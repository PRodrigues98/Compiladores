%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "y.tab.h"

#define MAXBITS 31

int nest = 0;

extern int yyerror(char *s);

%}

%x COM1 COM2 STR

%%



"=<"					BEGIN COM1;
<COM1>"=<"				nest++;
<COM1>"=>"				if(nest == 0) BEGIN INITIAL; else nest--;					
<COM1>.|\n 				;

"=="					BEGIN COM2;
<COM2>.					;
<COM2>\n				BEGIN INITIAL;



\"([^\"]|\\.)*\"	yylval.s = malloc(yyleng); *yylval.s = 0; REJECT;

\"					BEGIN STR;

<STR>\"				BEGIN 0; return STRING;
<STR>\\n			strcat(yylval.s, "\n");
<STR>\\t			strcat(yylval.s, "\t");
<STR>\\\"			strcat(yylval.s, yytext + 1);
<STR>\\.			yyerror("Invalid escape sequence in string");
<STR>.|\n			strcat(yylval.s, yytext);



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


[-+*/%<>=!|&~]			return *yytext; /*Operadores*/
[#{}()[\];,]			return *yytext; /*Delimitadores*/


[0-9]+		  			yylval.i = strtol(yytext, NULL, 10); return INT;
[a-zA-Z][a-zA-Z0-9_]*   yylval.s = strdup(yytext); return ID;
[0-9]\.[0-9]			yylval.d = strtod(yytext, NULL); return NUM;


[ \n\t\r]+				; //Atencao ao \n

.						yyerror("Unknown character");

%%

int yywrap(void) { 
	if (YYSTATE == COM1 || YYSTATE == COM2) yyerror("Unterminated comment");
    if (YYSTATE == STR) yyerror("Unterminated string");

	return 1; 
}

char *getyytext(){ 

    return yytext; 
}

int checkOverflow(long int i){
	return (i >> MAXBITS) != 0;
}
