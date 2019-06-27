%{
/* $Id: diy.y,v 1.0 2019/02/06 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"


extern int yylex();
extern void enterFunction(int pub, char *name, int enter, int retPos, Node *type, Node *stmt);
extern char *dupstr(const char *s);
extern char *mkfunc(char *s);
extern void variable(int pub, int cnst, char *name, Node *type, Node *init);
extern void externs();

extern char *extrns[100]; /* emit externs at the end only */
extern int extcnt;

char *labels[100]; /* confirm labels at the end */
int lblcnt = 0;


void yyerror(char *s);
void declare(int pub, int cnst, Node *type, char *name, Node *value);
void enter(int pub, int typ, char *name);
int checkargs(char *name, Node *args);
int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);
void function(int pub, Node *type, char *name, Node *body);
void addExtern(char *name);

static int ncicl;
static char *fpar;

int argPos;
int pos;

%}

%union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
};

%token <i> INT
%token <r> REAL
%token <s> ID STR
%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE GOTO LABEL
%token VOID INTEGER STRING NUMBER CONST PUBLIC INCR DECR DECLS
%nonassoc IFX
%nonassoc ELSE

%right ATR
%left '|'
%left '&'
%nonassoc '~'
%right XOR
%left '=' NE
%left GE LE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS '!' NOT REF
%nonassoc '[' '('

%type <n> tipo init finit blocop params
%type <n> bloco param base stmt step args list end brk lv expr
%type <i> ptr intp public

%token LOCAL POSINC POSDEC PTR CALL START PARAM NIL

%%

completeFile : file 	{ externs(); }
			 ;

file	:
		| file error ';'
		| file public tipo ID ';'										{ IDnew($3->value.i, $4, 0); if($2) addExtern($4); else declare($2, 0, $3, $4, 0); }
		| file public CONST tipo ID ';'									{ IDnew($4->value.i+5, $5, 0); if($2) addExtern($5); else declare($2, 1, $4, $5, 0); }
		| file public tipo ID init										{ IDnew($3->value.i, $4, 0); declare($2, 0, $3, $4, $5); }
		| file public CONST tipo ID init								{ IDnew($4->value.i+5, $5, 0); declare($2, 1, $4, $5, $6); }
		| file public tipo ID { enter($2, $3->value.i, $4); } finit 	{ function($2, $3, $4, $6); }
		| file public VOID ID { enter($2, 4, $4); } finit				{ function($2, intNode(VOID, 4), $4, $6); }
		;

public	:           { $$ = 0; }
		| PUBLIC    { $$ = 1; }
		;

ptr	:               { $$ = 0; }
	| '*'           { $$ = 10; }
	;

tipo : INTEGER ptr		{ $$ = intNode(INTEGER, 1+$2); }
	 | STRING ptr		{ $$ = intNode(STRING, 2+$2); }
	 | NUMBER ptr		{ $$ = intNode(NUMBER, 3+$2); }
	 ;

init : ATR ID ';'			{ $$ = strNode(ID, $2); $$->info = IDfind($2, 0) + 10; }
	 | ATR INT ';'			{ $$ = intNode(INT, $2); $$->info = 1; }
	 | ATR '-' INT ';'		{ $$ = intNode(INT, -$3); $$->info = 1; }
	 | ATR STR ';'			{ $$ = strNode(STR, $2); $$->info = 2; }
	 | ATR CONST STR ';'	{ $$ = strNode(CONST, $3); $$->info = 2+5; }
	 | ATR REAL ';'			{ $$ = realNode(REAL, $2); $$->info = 3; }
	 | ATR '-' REAL ';'		{ $$ = realNode(REAL, -$3); $$->info = 3; }
	 ;

finit : '(' params ')' blocop 	{ $$ = binNode('(', $4, $2); }
	  | '(' ')' blocop        	{ Node *n = nilNode(NIL); n->info = 0; $$ = binNode('(', $3, n); }
	  ;

blocop : ';'   	  	 { $$ = nilNode(NIL); }
       | bloco ';'   { $$ = $1; }
       ;

params : param
	   | params ',' param      { $$ = binNode(',', $1, $3); }
	   ;

bloco : '{' { IDpush(); } decls list end '}'    { $$ = uniNode('{', $5 ? binNode(';', $4, $5) : $4); IDpop(); }
	  ;

decls :
	  | decls param ';'
	  ;

