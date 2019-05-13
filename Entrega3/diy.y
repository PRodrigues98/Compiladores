%{

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "types.h"
#include "LinkedList.h"


extern int yylex();
extern int yyerror(char *s);
extern int errors;

typedef struct functionInfo {
	int initialized;
	LinkedList *args;
} FunctionInfo;

int cycles = 0;

%}

%union {
	int i;			/* integer value */
	char *s;
	double d;
	Node *n;
};



%token<i> INT
%token<s> STRING ID
%token<d> NUM
%token INTEGER NUMBER STRING_TYPE
%token FOR IF THEN ELSE WHILE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE
%token GEQ LEQ DIF ASSIGN INC DEC
%token VOID PUBLIC CONST

%token ROOT DECL DECLS TYPE PARAMS PARAM PARAMTYPE FUNC INSTR INSTRS CORPO
%token IFELSE DOWNUP EXPR ALLOC LVALUE ARG ARGS RIGHTINC LEFTINC RIGHTDEC LEFTDEC CALL VAR
%token PRIVATE FUNCPROP TYPEID VARPROP ERROR NIL


%type<n> decls decl varinit vartype params corpo paramets instrs instr left_value expr args for_args
%type<n> cycle_instr cycle_control


%nonassoc THEN
%nonassoc ELSE

%right ASSIGN
%left '|'
%left '&'
%nonassoc '~'
%left '=' DIF
%left '<' '>' LEQ GEQ
%left '+' '-'
%left '*' '/' '%'
%left POINTER ADDRESS '!' SYMMETRIC INC DEC
%left '(' '['


%%


file : decls							{if(errors == 0) printNode(uniNode(ROOT, $1), 0, yynames);}
;

decls : decls decl						{$$ = binNode(DECLS, $1, $2);}
      | 								{$$ = nilNode(NIL);}
;

decl : PUBLIC CONST vartype ID varinit ';'		{$$ = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, $3, strNode(ID, $4)), $5)); checkDeclaration(setConst(($3->value).i), $5->info); IDnew(setConst(($3->value).i), $4, 0);}
	 | PUBLIC vartype ID varinit ';'			{$$ = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, $2, strNode(ID, $3)), $4)); checkDeclaration(($2->value).i, $4->info); IDnew(($2->value).i, $3, 0);}
	 | CONST vartype ID varinit ';'				{$$ = binNode(DECL, nilNode(PRIVATE), binNode(VAR, binNode(VARPROP, $2, strNode(ID, $3)), $4)); checkDeclaration(setConst(($2->value).i), $4->info); IDnew(setConst(($2->value).i), $3, 0);}
	 | vartype ID varinit ';'					{$$ = binNode(DECL, nilNode(PRIVATE), binNode(VAR, binNode(VARPROP, $1, strNode(ID, $2)), $3)); checkDeclaration(($1->value).i, $3->info); IDnew(($1->value).i, $2, 0);}

	 | PUBLIC CONST vartype ID ';'				{$$ = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, $3, strNode(ID, $4)), nilNode(NIL))); IDnew(($3->value).i, $4, 0);}
	 | PUBLIC vartype ID ';'					{$$ = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, $2, strNode(ID, $3)), nilNode(NIL))); IDnew(($2->value).i, $3, 0);}
	 | vartype ID ';'							{$$ = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, $1, strNode(ID, $2)), nilNode(NIL))); IDnew(($1->value).i, $2, 0);}


	 | PUBLIC vartype ID '(' params ')' '{' {checkFunction(setFunction($2->value.i), $3, (LinkedList*)$5->user, 1);} corpo '}' ';'		{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $2, strNode(ID, $3)), $5), $9)); IDpop();}
	 | PUBLIC vartype ID '(' ')' '{' {checkFunction(setFunction($2->value.i), $3, 0, 1);} corpo '}' ';'									{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $2, strNode(ID, $3)), nilNode(NIL)), $8)); IDpop();}
	 | vartype ID '(' params ')' '{' {checkFunction(setFunction($1->value.i), $2, (LinkedList*)$4->user, 1);} corpo '}' ';'				{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $1, strNode(ID, $2)), $4), $8)); IDpop();}
	 | vartype ID '(' ')' '{' {checkFunction(setFunction($1->value.i), $2, 0, 1);} corpo '}' ';'										{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $1, strNode(ID, $2)), nilNode(NIL)), $7)); IDpop();}

	 | PUBLIC VOID ID '(' params ')' '{' {checkFunction(setFunction(setVoid(0)), $3, (LinkedList*)$5->user, 1);} corpo '}' ';'		{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $3)), $5), $9)); IDpop();}
	 | PUBLIC VOID ID '(' ')' '{' {checkFunction(setFunction(setVoid(0)), $3, 0, 1);} corpo '}' ';'									{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $3)), nilNode(NIL)), $8)); IDpop();}
	 | VOID ID '(' params ')' '{' {checkFunction(setFunction(setVoid(0)), $2, (LinkedList*)$4->user, 1);} corpo '}' ';'				{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $2)), $4), $8)); IDpop();}
	 | VOID ID '(' ')' '{' {checkFunction(setFunction(setVoid(0)), $2, 0, 1);} corpo '}' ';'										{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $2)), nilNode(NIL)), $7)); IDpop();}

	 | PUBLIC vartype ID '(' params ')' ';'		{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $2, strNode(ID, $3)), $5), nilNode(NIL))); checkFunction(setFunction($2->value.i), $3, $5->user, 0);}
	 | PUBLIC vartype ID '(' ')' ';'			{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $2, strNode(ID, $3)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction($2->value.i), $3, 0, 0);}
	 | vartype ID '(' params ')' ';'			{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $1, strNode(ID, $2)), $4), nilNode(NIL))); checkFunction(setFunction($1->value.i), $2, $4->user, 0);}
	 | vartype ID '(' ')' ';'					{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, $1, strNode(ID, $2)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction($1->value.i), $2, 0, 0);}

	 | PUBLIC VOID ID '(' params ')' ';'		{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $3)), $5), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), $3, $5->user, 0);}
	 | PUBLIC VOID ID '(' ')' ';'				{$$ = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $3)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), $3, 0, 0);}
	 | VOID ID '(' params ')' ';'				{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $2)), $4), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), $2, $4->user, 0);}
	 | VOID ID '(' ')' ';'						{$$ = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, $2)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), $2, 0, 0);}
	 

	 | error ';'							{$$ = nilNode(ERROR);}
	 | error '}'							{$$ = nilNode(ERROR);}
