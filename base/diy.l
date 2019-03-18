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

%x COM1 COM2 STR

%%



"=<"					BEGIN COM1;
<COM1>"=<"				nest++;
<COM1>"=>"				if(nest == 0) BEGIN INITIAL; else nest--;					
<COM1>.|\n 				printf("Bom dia!\n");

"=="					BEGIN COM2;
<COM2>.					;
<COM2>\n				BEGIN INITIAL;



"void"		  			return VOID;
"integer"     			return INTEGER;
"string"	  			return STRING_TYPE;
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


[-+*/%<>=!|&~\n]		return *yytext;


[0-9]+		  			yylval.i = strtol(yytext, NULL, 10); return INT;
[a-zA-Z][a-zA-Z0-9_]*   yylval.s = strdup(yytext); return ID;
[0-9]\.[0-9]			yylval.d = strtod(yytext, NULL); return NUM;


[ \t\r]+				; //Atencao ao \n

.						yyerror("Unknown character");

%%

int yywrap(void) { 
	if (YYSTATE == COM1) yyerror("Unterminated comment");
    if (YYSTATE == STR) yyerror("Unterminated string");

	return 1; 
}

char *getyytext(){ 

    return yytext; 
}
