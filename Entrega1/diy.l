%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "y.tab.h"

#define MAXBITS 31

int nest = 0;

extern int yyerror(char *s);

char *checkedMalloc(int size);
void checkOverflow(long int i);
void catstr(char *dest, char *orig);
void addChar(char *dest, char c);
char *dupstr(const char *s);
int parseInt(char *s, int base);
double parseDouble(char *s);
int octal(char *s);

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



\"([^"]|\\\")*\"			yylval.s = checkedMalloc(yyleng); if(yylval.s != NULL) *yylval.s = 0; REJECT;

\"							BEGIN STR;

<STR>\"						BEGIN 0; return STRING;
<STR>\\n					catstr(yylval.s, "\n");
<STR>\\t					catstr(yylval.s, "\t");
<STR>\\\"					catstr(yylval.s, yytext + 1);
<STR>\\([0-9A-Fa-f]{1,2})	addChar(yylval.s, (char)parseInt(yytext + 1, 16));
<STR>.|\n					catstr(yylval.s, yytext);



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


[1-9][0-9]*	  			yylval.i = parseInt(yytext, 10); return INT;
0[0-9]*					yylval.i = octal(yytext + 1); printf("%d\n", yylval.i); return INT;
0b[01]+					yylval.i = parseInt(yytext + 2, 2); return INT;


[0-9]+\.[0-9]+([\E\e]([-+])?[0-9]+)?		yylval.d = parseDouble(yytext); return NUM;


[a-zA-Z][a-zA-Z0-9_]*   yylval.s = dupstr(yytext); return ID;


[ \n\t\r]+				; /*Atencao ao \n*/

.						yyerror("Unknown character");

%%


int yywrap(void){ 
	if (YYSTATE == COM1 || YYSTATE == COM2) yyerror("Unterminated comment");
    if (YYSTATE == STR) yyerror("Unterminated string");

	return 1; 
}


char *getyytext(){ 
    
    return yytext; 
}


int parseInt(char *s, int base){

	errno = 0;

    long int num = strtol(s, 0, base);

    if (errno == ERANGE || (num >> MAXBITS) != 0){
        yyerror("Decimal overflow");
    }

	return (int)num;
}


void catstr(char *dest, char *orig){
	
	/* 
		
		If the destination is not null then the string malloc worked, 
		if not there should already be an error given or one coming
		from an unterminated string

	*/

	if(dest != NULL){
		strcat(dest, orig);
	}
}


int octal(char *s){

    int i, a = 0, b = 0;

    for(i = 0; s[i] != '\0'; i++){

        b = b * 8 + s[i] - '0';

        if(b < a){
            yyerror("Octal overflow");
            break;
        }

        a = b;
    }

    return a;
}


char *checkedMalloc(int size){
	char *s = (char *)malloc(size * sizeof(char));

	if(s == NULL){
		yyerror("Memory allocation error");
	}

	return s;
}


char *dupstr(const char *s){
	char *d;
	
	if(s == NULL){
		return NULL;
	}
	
	d = checkedMalloc(strlen(s) + 1);
	
	if (d == NULL){
		return NULL; 
	}
	
	strcpy(d, s);
	
	return d;
}


void addChar(char *dest, char c){

	if(dest == NULL){
		return;
	}

	int len = strlen(dest);

	dest[len] = c;
	dest[len + 1] = '\0';
}


double parseDouble(char *s){
	double num = 0;

	if(sscanf(s, "%lf", &num) != 1){
		yyerror("Number overflow");

		return 0;
	}

	return num;
}