;

vartype : INTEGER 							{$$ = intNode(TYPE, setInteger(0));}
	 	| INTEGER '*'						{$$ = intNode(TYPE, setPointer(setInteger(0)));}
	 	| NUMBER 							{$$ = intNode(TYPE, setNumber(0));}
	 	| NUMBER '*'						{$$ = intNode(TYPE, setPointer(setNumber(0)));}
	 	| STRING_TYPE 						{$$ = intNode(TYPE, setString(0));}
	 	| STRING_TYPE '*'					{$$ = intNode(TYPE, setPointer(setString(0)));}
;

varinit : ASSIGN INT 						{$$ = intNode(INT, $2); $$->info = setInteger(0); if($2 == 0) $$->info = setZero($$->info);}
		| ASSIGN CONST STRING 				{$$ = strNode(STRING, $3); $$->info = setRightConst(setString(0));}
		| ASSIGN STRING 					{$$ = strNode(STRING, $2); $$->info = setString(0);}
		| ASSIGN NUM 						{$$ = realNode(NUM, $2); $$->info = setNumber(0);}
		| ASSIGN ID 						{$$ = strNode(ID, $2); $$->info = IDfind($2, 0);}
		| ASSIGN '-' INT 					{$$ = intNode(INT, -1 * $3); $$->info = setInteger(0); if($3 == 0) $$->info = setZero($$->info);}
		| ASSIGN '-' NUM 					{$$ = realNode(NUM, -1 * $3); $$->info = setNumber(0);}
;

params : vartype ID 					{$$ = binNode(PARAM, nilNode(NIL), binNode(PARAMTYPE, $1, strNode(ID, $2))); $$->user = (void *)addElement($1->value.i, $2, 0);}
	   | params ',' vartype ID  		{$$ = binNode(PARAMS, $1, binNode(PARAMTYPE, $3, strNode(ID, $4))); $$->user = (void *)addElement($3->value.i, $4, (LinkedList *)$1->user);}
;

corpo : paramets instrs					{$$ = binNode(CORPO, $1, $2);}
	  | paramets						{$$ = binNode(CORPO, $1, nilNode(NIL));}
	  | instrs							{$$ = binNode(CORPO, nilNode(NIL), $1);}
	  |									{$$ = nilNode(NIL);}
;

paramets : paramets vartype ID ';'		{$$ = binNode(PARAMS, $1, binNode(PARAMTYPE, $2, strNode(ID, $3))); IDnew(($2->value).i, $3, 0);}
		 | vartype ID ';'				{$$ = uniNode(PARAM, binNode(PARAMTYPE, $1, strNode(ID, $2))); IDnew(($1->value).i, $2, 0);}
