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
};



%token <i> INT
%token <s> STRING ID
%token <d> NUM
%token INTEGER NUMBER STRING_TYPE
%token FOR IF THEN ELSE WHILE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE
%token GEQ LEQ DIF ASSIGN INC DEC
%token VOID PUBLIC CONST



%%
file	:
	;
%%



int yyerror(char *s) {

	extern int yylineno;
	extern char *getyytext();

	fprintf(stdin, "%s at or before '%s' in line %d\n", s, getyytext(), yylineno);

	yynerrs++;

	return 1; 
}

int main(int argc, char *argv[]) {
    extern YYSTYPE yylval;
    int tk;

    while((tk = yylex())) {
    	if(tk > YYERRCODE) {
		    printf("%d:\t%s\n", tk, yyname[tk]);
    	}
	    else {
		    printf("%d:\t%c\n", tk, tk);
	    }
	}

	printf("%d\n", yynerrs);

    return yynerrs;
}

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
