%{

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"

extern int yylex();
int yyerror(char *s);

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

%token ROOT DECL DECLS TYPE EMPTYINIT PARAMS PARAM IDTYPE PARAMTYPE FUNC INSTR INSTRS CORPO EMPTYCORPO
%token IFELSE DOWNUP EXPR ALLOC LVALUE NOARGS ARG ARGS RIGHTINC LEFTINC RIGHTDEC LEFTDEC CALL


%type<n> decls decl init type params param corpo paramets instrs instr left_value expr args


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


file : decls							{printNode(uniNode(ROOT, $1), 0, yynames);}
;

decls : decls decl						{$$ = binNode(DECLS, $1, $2);}
      | 								{$$ = nilNode(DECLS);}
;

decl : PUBLIC CONST type ID init ';'	{$$ = binNode(DECL, binNode(IDTYPE, $3, strNode(ID, $4)), $5);}
	 | PUBLIC type ID init ';'			{$$ = binNode(DECL, binNode(IDTYPE, $2, strNode(ID, $3)), $4);}
	 | CONST type ID init ';'			{$$ = binNode(DECL, binNode(IDTYPE, $2, strNode(ID, $3)), $4);}
	 | type ID init ';'					{$$ = binNode(DECL, binNode(IDTYPE, $1, strNode(ID, $2)), $3);}
;

type : INTEGER 							{$$ = nilNode(TYPE);}
	 | INTEGER '*'						{$$ = nilNode(TYPE);}
	 | NUMBER 							{$$ = nilNode(TYPE);}
	 | NUMBER '*'						{$$ = nilNode(TYPE);}
	 | STRING_TYPE 						{$$ = nilNode(TYPE);}
	 | STRING_TYPE '*'					{$$ = nilNode(TYPE);}
	 | VOID								{$$ = nilNode(TYPE);}
	 | VOID '*'							{$$ = nilNode(TYPE);}
;

init : ASSIGN INT 						{$$ = intNode(INT, $2);}
	 | ASSIGN CONST STRING 				{$$ = strNode(STRING, $3);}
	 | ASSIGN STRING 					{$$ = strNode(STRING, $2);}
	 | ASSIGN NUM 						{$$ = realNode(NUMBER, $2);}
	 | ASSIGN ID 						{$$ = strNode(ID, $2);}
	 | '(' params ')' '{' corpo	'}'		{$$ = binNode(FUNC, $2, $5);}
	 | '(' params ')' 					{$$ = uniNode(PARAMS, $2);}
	 | '(' ')'							{$$ = nilNode(PARAMS);}
	 | '(' ')' '{' corpo '}'			{$$ = binNode(FUNC, nilNode(PARAMS), $4);}
	 |									{$$ = nilNode(EMPTYINIT);}
;

params : param							{$$ = uniNode(PARAM, $1);}
	   | params ',' param 				{$$ = binNode(PARAMS, $1, $3);}
;

param : type ID 						{$$ = binNode(PARAMTYPE, $1, strNode(ID, $2));}
;

corpo : paramets instrs					{$$ = binNode(CORPO, $1, $2);}
	  | paramets						{$$ = uniNode(CORPO, $1);}
	  | instrs							{$$ = uniNode(CORPO, $1);}
	  |									{$$ = nilNode(EMPTYCORPO);}
;

paramets : paramets param ';'			{$$ = binNode(PARAMS, $1, $2);}
		 | param ';'					{$$ = uniNode(PARAM, $1);}
;

instrs : instrs instr 					{$$ = binNode(INSTRS, $1, $2);}
	   | instr 							{$$ = uniNode(INSTR, $1);}
;

instr : IF expr THEN instr 										{$$ = binNode(IF, $2, $4);}
	  | IF expr THEN instr ELSE instr 							{$$ = binNode(IFELSE, binNode(IF, $2, $4), $6);}
	  | DO instr WHILE expr ';'									{$$ = binNode(WHILE, $2, $4);}
	  | FOR left_value IN expr UPTO expr DO instr 				{$$ = binNode(FOR, $2, binNode(PARAMS, $4, binNode(INSTRS, binNode(DOWNUP, nilNode(UPTO), uniNode(STEP, intNode(INT, 1))), $8)));}
	  | FOR left_value IN expr UPTO expr STEP expr DO instr 	{$$ = binNode(FOR, $2, binNode(PARAMS, $4, binNode(INSTRS, binNode(DOWNUP, nilNode(UPTO), uniNode(STEP, $8)), $10)));}
	  | FOR left_value IN expr DOWNTO expr DO instr 			{$$ = binNode(FOR, $2, binNode(PARAMS, $4, binNode(INSTRS, binNode(DOWNUP, nilNode(DOWNTO), uniNode(STEP, intNode(INT, 1))), $8)));}
	  | FOR left_value IN expr DOWNTO expr STEP expr DO instr 	{$$ = binNode(FOR, $2, binNode(PARAMS, $4, binNode(INSTRS, binNode(DOWNUP, nilNode(DOWNTO), uniNode(STEP, $8)), $10)));}
	  | expr ';' 												{$$ = $1;}
	  | '{' corpo '}'											{$$ = $2;}
	  | BREAK INT ';'											{$$ = intNode(BREAK, $2);}
	  | BREAK ';'												{$$ = intNode(BREAK, 1);}
	  | CONTINUE INT ';'										{$$ = intNode(CONTINUE, $2);}
	  | CONTINUE ';'											{$$ = intNode(CONTINUE, 1);}
	  | left_value '#' expr ';'									{$$ = binNode(ALLOC, $1, $3);}
;

left_value : ID 							{$$ = strNode(ID, $1);}
		   | ID '[' expr ']'				{$$ = binNode(LVALUE, strNode(ID, $1), $3);}
;

expr : left_value							{$$ = $1;}
	 | INT 									{$$ = intNode(INT, $1);}
	 | NUM 									{$$ = realNode(NUM, $1);}
	 | STRING 								{$$ = strNode(STRING, $1);}
	 | '(' expr ')'							{$$ = $2;}
	 | ID '(' args ')'						{$$ = binNode(CALL, strNode(ID, $1), $3);}
	 | ID '(' ')'							{$$ = binNode(CALL, strNode(ID, $1), nilNode(NOARGS));}
	 | '&' left_value %prec ADDRESS			{$$ = uniNode(ADDRESS, $2);}
	 | '*' expr %prec POINTER				{$$ = uniNode(POINTER, $2);}
	 | '-' expr %prec SYMMETRIC				{$$ = uniNode(SYMMETRIC, $2);}
	 | expr '!'								{$$ = uniNode('!', $1);}
	 | INC left_value						{$$ = uniNode(RIGHTINC, $2);}
	 | left_value INC 						{$$ = uniNode(LEFTINC, $1);}
	 | DEC left_value						{$$ = uniNode(LEFTDEC, $2);}
	 | left_value DEC 						{$$ = uniNode(RIGHTDEC, $1);}
	 | expr '*' expr 						{$$ = binNode('*', $1, $3);}
	 | expr '/' expr 						{$$ = binNode('/', $1, $3);}
	 | expr '%' expr 						{$$ = binNode('%', $1, $3);}
	 | expr '+' expr 						{$$ = binNode('+', $1, $3);}
	 | expr '-' expr 						{$$ = binNode('-', $1, $3);}
	 | expr '<' expr 						{$$ = binNode('<', $1, $3);}
	 | expr '>' expr 						{$$ = binNode('>', $1, $3);}
	 | expr LEQ expr 						{$$ = binNode(LEQ, $1, $3);}
	 | expr GEQ expr 						{$$ = binNode(GEQ, $1, $3);}
	 | expr DIF expr 						{$$ = binNode(DIF, $1, $3);}
	 | expr '=' expr 						{$$ = binNode('=', $1, $3);}
	 | '~' expr 							{$$ = uniNode('~', $2);}
	 | expr '&' expr 						{$$ = binNode('&', $1, $3);}
	 | expr '|' expr 						{$$ = binNode('|', $1, $3);}
	 | left_value ASSIGN expr 				{$$ = binNode(ASSIGN, $1, $3);}
;

args : args ',' expr 						{$$ = binNode(ARGS, $1, $3);}
	 | expr 								{$$ = $1;}
;


%%

/*

if_else_instr : left_if_else_instr non_for_non_if_instr
			  | left_if_else_instr for_instr
			  | left_if_else_instr if_instr
;

left_if_else_instr : left_if_instr IF expr THEN instr ELSE
				   | IF expr THEN instr ELSE
;


if_instr : left_if_instr non_for_non_if_instr
		 | left_if_instr for_instr
		 | left_if_instr if_else_instr
;

left_if_instr : left_if_instr 
			  | IF expr THEN
;


for_instr : left_for_instr non_for_non_if_instr
		  | left_for_instr if_instr
		  | left_for_instr if_else_instr
;

left_for_instr : left_for_instr FOR left_value IN expr UPTO expr DO
			   | FOR left_value IN expr UPTO expr DO
;

*/

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