;

instrs : instrs instr 					{$$ = binNode(INSTRS, $1, $2);}
	   | instr 							{$$ = uniNode(INSTR, $1);}
;

instr : IF expr THEN cycle_instr 										{$$ = binNode(IF, $2, $4); if(!isInteger($2->info) || isPointer($2->info)) yyerror("Invalid argument for if");}
	  | IF expr THEN cycle_instr ELSE cycle_instr 						{$$ = binNode(IFELSE, binNode(IF, $2, $4), $6); if(!isInteger($2->info) || isPointer($2->info)) yyerror("Invalid argument for if");}
	  | DO {cycles++;} cycle_instr WHILE expr ';'						{$$ = binNode(WHILE, $3, $5); cycles--; if(!isInteger($5->info) || isPointer($5->info)) yyerror("Invalid argument for while");}
	  | FOR left_value IN expr for_args DO {cycles++;} cycle_instr		{$$ = binNode(FOR, $2, binNode(PARAMS, $4, binNode(INSTRS, $5, $8))); cycles--; checkAssign($2->info, $4->info);}
	  | expr ';' 														{$$ = $1;}
	  | '{' push_subroutine corpo '}'									{$$ = $3; IDpop();}
	  | '{' push_subroutine corpo cycle_control '}' 					{$$ = binNode(CORPO, $3, $4); IDpop();}
	  | left_value '#' expr ';'											{$$ = binNode(ALLOC, $1, $3); if(!isInteger($3->info) || isPointer($3->info)) yyerror("Invalid argument for function");}

	  | error ';'														{$$ = nilNode(ERROR);}
	  | error '}'														{$$ = nilNode(ERROR);}
;

cycle_control : BREAK ';' 			{$$ = intNode(BREAK, 1); if(cycles < 1) yyerror("Not enough nested cycles for break instruction");}
			  | BREAK INT ';'		{$$ = intNode(BREAK, $2); if(cycles < $2) yyerror("Not enough nested cycles for break instruction argument");}
			  | CONTINUE ';'		{$$ = intNode(CONTINUE, 1); if(cycles < 1) yyerror("Not enough nested cycles for continue instruction");}
			  | CONTINUE INT ';'	{$$ = intNode(CONTINUE, $2); if(cycles < $2) yyerror("Not enough nested cycles for continue instruction argument");}
;

push_subroutine : {IDpush();}
;

cycle_instr : instr 				{$$ = $1;}
			| cycle_control 		{$$ = $1;}
;

for_args : UPTO expr 					{$$ = binNode(DOWNUP, nilNode(UPTO), uniNode(STEP, intNode(INT, 1))); if(!isInteger($2->info) || isPointer($2->info)) yyerror("Invalid for arguments");}
		 | UPTO expr STEP expr 			{$$ = binNode(DOWNUP, nilNode(UPTO), uniNode(STEP, $4)); if(!isInteger($2->info) || isPointer($2->info) || !isInteger($4->info) || isPointer($4->info)) yyerror("Invalid for arguments");}
		 | DOWNTO expr 					{$$ = binNode(DOWNUP, nilNode(DOWNTO), uniNode(STEP, intNode(INT, 1))); if(!isInteger($2->info) || isPointer($2->info)) yyerror("Invalid for arguments");}
		 | DOWNTO expr STEP expr 		{$$ = binNode(DOWNUP, nilNode(DOWNTO), uniNode(STEP, $4)); if(!isInteger($2->info) || isPointer($2->info) || !isInteger($4->info) || isPointer($4->info)) yyerror("Invalid for arguments");}
;

left_value : ID 							{$$ = strNode(ID, $1); $$->info = IDfind($1, 0);}
		   | ID '[' expr ']'				{$$ = binNode(LVALUE, strNode(ID, $1), $3); if(!isInteger($3->info)) yyerror("Invalid address"); $$->info = checkPointer(IDfind($1, 0));}
;

