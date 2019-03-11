%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"

void yyerror(char *s);

int nest = 0;
%}

%x COM STR

%%
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
":="
"++"
"--"	
[-+*/%<>=!|&~]			return *yytext;
[0-9]+		  			yylval.i = strtol(yytext, 0, 10); return INT;
[a-zA-Z][a-zA-Z_0-9]    yylval.s = strdup(yytext); return ID;
[0-9]\.[0-9]			return NUM;
%%

int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
