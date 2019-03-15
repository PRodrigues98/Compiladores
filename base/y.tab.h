#define INT 257
#define STR 258
#define ID 259
#define NUM 260
#define FOR 261
#define IF 262
#define THEN 263
#define ELSE 264
#define WHILE 265
#define DO 266
#define IN 267
#define STEP 268
#define UPTO 269
#define DOWNTO 270
#define BREAK 271
#define CONTINUE 272
#define VOID 273
#define PUBLIC 274
#define CONST 275
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
	char *s;
	double d;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