expr : left_value							{$$ = $1;}
	 | INT 									{$$ = intNode(INT, $1); $$->info = setInteger(0); if($1 == 0) $$->info = setZero($$->info);}
	 | NUM 									{$$ = realNode(NUM, $1); $$->info = setNumber(0);}
	 | STRING 								{$$ = strNode(STRING, $1); $$->info = setString(0);}
	 | CONST STRING 						{$$ = strNode(STRING, $2); $$->info = setRightConst(setString(0));}
	 | '(' expr ')'							{$$ = $2; $$->info = $2->info;}
	 | ID '(' args ')'						{$$ = binNode(CALL, strNode(ID, $1), $3); $$->info = checkFunction(-1, $1, (LinkedList *)$3->user, 2);}
	 | ID '(' ')'							{$$ = binNode(CALL, strNode(ID, $1), nilNode(NIL)); $$->info = checkFunction(-1, $1, 0, 2);}
	 | '&' left_value %prec ADDRESS			{$$ = uniNode(ADDRESS, $2); $$->info = checkLocation($2->info);}
	 | '*' expr %prec POINTER				{$$ = uniNode(POINTER, $2); $$->info = checkPointer($2->info);}
	 | '-' expr %prec SYMMETRIC				{$$ = uniNode(SYMMETRIC, $2); $$->info = $2->info;}
	 | expr '!'								{$$ = uniNode('!', $1); if(!isInteger($1->info) || isPointer($1->info)) yyerror("Invalid argument for factorial"); $$->info = setNumber(0);}
	 | INC left_value						{$$ = uniNode(RIGHTINC, $2); if(!isInteger($2->info) || isPointer($2->info)) yyerror("Invalid argument for increment"); $$->info = setInteger(0);}
	 | left_value INC 						{$$ = uniNode(LEFTINC, $1); if(!isInteger($1->info) || isPointer($1->info)) yyerror("Invalid argument for increment"); $$->info = setInteger(0);}
	 | DEC left_value						{$$ = uniNode(LEFTDEC, $2); if(!isInteger($2->info) || isPointer($2->info)) yyerror("Invalid argument for decrement"); $$->info = setInteger(0);}
	 | left_value DEC 						{$$ = uniNode(RIGHTDEC, $1); if(!isInteger($1->info) || isPointer($1->info)) yyerror("Invalid argument for decrement"); $$->info = setInteger(0);}
	 | expr '*' expr 						{$$ = binNode('*', $1, $3); $$->info = checkOperation($1->info, $3->info);}
	 | expr '/' expr 						{$$ = binNode('/', $1, $3); $$->info = checkOperation($1->info, $3->info);}
	 | expr '%' expr 						{$$ = binNode('%', $1, $3); $$->info = checkOperation($1->info, $3->info);}
	 | expr '+' expr 						{$$ = binNode('+', $1, $3); $$->info = checkOperation($1->info, $3->info);}
	 | expr '-' expr 						{$$ = binNode('-', $1, $3); $$->info = checkOperation($1->info, $3->info);}
	 | expr '<' expr 						{$$ = binNode('<', $1, $3); checkComparison($1->info, $3->info); $$->info = setInteger(0);}
	 | expr '>' expr 						{$$ = binNode('>', $1, $3); checkComparison($1->info, $3->info); $$->info = setInteger(0);}
	 | expr LEQ expr 						{$$ = binNode(LEQ, $1, $3); checkComparison($1->info, $3->info); $$->info = setInteger(0);}
	 | expr GEQ expr 						{$$ = binNode(GEQ, $1, $3); checkComparison($1->info, $3->info); $$->info = setInteger(0);}
	 | expr DIF expr 						{$$ = binNode(DIF, $1, $3); checkComparison($1->info, $3->info); $$->info = setInteger(0);}
	 | expr '=' expr 						{$$ = binNode('=', $1, $3); checkComparison($1->info, $3->info); $$->info = setInteger(0);}
	 | '~' expr 							{$$ = uniNode('~', $2); if(!isInteger($2->info) || !(isPointer($2->info))) yyerror("Invalid argument for negation"); $$->info = setInteger(0);}
	 | expr '&' expr 						{$$ = binNode('&', $1, $3); if(!isInteger($1->info) || isPointer($1->info) || !isInteger($3->info) || isPointer($3->info)) yyerror("Invalid arguments for logical AND"); $$->info = setInteger(0);}
	 | expr '|' expr 						{$$ = binNode('|', $1, $3); if(!isInteger($1->info) || isPointer($1->info) || !isInteger($3->info) || isPointer($3->info)) yyerror("Invalid arguments for logical OR"); $$->info = setInteger(0);}
	 | left_value ASSIGN expr 				{$$ = binNode(ASSIGN, $1, $3); $$->info = checkAssign($1->info, $3->info); if(((isPointer($1->info) || isString($1->info)) && (isPointer($3->info) || isString($3->info))) && (isRightConst($1->info) != isRightConst($3->info))) IDreplace($3->info, $1->value.s, 0);}
;

args : args ',' expr 						{$$ = binNode(ARGS, $1, $3); $$->user = (void *)addElement($3->info, 0, $1->user);}
	 | expr 								{$$ = $1; $$->user = (void *)addElement($1->info, 0, 0);}