param : tipo ID 	{ 
						long actualPos;

						$$ = binNode(PARAM, $1, strNode(ID, $2));

						if(IDlevel() == 1){
                    		fpar[++fpar[0]] = $1->value.i;

                    		actualPos = argPos;

                    		argPos += ($1->value.i == 3) ? 8 : 4;
                    	}
                    	else{
                    		pos -= ($1->value.i == 3) ? 8 : 4;
                    		actualPos = pos;
                    	}

                    	IDnew($1->value.i, $2, actualPos);
                    }
	 ;

stmt : base
	 | brk
	 ;

base : ';'                   									{ $$ = nilNode(VOID); }
	 | DO { ncicl++; } stmt WHILE expr ';'						{ $$ = binNode(WHILE, binNode(DO, nilNode(START), $3), $5); ncicl--; }
	 | FOR lv IN expr UPTO expr step DO { ncicl++; } stmt		{ 
	 																Node *p1 = uniNode(PTR, $2);
	 																p1->info = $2->info;

	 																Node *p2 = uniNode(PTR, $2);
	 																p2->info = $2->info;

	 																Node *a1 = binNode(ATR, $4, $2);
	 																a1->info = $2->info;

	 																Node *a2 = binNode(ATR, binNode('+', p2, $7), $2);
	 																a2->info = $2->info;

	 																$$ = binNode(';', a1, binNode(FOR, binNode(IN, nilNode(START), binNode(LE, p1, $6)), binNode(';', $10, a2))); 

	 																ncicl--; 
	 															}
	 | FOR lv IN expr DOWNTO expr step DO { ncicl++; } stmt		{ 

	 																Node *p1 = uniNode(PTR, $2);
	 																p1->info = $2->info;

	 																Node *p2 = uniNode(PTR, $2);
	 																p2->info = $2->info;

	 																Node *a1 = binNode(ATR, $4, $2);
	 																a1->info = $2->info;

	 																Node *a2 = binNode(ATR, binNode('-', p2, $7), $2);
	 																a2->info = $2->info;

	 																$$ = binNode(';', a1, binNode(FOR, binNode(IN, nilNode(START), binNode(GE, p1, $6)), binNode(';', $10, a2))); 

	 																ncicl--; 
	 															}
	 | IF expr THEN stmt %prec IFX    							{ $$ = binNode(IF, $2, $4); }
	 | IF expr THEN stmt ELSE stmt    							{ $$ = binNode(ELSE, binNode(IF, $2, $4), $6); }
	 | expr ';'        	{ $$ = $1; }
	 | bloco           	{ $$ = $1; }
	 | lv '#' expr ';' 	{ $$ = binNode('#', $3, $1); }
	 | ID LABEL 		{ $$ = strNode(LABEL, $1); }
	 | GOTO ID ';'		{ $$ = strNode(GOTO, $2); }
	 | error ';'       	{ $$ = nilNode(NIL); }
	 ;

end	:		{ $$ = 0; }
	| brk
	;

brk : BREAK intp ';'        { $$ = intNode(BREAK, $2); if ($2 <= 0 || $2 > ncicl) yyerror("invalid break argument"); }
	| CONTINUE intp ';'     { $$ = intNode(CONTINUE, $2); if ($2 <= 0 || $2 > ncicl) yyerror("invalid continue argument"); }
	;

step :               { $$ = intNode(INT, 1); }
	 | STEP expr     { $$ = $2; }
	 ;

intp :       { $$ = 1; }
	 | INT
	 ;

list : base
	 | list base     { $$ = binNode(';', $1, $2); }
	 ;

args : expr				{ $$ = binNode(',', $1, nilNode(NIL)); $$->info = ($1->info % 5 == 3) ? 8 : 4; }
	 | args ',' expr 	{ $$ = binNode(',', $3, $1); $$->info = $1->info + (($3->info % 5 == 3) ? 8 : 4); }
	 ;

lv : ID	 	{ 
				long pos; 
				int typ = IDfind($1, &pos);

            	if(pos == 0){
            		$$ = strNode(ID, $1);
            	}
            	else{
            		$$ = intNode(LOCAL, pos);
            	}

				$$->info = typ;
			}
   | ID '[' expr ']'	{ 
							Node *n;
                            long pos; 
                            int typ = IDfind($1, &pos);

                            if(typ / 10 != 1 && typ % 5 != 2){
                            	yyerror("not a pointer");
                            }

                            if(pos == 0){
                            	n = strNode(ID, $1);
                            }
                            else{
                            	n = intNode(LOCAL, pos);
                            }

                            $$ = binNode('[', uniNode(PTR, n), $3);

                            LEFT_CHILD($$)->info = typ;

			    			if(typ >= 10) typ -= 10;
                            else if(typ % 5 == 2) typ = 1;

			    			if(typ >= 5) typ -= 5;

			    			$$->info = typ;
						}
	;

