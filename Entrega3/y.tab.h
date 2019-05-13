#define INT 257
#define STRING 258
#define ID 259
#define NUM 260
#define INTEGER 261
#define NUMBER 262
#define STRING_TYPE 263
#define FOR 264
#define IF 265
#define THEN 266
#define ELSE 267
#define WHILE 268
#define DO 269
#define IN 270
#define STEP 271
#define UPTO 272
#define DOWNTO 273
#define BREAK 274
#define CONTINUE 275
#define GEQ 276
#define LEQ 277
#define DIF 278
#define ASSIGN 279
#define INC 280
#define DEC 281
#define VOID 282
#define PUBLIC 283
#define CONST 284
#define ROOT 285
#define DECL 286
#define DECLS 287
#define TYPE 288
#define PARAMS 289
#define PARAM 290
#define PARAMTYPE 291
#define FUNC 292
#define INSTR 293
#define INSTRS 294
#define CORPO 295
#define IFELSE 296
#define DOWNUP 297
#define EXPR 298
#define ALLOC 299
#define LVALUE 300
#define ARG 301
#define ARGS 302
#define RIGHTINC 303
#define LEFTINC 304
#define RIGHTDEC 305
#define LEFTDEC 306
#define CALL 307
#define VAR 308
#define PRIVATE 309
#define FUNCPROP 310
#define TYPEID 311
#define VARPROP 312
#define ERROR 313
#define NIL 314
#define POINTER 315
#define ADDRESS 316
#define SYMMETRIC 317
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
	Node *n;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