;

%%

int checkPointer(int a){

	if(isFunc(a)){
		yyerror("Invalid argument for value of operator");
		return cleanFunction(cleanPointer(a));
	}

	if((isPointer(a) || isString(a)) && isRightConst(a)){
		return setConst(cleanRightConst(cleanPointer(a)));
	}

	if(isPointer(a) && !isRightConst(a)){
		return cleanConst(cleanPointer(a));
	}
	else if(isString(a)){
		if(isRightConst(a)){
			return setConst(setInteger(0));
		}
		return setInteger(0);
	}

	yyerror("Invalid argument for value of operator");

	return cleanConst(cleanPointer(a));
}

int checkOperation(int a, int b){
	if(!isIntegerOrNum(a) || !isIntegerOrNum(b) || isPointer(a) || isPointer(b)){
		yyerror("Invalid argument for operator");
		return setInteger(0);
	}

	if(isNumber(a) || isNumber(b)){
		return setNumber(0);
	}
	else{
		return setInteger(0);
	}

	return setInteger(0);
}

int checkLocation(int a){
	if(isPointer(a)){
		yyerror("Cant apply location to pointer");
	}
	else if(isFunc(a)){
		yyerror("Cant apply location to function");
	}

	if(isConst(a)){
		return setRightConst(cleanConst(setPointer(a)));
	}

	return setPointer(a);
}

void checkDeclaration(int a, int b){

	if(isFunc(a) || isFunc(b)){
		yyerror("Illegal assignment");
		return;
	}

	if( ( getType(a) == getType(b) && isPointer(a) == isPointer(b)										   ) || 
	    ( isZero(b) 			   										   								   ) ||
	    ( (isInteger(a) && isPointer(a) && isString(b)) || (isInteger(b) && isPointer(b) && isString(a))   ) ){

		return;
	}

	yyerror("Illegal assignment");
}

int checkAssign(int a, int b){

	if(isFunc(a) || isFunc(b)){
		yyerror("Illegal assignment");
		return cleanFunction(b);
	}

	if(isConst(a)){
		yyerror("Cannot assign to constant variable");
		return a;
	}

	if(!isPointer(a) && !isPointer(b) && isIntegerOrNum(a) == isIntegerOrNum(b) && isIntegerOrNum(a)){
		return a;
	}

	int errorsBefore = errors;

	checkDeclaration(a, b);

	if(errors == errorsBefore){
		return a;
	}

	yyerror("Illegal assignment");

	return b;
}

void checkComparison(int a, int b){

	if(isZero(a) || isZero(b)){
		return;
	}

	if(!isPointer(a) && !isPointer(b) && isIntegerOrNum(a) == isIntegerOrNum(b)){
		return;
	}

	yyerror("Invalid arguments for comparison");
}

void pushArg(LinkedList *l){

	IDnew(l->type, l->id, 0);
}

int checkFunction(int type, char *id, LinkedList *l, int init){
	int declType = IDsearch(id, (long *)IDtest, IDlevel(), 0);
	FunctionInfo *info = 0;
	long aux;

	if(init == 2 && declType == -1){
		yyerror("Call to function that was not declared");

		return setInteger(0);
	}
	else if(init == 2 && declType != -1){

		if(!isFunc(declType)){
			yyerror("ID is not a function");

			return declType;
		}

		declType = IDsearch(id, &aux, IDlevel(), 0);

		info = (FunctionInfo *)aux;

		if(info == NULL){
			yyerror("Function information was not initialized");

			return cleanFunction(declType);
		}

		if(!compareLists(info->args, l)){
			yyerror("Incompatible arguments for function");
		}

		return cleanFunction(declType);
	}

	if(declType == -1){
		info = (FunctionInfo *)malloc(sizeof(FunctionInfo));

		info->initialized = 0;

		info->args = l;

		IDnew(type, id, (long)info);
	}
	else{

		declType = IDsearch(id, (long *)&aux, IDlevel(), 0);

		info = (FunctionInfo *)aux;

		if(declType != type){
			yyerror("Incompatible function returns");

			IDreplace(type, id, aux);

			return cleanFunction(type);
		}
		else if(!compareLists(info->args, l)){
			yyerror("Incompatible declared function arguments");

			IDreplace(type, id, aux);

			return cleanFunction(type);
		}
	}

	if(init == 1){
		if(info->initialized == 1){
			yyerror("Initialized a function twice");
		}

		IDpush();

		IDnew(cleanFunction(type), id, 0);

		forEachElement(l, pushArg);

		info->initialized = 1;

		return cleanFunction(type);
	}
}


char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