expr : lv						{ $$ = uniNode(PTR, $1); $$->info = $1->info; }
	 | '*' lv        			{ $$ = uniNode(PTR, uniNode(PTR, $2)); LEFT_CHILD($$)->info = $2->info; if ($2->info / 10 == 1) $$->info = $2->info % 10; else if ($2->info % 5 == 2) $$->info = 1; else yyerror("can dereference lvalue"); }
	 | lv ATR expr   			{ $$ = binNode(ATR, $3, $1); if ($$->info % 10 > 5) yyerror("constant value to assignment"); if (noassign($1, $3)) yyerror("illegal assignment"); $$->info = $1->info; }
	 | INT          			{ $$ = intNode(INT, $1); $$->info = 1; }
	 | STR           			{ $$ = strNode(STR, $1); $$->info = 2; }
	 | REAL          			{ $$ = realNode(REAL, $1); $$->info = 3; }
	 | '-' expr %prec UMINUS	{ $$ = uniNode(UMINUS, $2); $$->info = $2->info; nostring($2, $2);}
	 | '~' expr %prec UMINUS 	{ $$ = uniNode(NOT, $2); $$->info = intonly($2, 0); }
	 | '&' lv %prec UMINUS   	{ $$ = uniNode(REF, $2); $$->info = $2->info + 10; }
	 | expr '!'             	{ $$ = uniNode('!', $1); $$->info = 3; intonly($1, 0); addExtern("_factorial"); }
	 | INCR lv       			{ $$ = uniNode(INCR, $2); $$->info = intonly($2, 1); }
	 | DECR lv       			{ $$ = uniNode(DECR, $2); $$->info = intonly($2, 1); }
	 | lv INCR       			{ $$ = uniNode(POSINC, $1); $$->info = intonly($1, 1); }
	 | lv DECR       			{ $$ = uniNode(POSDEC, $1); $$->info = intonly($1, 1); }
	 | expr '+' expr 			{ $$ = binNode('+', $1, $3); $$->info = nostring($1, $3); }
	 | expr '-' expr 			{ $$ = binNode('-', $1, $3); $$->info = nostring($1, $3); }
	 | expr '*' expr 			{ $$ = binNode('*', $1, $3); $$->info = nostring($1, $3); }
	 | expr '/' expr 			{ $$ = binNode('/', $1, $3); $$->info = nostring($1, $3); }
	 | expr '%' expr 			{ $$ = binNode('%', $1, $3); $$->info = intonly($1, 0); intonly($3, 0); }
	 | expr '<' expr 			{ $$ = binNode('<', $1, $3); $$->info = 1; if($1->info == $3->info && $1->info == 2) addExtern("_strcmp");}
	 | expr '>' expr 			{ $$ = binNode('>', $1, $3); $$->info = 1; if($1->info == $3->info && $1->info == 2) addExtern("_strcmp");}
	 | expr GE expr  			{ $$ = binNode(GE, $1, $3); $$->info = 1; if($1->info == $3->info && $1->info == 2) addExtern("_strcmp");}
	 | expr LE expr  			{ $$ = binNode(LE, $1, $3); $$->info = 1; if($1->info == $3->info && $1->info == 2) addExtern("_strcmp");}
	 | expr NE expr  			{ $$ = binNode(NE, $1, $3); $$->info = 1; if($1->info == $3->info && $1->info == 2) addExtern("_strcmp");}
	 | expr '=' expr 			{ $$ = binNode('=', $1, $3); $$->info = 1; if($1->info == $3->info && $1->info == 2) addExtern("_strcmp");}
	 | expr '&' expr 			{ $$ = binNode('&', $1, $3); $$->info = intonly($1, 0); intonly($3, 0); }
	 | expr '|' expr 			{ $$ = binNode('|', $1, $3); $$->info = intonly($1, 0); intonly($3, 0); }
	 | expr XOR expr 			{ $$ = binNode(XOR, $1, $3); $$->info = intonly($1, 0); intonly($3, 0); }
	 | '(' expr ')' 			{ $$ = $2; $$->info = $2->info; }
	 | ID '(' args ')' 			{ $$ = binNode(CALL, strNode(ID, $1), $3); $$->info = checkargs($1, $3); }
	 | ID '(' ')'    			{ $$ = binNode(CALL, strNode(ID, $1), intNode(VOID, 0)); $$->info = checkargs($1, 0); }
	 ;

