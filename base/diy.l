%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"

void yyerror(char *s);

int nest = 0;
%}

%x COM1 COM2 STRING

%%
"=<"					BEGIN COM1;
<COM1>"=<"				nest++;
<COM1>"=>"				if(nest == 0) BEGIN INITIAL; else nest--;					
<COM1>.|\n 				;

"=="					BEGIN COM2;
<COM2>.					;
<COM2>\n				BEGIN COM2;

"for"		  			return FOR;
"void"		  			return VOID;
"integer"     			return INTEGER;
"string"	  			return STRING;
"public"	  			return PUBLIC;
"number"	  			return NUMBER;
"const"		  			return CONST;
"if"		  			return IF;
"then"		  			return THEN;
"else"		  			return ELSE;
"while"		  			return WHILE;
"do"		  			return DO;
"for"		  			return FOR;
"in"		  			return IN;
"step"		  			return STEP;
"upto"		  			return UPTO;
"downto"	  			return DOWNTO;
"break"		  			return BREAK;
"continue"   		 	return CONTINUE;
">="					return GEQ;
"<="					return LEQ;
"<>"					return DIF;
":="					return ASSIGN;
"++"					return INC;
"--"					return DEC;

[-+*/%<>=!|&~]			return *yytext;
[-+]?[0-9]+		  		yylval.i = strtol(yytext, NULL, 10); return INT;
[a-zA-Z][a-zA-Z_0-9]    yylval.s = strdup(yytext); return ID;
[0-9]\.[0-9]			yylval.d = strtod(yytext, NULL); return NUM;

%%

int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
