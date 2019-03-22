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
void addChar(char *dest, char c);
char *dupstr(const char *s);
int parseInt(char *s, int base);
double parseDouble(char *s);
int octal(char *s);

int mallocCheck = 0, delim = 0;

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



\"([^"]|\\\")*\"			yylval.s = checkedMalloc(yyleng); if(yylval.s != NULL){*yylval.s = 0; mallocCheck = 1;} REJECT;

\"							BEGIN STR;

<STR>\"						mallocCheck = 0; BEGIN 0; delim = 1; return STRING;
<STR>\\n					if(mallocCheck) strcat(yylval.s, "\n");
<STR>\\t					if(mallocCheck) strcat(yylval.s, "\t");
<STR>\0						yyerror("Invalid character in string");
<STR>\\\"					if(mallocCheck) strcat(yylval.s, yytext + 1);
<STR>\\\\					if(mallocCheck) strcat(yylval.s, yytext + 1);
<STR>\\([0-9A-Fa-f]{1,2})	if(mallocCheck) addChar(yylval.s, (char)parseInt(yytext + 1, 16));
<STR>\\(.|\n)				yyerror("Invalid escape sequence in string");
<STR>.|\n					if(mallocCheck) strcat(yylval.s, yytext);



"void"		  			delim = 0; return VOID;
"integer"     			delim = 0; return INTEGER;
"string"	  			delim = 0; return STRING_TYPE;
"public"	  			delim = 0; return PUBLIC;
"number"	  			delim = 0; return NUMBER;
"const"		  			delim = 0; return CONST;
"if"		  			delim = 0; return IF;
"then"		  			delim = 0; return THEN;
"else"		  			delim = 0; return ELSE;
"while"		  			delim = 0; return WHILE;
"do"		  			delim = 0; return DO;
"for"		  			delim = 0; return FOR;
"in"		  			delim = 0; return IN;
"step"		  			delim = 0; return STEP;
"upto"		  			delim = 0; return UPTO;
"downto"	  			delim = 0; return DOWNTO;
"break"		  			delim = 0; return BREAK;
"continue"   		 	delim = 0; return CONTINUE;


">="					delim = 0; return GEQ;
"<="					delim = 0; return LEQ;
"<>"					delim = 0; return DIF;
":="					delim = 0; return ASSIGN;
"++"					delim = 0; return INC;
"--"					delim = 0; return DEC;


[)!]					delim = 1; return *yytext;
[-+*/%<>=!|&~]			delim = 0; return *yytext; /*Operadores*/
[#{}()[\];,]			delim = 0; return *yytext; /*Delimitadores*/


[1-9][0-9]*	  			yylval.i = parseInt(yytext, 10); delim = 1; return INT;
0[0-9]*					yylval.i = octal(yytext + 1);  delim = 1; return INT;
0b[01]+					yylval.i = parseInt(yytext + 2, 2); delim = 1; return INT;


[0-9]+\.[0-9]+([\E\e]([-+])?[0-9]+)?		yylval.d = parseDouble(yytext); delim = 1; return NUM;


[a-zA-Z][a-zA-Z0-9_]*   yylval.s = dupstr(yytext); delim = 1; return ID;


\n						 if(delim == 1){ delim = 0; return ';'; }


[ \t\r]+				; /*Atencao ao \n*/

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