%%

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

void declare(int pub, int cnst, Node *type, char *name, Node *value){
	int typ;

	if(!value){
    	if(!pub && cnst){
    		yyerror("local constants must be initialised");
    	}

		variable(pub, cnst, name, type, value);

    	return;
	}

	if (value->attrib == INT && value->value.i == 0 && (type->value.i > 10 || type->value.i == 2)){

		variable(pub, cnst, name, type, value);

  		return; /* NULL pointer and NULL string */
	}

	if((typ = value->info) % 10 > 5){
		typ -= 5;
	}

	if(typ == 11 && type->value.i % 10 == 3){
		variable(pub, cnst, name, type, value);

		return;
	}

	if (type->value.i != typ){
		yyerror("wrong types in initialization");
	}

	variable(pub, cnst, name, type, value);
}

void enter(int pub, int typ, char *name) {

	fpar = malloc(32); /* 31 arguments, at most */

	fpar[0] = 0; /* argument count*/

	if(IDfind(name, (long*)IDtest) < 20){
		IDnew(typ + 20, name, (long)fpar);
	}

	IDpush();

	argPos = 8;
	pos = 0;

	/* if the return type isn't void */
	if (typ != 4){

		pos -= (typ == 3) ? 8 : 4;

		IDnew(typ, name, pos);
	}
}

int checkargs(char *name, Node *args) {
	char *arg;

	int typ;

    if ((typ = IDsearch(name, (long*)&arg, IDlevel(), 1)) < 20) {
		yyerror("ident not a function");
		return 0;
	}

	if (args == 0 && arg[0] == 0){
		;
	}
	else if (args == 0 && arg[0] != 0){
		yyerror("function requires no arguments");
	}
	else if (args != 0 && arg[0] == 0){
		yyerror("function requires arguments");
	}
	else {
		int err = 0, null, i = arg[0], typ;

		do {
			Node *n;

			if (i == 0) {
				yyerror("too many arguments.");
				err = 1;
				break;
			}

			n = LEFT_CHILD(args);

			typ = n->info;

			if (typ % 10 > 5) typ -= 5; /* remove CONST */

			null =  (n->attrib == INT && n->value.i == 0 && arg[i] > 10) ? 1 : 0;

			if (!null && arg[i] != typ) {
				yyerror("wrong argument type");
				err = 1;
				break;
			}

			args = RIGHT_CHILD(args);
			i--;

		} while (args->attrib != NIL);

		if (!err && i > 0){
			yyerror("missing arguments");
		}
	}

	return typ % 20;
}

int nostring(Node *arg1, Node *arg2) {
	if(arg1->info % 5 == 2 || arg2->info % 5 == 2){
		yyerror("can not use strings");
	}

	return (arg1->info % 5 == 3 || arg2->info % 5 == 3) ? 3 : 1;
}

int intonly(Node *arg, int novar) {

	if(arg->info % 5 != 1){
		yyerror("only integers can be used");
	}

	if(arg->info % 10 > 5){
		yyerror("argument is constant");
	}

	return 1;
}

int noassign(Node *arg1, Node *arg2) {
	int t1 = arg1->info, t2 = arg2->info;

	if(t1 == t2) return 0;
	if(t1 == 3 && t2 == 1) return 0; /* real := int */
	if(t1 == 1 && t2 == 3) return 0; /* int := real */
	if(t1 == 2 && t2 == 11) return 0; /* string := int* */
	if(t1 == 2 && arg2->attrib == INT && arg2->value.i == 0) return 0; /* string := 0 */
	if(t1 > 10 && t1 < 20 && arg2->attrib == INT && arg2->value.i == 0) return 0; /* pointer := 0 */

	return 1;
}

void function(int pub, Node *type, char *name, Node *body){
	Node *bloco = LEFT_CHILD(body);

	long retPos;

	IDfind(name, &retPos);

	IDpop();

	long par;
	int fwd = IDfind(name, &par);

	if (bloco->attrib != NIL){ /* not a forward declaration */

		if (fwd > 40){
			yyerror("duplicate function");
		} 
		else {
			IDreplace(fwd + 40, name, par);

			enterFunction(pub, name, -pos, (int)retPos, type, bloco);
		}
	}
	else if(fwd <= 40 && pub){

		addExtern(mkfunc(name));
	}
}

void addExtern(char *name){

	int i;

	for (i = 0; i < extcnt; i++){
		if (extrns[i] && strcmp(extrns[i], name) == 0){
			return;
		}
	}

	extrns[extcnt++] = name;
}
