/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "diy.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "types.h"
#include "LinkedList.h"


extern int yylex();
extern int yyerror(char *s);
extern int errors;

typedef struct functionInfo {
	int initialized;
	LinkedList *args;
} FunctionInfo;

int cycles = 0;

#line 26 "diy.y"
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
#line 58 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    2,    2,
   16,    2,   17,    2,   18,    2,   19,    2,   20,    2,
   21,    2,   22,    2,   23,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    4,    4,    4,    4,
    4,    4,    3,    3,    3,    3,    3,    3,    3,    5,
    5,    6,    6,    6,    6,    7,    7,    8,    8,    9,
    9,   24,    9,   25,    9,    9,    9,    9,    9,    9,
    9,   15,   15,   15,   15,   26,   14,   14,   13,   13,
   13,   13,   10,   10,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   12,   12,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    6,    5,    5,    4,    5,    4,    3,
    0,   11,    0,   10,    0,   10,    0,    9,    0,   11,
    0,   10,    0,   10,    0,    9,    7,    6,    6,    5,
    7,    6,    6,    5,    2,    2,    1,    2,    1,    2,
    1,    2,    2,    3,    2,    2,    2,    3,    3,    2,
    4,    2,    1,    1,    0,    4,    3,    2,    1,    4,
    6,    0,    6,    0,    8,    2,    4,    5,    4,    2,
    2,    2,    3,    2,    3,    0,    1,    1,    2,    4,
    2,    4,    1,    4,    1,    1,    1,    1,    2,    3,
    4,    3,    2,    2,    2,    2,    2,    2,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    3,    3,    3,    3,    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,
    0,   35,   36,   38,   40,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   10,
    0,    0,    0,    0,    0,    0,    0,    9,    0,    0,
   43,   45,   47,   46,    0,    0,    0,    0,    7,   34,
   25,   50,    0,    0,    0,    0,    8,    0,    0,    0,
    5,    6,   44,   48,   49,   30,   17,    0,    0,   33,
   23,    0,   32,   21,    0,    4,   28,   13,    0,    0,
   29,   15,    0,   86,   88,    0,   87,    0,    0,   62,
    0,    0,    0,    0,    0,    0,    0,    0,   76,    0,
    0,    0,    0,   59,    0,    0,    0,   51,    0,   31,
   19,    0,   27,   11,    0,    0,   70,   71,    0,    0,
    0,    0,    0,    0,    0,   97,   99,   89,   93,    0,
   95,   94,    0,    0,    0,    0,    0,    0,   58,    0,
   98,  100,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   96,   66,    0,    0,
    0,    0,    0,    0,    0,   92,    0,    0,    0,    0,
    0,    0,    0,   77,    0,   78,   90,    0,   57,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   18,    0,   91,    0,   84,    0,    0,    0,   72,
    0,   74,    0,   67,    0,   56,   69,   24,   22,    0,
   14,    0,   16,    0,    0,    0,    0,    0,   73,   75,
    0,   68,   20,   12,    0,    0,   64,   61,   63,    0,
    0,    0,    0,    0,   65,
};
static const YYINT yydgoto[] = {                          1,
    2,   10,   31,  100,   34,  101,  102,  103,  104,  123,
  106,  168,  227,  175,  176,  163,  112,  116,   80,  161,
  109,  107,   69,  125,  242,  134,
};
static const YYINT yysindex[] = {                         0,
    0,  217,  -36,   12,   13,   17, -220, -126, -215,    0,
 -219,    0,    0,    0,    0,    0,   26, -189, -215, -178,
 -176,  -25,  -40,   47, -166,  -23, -184,  -42,    8,    0,
   41,  -39, -152,   30,   28,  -53,   71,    0,   54,   64,
    0,    0,    0,    0, -133, -158,  -14,   86,    0,    0,
    0,    0,   -9, -215,   -8,   90,    0,   73,   -6,   98,
    0,    0,    0,    0,    0,    0,    0,   -3,   23,    0,
    0, -119,    0,    0,   -2,    0,    0,    0,    5,   23,
    0,    0,  -15,    0,    0,  -18,    0, -114,   84,    0,
 -114, -114, -125, -114,   84,   84,   84,   84,    0,  -97,
   39,   23,   66,    0,  -16,  393,   23,    0,   23,    0,
    0,   23,    0,    0,   58,   23,    0,    0,   56,   84,
   59,  -86,  -83,  423,   37,    0,    0,    0,    0,  555,
    0,    0,  449,   23,  140,  141,  -64,   66,    0,   84,
    0,    0,   84,   84,   84,   84,   84,   84,   84,   84,
   84,   84,   84,   84,   84,   84,    0,    0,   76,   77,
   23,   79,   23,  147,   82,    0,  649,  136,  460,   84,
   37,  -52,  -46,    0,  -60,    0,    0, -109,    0,    0,
  150,  649,  481,  312,  312,   43,  660,  555,   43,  312,
  312,   25,   25,  179,  179,  179,  154,  155,   94,  161,
  102,    0,  166,    0,   84,    0,  382,  -38,  171,    0,
  172,    0,   84,    0,  107,    0,    0,    0,    0,  176,
    0,  178,    0,  649,   84,   84,  -28,   37,    0,    0,
  517,    0,    0,    0,  548,  589,    0,    0,    0,   84,
   84,   37,  649,  649,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,  255,    0,    1,    7,   19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  151,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  151,
    0,    0,    0,    0,    0,  -33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -107, -100,    0,  619,    0,  151,    0,  151,    0,
    0,  151,    0,    0,    0,  151,    0,    0,    0,    0,
  110,    0,  352,    0,    0,    0,    0,    0,    0,  135,
    0,    0,    0,  -88,    0,    0,    0,  -84,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  151,    0,  151,    0,    0,    0,  137,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  861,    0,  869,  905,  100,  960, 1055, 1063,  947,
  997,  810,  839,  703,  744,  797,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   -7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  144,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    3,    6,    0,    0,    0,    0,
    0,    0,   29,   31,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,   16, 1364,   -5,  807,    0,  197,  581, 1251,
 1139,    0,    0, -150,  127,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1493
static const YYINT yytable[] = {                         83,
   32,   83,   46,   83,   83,   57,  210,   83,   83,   83,
   83,   83,  212,   83,   29,  214,   37,   53,  143,   50,
  208,  119,   12,   48,   54,   83,   83,   83,   83,   56,
   60,   60,   60,   30,   60,   38,   55,   60,   17,   22,
   52,   39,   40,  117,   66,    4,    5,    6,   47,   70,
   73,   58,   77,   14,   15,   81,  110,  157,   16,   83,
   94,  156,   98,  113,   97,   23,  154,   96,   55,   24,
   53,  155,  120,   54,   94,  157,   98,  238,   97,  156,
   26,   96,   27,   51,  154,  152,   35,  153,   13,  155,
   83,  245,   36,   94,   28,   98,  166,   97,   64,   49,
   96,   65,  150,   94,  151,   98,   52,   97,   67,  118,
   96,   59,   61,   71,   74,   60,   78,   60,   60,   82,
  111,   94,   62,   98,   63,   97,   68,  114,   96,   54,
   75,   76,  128,   54,    4,    5,    6,  110,   79,  108,
  110,   54,   83,  110,  121,   99,   83,   83,   95,  120,
   83,   83,   83,   83,   83,   18,   83,   19,  110,   99,
  110,  135,   95,  136,  172,  173,   53,   53,   83,   83,
   83,   83,  112,   54,   54,  112,  204,  117,  112,  205,
  117,   95,  164,  170,  116,   55,   55,  116,   99,   52,
   52,   95,  110,  112,  181,  140,  141,  142,  179,  180,
  197,  198,   83,  200,  209,  202,  203,  213,  216,   95,
  211,  157,  218,  219,   41,   42,   43,   44,  220,  221,
    4,    5,    6,  110,  223,   28,  222,  112,  228,  229,
  230,  232,   83,   83,  233,   83,  234,   83,   83,   83,
  237,   45,   83,   83,   83,   83,   83,   83,   60,   60,
   60,   60,   60,   28,    1,   28,   60,   60,  112,   37,
   60,   60,  140,  141,  142,   39,   60,   60,    4,    5,
    6,   79,   60,   60,   81,   55,   60,   41,   83,   84,
   85,   86,   87,    4,    5,    6,   88,   89,    4,    5,
    6,   90,   83,   84,   85,   86,   87,   80,  138,   82,
   88,   89,   91,   92,  215,   90,   93,    0,    0,    0,
  172,  173,   84,   85,   86,   87,   91,   92,  144,  145,
   93,   83,   84,   85,   86,   87,    0,    0,    0,   88,
   89,    4,    5,    6,   90,   91,   92,    0,    0,   93,
   84,   85,   86,   87,  157,   91,   92,    0,  156,   93,
    0,    0,    0,  154,  152,    0,  153,    0,  155,    0,
    0,    0,    0,   91,   92,  110,    0,   93,  110,    0,
  110,  110,  110,    0,    0,   83,    0,  110,   83,   83,
   83,   83,   83,    0,   85,   83,   83,   83,   85,   85,
    0,    0,   85,   85,   85,   85,   85,    0,   85,    0,
  112,    0,    0,  112,    0,  112,  112,  112,    0,    0,
   85,   85,   85,   85,  157,    0,    0,    0,  156,  148,
    0,    0,    0,  154,  152,  157,  153,    0,  155,  156,
  148,    0,    0,    0,  154,  152,    0,  153,    0,  155,
    0,  150,  149,  151,   85,    0,    0,    0,    0,    0,
    0,  158,  150,  149,  151,  157,    0,    0,    0,  156,
  148,    0,    0,    0,  154,  152,    0,  153,    0,  155,
    0,    0,    3,    0,    0,   85,    0,    4,    5,    6,
    0,  157,  150,  149,  151,  156,  148,    0,    0,  177,
  154,  152,  157,  153,    0,  155,  156,  148,    7,    8,
    9,  154,  152,    0,  153,  147,  155,    0,  150,  149,
  151,    0,    0,  157,    0,    0,  147,  156,  148,  150,
  149,  151,  154,  152,    0,  153,    0,  155,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  217,
  150,  149,  151,    0,    0,    0,  147,    0,    0,  157,
    0,    0,  206,  156,  148,    0,    0,    0,  154,  152,
    0,  153,    0,  155,    0,    0,    0,    0,    0,    0,
    0,    0,  147,    0,    0,  239,  150,  149,  151,    0,
  157,    0,    0,  147,  156,  148,    0,  157,    0,  154,
  152,  156,  153,    0,  155,    0,  154,  152,    0,  153,
    0,  155,    0,    0,  147,    0,    0,  150,  149,  151,
    0,    0,    0,    0,  150,  149,  151,   85,    0,    0,
   85,  157,   85,   85,   85,  156,  148,   85,   85,   85,
  154,  152,    0,  153,    0,  155,    0,    0,    0,    0,
  147,    0,    0,    0,    0,    0,    0,    0,  150,  149,
  151,   85,    0,  225,  226,   85,   85,  144,  145,  146,
   85,   85,    0,   85,    0,   85,    0,    0,  144,  145,
  146,  147,    0,    0,    0,    0,    0,   85,   85,   85,
   85,  157,    0,  139,    0,  156,  148,    0,  171,    0,
  154,  152,  157,  153,    0,  155,  156,  148,  144,  145,
  146,  154,  152,    0,  153,  174,  155,    0,  150,  149,
  151,    0,  147,    0,    0,    0,    0,    0,  139,  150,
  149,  151,    0,    0,  144,  145,  146,    0,    0,    0,
    0,    0,    0,    0,    0,  144,  145,  146,    0,  101,
  101,    0,   85,  101,  101,  101,  101,  101,    0,  101,
    0,  174,    0,    0,    0,    0,  144,  145,  146,    0,
    0,  101,  101,  101,  101,    0,    0,    0,    0,    0,
    0,    0,  147,    0,    0,    0,    0,    0,    0,    0,
  102,  102,    0,    0,  102,  102,  102,  102,  102,    0,
  102,    0,  144,  145,  146,  101,    0,    0,    0,    0,
    0,    0,  102,  102,  102,  102,    0,    0,  174,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  240,    0,
    0,    0,  174,  144,  145,  146,  101,    0,    0,    0,
  144,  145,  146,  103,  103,    0,  102,  103,  103,  103,
  103,  103,    0,  103,    0,    0,    0,  104,    0,    0,
  104,    0,  104,  104,  104,  103,  103,  103,  103,  241,
    0,    0,    0,    0,  144,  145,  146,  102,  104,  104,
  104,  104,    0,    0,    0,    0,  105,    0,    0,  105,
    0,  105,  105,  105,    0,    0,  115,    0,    0,  103,
    0,    0,    0,    0,   85,   85,   85,  105,  105,  105,
  105,  115,  104,    0,  115,    0,  109,    0,    0,  109,
    0,    0,  109,  159,    0,  160,    0,    0,  162,  115,
  103,    0,  165,    0,  144,  145,  146,  109,  109,  109,
  109,  105,    0,  104,    0,  144,  145,  146,    0,    0,
  178,    0,  108,    0,    0,  108,    0,    0,  108,    0,
    0,    0,    0,  115,    0,    0,    0,    0,    0,    0,
    0,  109,  105,  108,  108,  108,  108,  199,  101,  201,
    0,  101,    0,  101,  101,  101,    0,    0,  101,  101,
  101,    0,    0,    0,  106,    0,    0,  106,    0,    0,
  106,    0,  109,    0,    0,    0,    0,  108,    0,    0,
  114,    0,    0,  114,    0,  106,  106,  106,  106,  102,
    0,    0,  102,    0,  102,  102,  102,    0,  114,  102,
  102,  102,    0,    0,    0,    0,    0,    0,  108,    0,
    0,    0,    0,    0,  107,    0,    0,  107,    0,  106,
  107,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  114,    0,    0,  107,  107,  107,  107,    0,
    0,    0,  103,    0,    0,  103,    0,  103,  103,  103,
  106,    0,  103,  103,  103,  104,    0,    0,  104,    0,
  104,  104,  104,  114,    0,  104,  104,  104,    0,  107,
    0,    0,  113,    0,    0,  113,    0,    0,  113,    0,
  111,    0,    0,  111,  105,    0,  111,  105,    0,  105,
  105,  105,    0,  113,  105,  105,  105,    0,    0,    0,
  107,  111,    0,  111,    0,    0,  115,    0,    0,  115,
    0,  115,  115,  115,  109,    0,    0,  109,    0,  109,
  109,  109,    0,    0,  109,  109,  109,  113,    0,    0,
    0,    0,    0,    0,    0,  111,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  108,    0,    0,  108,    0,  108,  108,  108,  113,    0,
  108,  108,  108,    0,    0,    0,  111,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  106,    0,    0,  106,    0,  106,  106,  106,
    0,    0,  106,  106,  106,  114,    0,  124,  114,    0,
  114,  114,  114,  130,  131,  132,  133,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  167,  169,    0,
    0,    0,  107,    0,    0,  107,    0,  107,  107,  107,
    0,    0,  107,  107,  107,    0,    0,    0,  182,    0,
    0,  183,  184,  185,  186,  187,  188,  189,  190,  191,
  192,  193,  194,  195,  196,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  207,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  105,
  113,    0,    0,  113,    0,  113,  113,  113,  111,    0,
  105,  111,    0,  111,  111,  111,    0,    0,  122,    0,
  111,  126,  127,  224,  129,    0,    0,    0,    0,    0,
    0,  231,  105,  105,    0,    0,    0,  105,    0,  105,
    0,    0,  105,  235,  236,   11,  105,    0,    0,    0,
    0,   20,   21,    0,    0,  105,    0,    0,  243,  244,
    0,    0,   25,    0,  105,    0,   33,    0,  105,    0,
    0,    0,   33,    0,    0,    0,    0,    0,   33,    0,
   33,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  105,    0,  105,    0,    0,    0,   72,    0,    0,
    0,  105,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  137,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  105,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  105,
};
static const YYINT yycheck[] = {                         33,
   41,   35,   45,   37,   38,   59,   59,   41,   42,   43,
   44,   45,   59,   47,   40,  125,   40,  125,   35,   59,
  171,   40,   59,   29,  125,   59,   60,   61,   62,   35,
   38,   37,   40,   59,   42,   59,  125,   45,  259,  259,
  125,   26,   27,   59,   59,  261,  262,  263,   41,   59,
   59,   36,   59,   42,   42,   59,   59,   33,   42,   93,
   38,   37,   40,   59,   42,   40,   42,   45,   41,  259,
   41,   47,   91,   44,   38,   33,   40,  228,   42,   37,
  259,   45,  259,  123,   42,   43,   40,   45,  125,   47,
  124,  242,  259,   38,  279,   40,   41,   42,  257,   59,
   45,  260,   60,   38,   62,   40,  259,   42,  123,  125,
   45,   41,   59,  123,  123,  123,  123,  125,  126,  123,
  123,   38,   59,   40,  258,   42,   41,  123,   45,   44,
   41,   59,  258,   44,  261,  262,  263,   38,   41,  259,
   41,   44,   33,   44,  259,  123,   37,   38,  126,   91,
   41,   42,   43,   44,   45,  282,   47,  284,   59,  123,
   61,  259,  126,  125,  274,  275,  274,  275,   59,   60,
   61,   62,   38,  274,  275,   41,   41,   41,   44,   44,
   44,  126,  125,  270,   41,  274,  275,   44,  123,  274,
  275,  126,   93,   59,  259,  279,  280,  281,   59,   59,
  125,  125,   93,  125,  257,   59,  125,  268,   59,  126,
  257,   33,   59,   59,  257,  258,  259,  260,  125,   59,
  261,  262,  263,  124,   59,  279,  125,   93,  267,   59,
   59,  125,  266,  124,   59,  269,   59,  271,  272,  273,
  269,  284,  276,  277,  278,  279,  280,  281,  256,  257,
  258,  259,  260,  279,    0,  279,  264,  265,  124,  259,
  268,  269,  279,  280,  281,  259,  274,  275,  261,  262,
  263,  269,  280,  281,  269,  125,  284,  259,  256,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  261,  262,
  263,  269,  256,  257,  258,  259,  260,  269,  102,  269,
  264,  265,  280,  281,  178,  269,  284,   -1,   -1,   -1,
  274,  275,  257,  258,  259,  260,  280,  281,  276,  277,
  284,  256,  257,  258,  259,  260,   -1,   -1,   -1,  264,
  265,  261,  262,  263,  269,  280,  281,   -1,   -1,  284,
  257,  258,  259,  260,   33,  280,  281,   -1,   37,  284,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,  280,  281,  266,   -1,  284,  269,   -1,
  271,  272,  273,   -1,   -1,  266,   -1,  278,  269,  270,
  271,  272,  273,   -1,   33,  276,  277,  278,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,
  266,   -1,   -1,  269,   -1,  271,  272,  273,   -1,   -1,
   59,   60,   61,   62,   33,   -1,   -1,   -1,   37,   38,
   -1,   -1,   -1,   42,   43,   33,   45,   -1,   47,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   60,   61,   62,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   33,   -1,   -1,   -1,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,  256,   -1,   -1,  124,   -1,  261,  262,  263,
   -1,   33,   60,   61,   62,   37,   38,   -1,   -1,   41,
   42,   43,   33,   45,   -1,   47,   37,   38,  282,  283,
  284,   42,   43,   -1,   45,  124,   47,   -1,   60,   61,
   62,   -1,   -1,   33,   -1,   -1,  124,   37,   38,   60,
   61,   62,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   60,   61,   62,   -1,   -1,   -1,  124,   -1,   -1,   33,
   -1,   -1,   93,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   59,   60,   61,   62,   -1,
   33,   -1,   -1,  124,   37,   38,   -1,   33,   -1,   42,
   43,   37,   45,   -1,   47,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,  124,   -1,   -1,   60,   61,   62,
   -1,   -1,   -1,   -1,   60,   61,   62,  266,   -1,   -1,
  269,   33,  271,  272,  273,   37,   38,  276,  277,  278,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,
   62,   33,   -1,  272,  273,   37,   38,  276,  277,  278,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,  276,  277,
  278,  124,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,
   62,   33,   -1,  103,   -1,   37,   38,   -1,  266,   -1,
   42,   43,   33,   45,   -1,   47,   37,   38,  276,  277,
  278,   42,   43,   -1,   45,  125,   47,   -1,   60,   61,
   62,   -1,  124,   -1,   -1,   -1,   -1,   -1,  138,   60,
   61,   62,   -1,   -1,  276,  277,  278,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  276,  277,  278,   -1,   37,
   38,   -1,  124,   41,   42,   43,   44,   45,   -1,   47,
   -1,  171,   -1,   -1,   -1,   -1,  276,  277,  278,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   37,   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,   -1,  276,  277,  278,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   60,   61,   62,   -1,   -1,  228,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  271,   -1,
   -1,   -1,  242,  276,  277,  278,  124,   -1,   -1,   -1,
  276,  277,  278,   37,   38,   -1,   93,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   38,   -1,   -1,
   41,   -1,   43,   44,   45,   59,   60,   61,   62,  271,
   -1,   -1,   -1,   -1,  276,  277,  278,  124,   59,   60,
   61,   62,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   43,   44,   45,   -1,   -1,   80,   -1,   -1,   93,
   -1,   -1,   -1,   -1,  276,  277,  278,   59,   60,   61,
   62,   41,   93,   -1,   44,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,  107,   -1,  109,   -1,   -1,  112,   59,
  124,   -1,  116,   -1,  276,  277,  278,   59,   60,   61,
   62,   93,   -1,  124,   -1,  276,  277,  278,   -1,   -1,
  134,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   93,  124,   59,   60,   61,   62,  161,  266,  163,
   -1,  269,   -1,  271,  272,  273,   -1,   -1,  276,  277,
  278,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,   -1,  124,   -1,   -1,   -1,   -1,   93,   -1,   -1,
   41,   -1,   -1,   44,   -1,   59,   60,   61,   62,  266,
   -1,   -1,  269,   -1,  271,  272,  273,   -1,   59,  276,
  277,  278,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   93,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   93,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,  266,   -1,   -1,  269,   -1,  271,  272,  273,
  124,   -1,  276,  277,  278,  266,   -1,   -1,  269,   -1,
  271,  272,  273,  124,   -1,  276,  277,  278,   -1,   93,
   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,
   38,   -1,   -1,   41,  266,   -1,   44,  269,   -1,  271,
  272,  273,   -1,   59,  276,  277,  278,   -1,   -1,   -1,
  124,   59,   -1,   61,   -1,   -1,  266,   -1,   -1,  269,
   -1,  271,  272,  273,  266,   -1,   -1,  269,   -1,  271,
  272,  273,   -1,   -1,  276,  277,  278,   93,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  266,   -1,   -1,  269,   -1,  271,  272,  273,  124,   -1,
  276,  277,  278,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  266,   -1,   -1,  269,   -1,  271,  272,  273,
   -1,   -1,  276,  277,  278,  266,   -1,   89,  269,   -1,
  271,  272,  273,   95,   96,   97,   98,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  119,  120,   -1,
   -1,   -1,  266,   -1,   -1,  269,   -1,  271,  272,  273,
   -1,   -1,  276,  277,  278,   -1,   -1,   -1,  140,   -1,
   -1,  143,  144,  145,  146,  147,  148,  149,  150,  151,
  152,  153,  154,  155,  156,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  170,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   69,
  266,   -1,   -1,  269,   -1,  271,  272,  273,  266,   -1,
   80,  269,   -1,  271,  272,  273,   -1,   -1,   88,   -1,
  278,   91,   92,  205,   94,   -1,   -1,   -1,   -1,   -1,
   -1,  213,  102,  103,   -1,   -1,   -1,  107,   -1,  109,
   -1,   -1,  112,  225,  226,    2,  116,   -1,   -1,   -1,
   -1,    8,    9,   -1,   -1,  125,   -1,   -1,  240,  241,
   -1,   -1,   19,   -1,  134,   -1,   23,   -1,  138,   -1,
   -1,   -1,   29,   -1,   -1,   -1,   -1,   -1,   35,   -1,
   37,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  161,   -1,  163,   -1,   -1,   -1,   54,   -1,   -1,
   -1,  171,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  102,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  228,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  242,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 317
#define YYUNDFTOKEN 346
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","STRING","ID","NUM",
"INTEGER","NUMBER","STRING_TYPE","FOR","IF","THEN","ELSE","WHILE","DO","IN",
"STEP","UPTO","DOWNTO","BREAK","CONTINUE","GEQ","LEQ","DIF","ASSIGN","INC",
"DEC","VOID","PUBLIC","CONST","ROOT","DECL","DECLS","TYPE","PARAMS","PARAM",
"PARAMTYPE","FUNC","INSTR","INSTRS","CORPO","IFELSE","DOWNUP","EXPR","ALLOC",
"LVALUE","ARG","ARGS","RIGHTINC","LEFTINC","RIGHTDEC","LEFTDEC","CALL","VAR",
"PRIVATE","FUNCPROP","TYPEID","VARPROP","ERROR","NIL","POINTER","ADDRESS",
"SYMMETRIC",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : decls",
"decls : decls decl",
"decls :",
"decl : PUBLIC CONST vartype ID varinit ';'",
"decl : PUBLIC vartype ID varinit ';'",
"decl : CONST vartype ID varinit ';'",
"decl : vartype ID varinit ';'",
"decl : PUBLIC CONST vartype ID ';'",
"decl : PUBLIC vartype ID ';'",
"decl : vartype ID ';'",
"$$1 :",
"decl : PUBLIC vartype ID '(' params ')' '{' $$1 corpo '}' ';'",
"$$2 :",
"decl : PUBLIC vartype ID '(' ')' '{' $$2 corpo '}' ';'",
"$$3 :",
"decl : vartype ID '(' params ')' '{' $$3 corpo '}' ';'",
"$$4 :",
"decl : vartype ID '(' ')' '{' $$4 corpo '}' ';'",
"$$5 :",
"decl : PUBLIC VOID ID '(' params ')' '{' $$5 corpo '}' ';'",
"$$6 :",
"decl : PUBLIC VOID ID '(' ')' '{' $$6 corpo '}' ';'",
"$$7 :",
"decl : VOID ID '(' params ')' '{' $$7 corpo '}' ';'",
"$$8 :",
"decl : VOID ID '(' ')' '{' $$8 corpo '}' ';'",
"decl : PUBLIC vartype ID '(' params ')' ';'",
"decl : PUBLIC vartype ID '(' ')' ';'",
"decl : vartype ID '(' params ')' ';'",
"decl : vartype ID '(' ')' ';'",
"decl : PUBLIC VOID ID '(' params ')' ';'",
"decl : PUBLIC VOID ID '(' ')' ';'",
"decl : VOID ID '(' params ')' ';'",
"decl : VOID ID '(' ')' ';'",
"decl : error ';'",
"decl : error '}'",
"vartype : INTEGER",
"vartype : INTEGER '*'",
"vartype : NUMBER",
"vartype : NUMBER '*'",
"vartype : STRING_TYPE",
"vartype : STRING_TYPE '*'",
"varinit : ASSIGN INT",
"varinit : ASSIGN CONST STRING",
"varinit : ASSIGN STRING",
"varinit : ASSIGN NUM",
"varinit : ASSIGN ID",
"varinit : ASSIGN '-' INT",
"varinit : ASSIGN '-' NUM",
"params : vartype ID",
"params : params ',' vartype ID",
"corpo : paramets instrs",
"corpo : paramets",
"corpo : instrs",
"corpo :",
"paramets : paramets vartype ID ';'",
"paramets : vartype ID ';'",
"instrs : instrs instr",
"instrs : instr",
"instr : IF expr THEN cycle_instr",
"instr : IF expr THEN cycle_instr ELSE cycle_instr",
"$$9 :",
"instr : DO $$9 cycle_instr WHILE expr ';'",
"$$10 :",
"instr : FOR left_value IN expr for_args DO $$10 cycle_instr",
"instr : expr ';'",
"instr : '{' push_subroutine corpo '}'",
"instr : '{' push_subroutine corpo cycle_control '}'",
"instr : left_value '#' expr ';'",
"instr : error ';'",
"instr : error '}'",
"cycle_control : BREAK ';'",
"cycle_control : BREAK INT ';'",
"cycle_control : CONTINUE ';'",
"cycle_control : CONTINUE INT ';'",
"push_subroutine :",
"cycle_instr : instr",
"cycle_instr : cycle_control",
"for_args : UPTO expr",
"for_args : UPTO expr STEP expr",
"for_args : DOWNTO expr",
"for_args : DOWNTO expr STEP expr",
"left_value : ID",
"left_value : ID '[' expr ']'",
"expr : left_value",
"expr : INT",
"expr : NUM",
"expr : STRING",
"expr : CONST STRING",
"expr : '(' expr ')'",
"expr : ID '(' args ')'",
"expr : ID '(' ')'",
"expr : '&' left_value",
"expr : '*' expr",
"expr : '-' expr",
"expr : expr '!'",
"expr : INC left_value",
"expr : left_value INC",
"expr : DEC left_value",
"expr : left_value DEC",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr LEQ expr",
"expr : expr GEQ expr",
"expr : expr DIF expr",
"expr : expr '=' expr",
"expr : '~' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : left_value ASSIGN expr",
"args : args ',' expr",
"args : expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 221 "diy.y"

int checkPointer(int a){

	if(isFunc(a)){
		yyerror("Invalid argument for value of operator");
		return cleanFunction(cleanPointer(a));
	}

	if((isPointer(a) || isString(a)) && isRightConst(a)){
		return setConst(cleanRightConst(cleanPointer(a)));
	}

	if(isPointer(a) && !isRightConst(a)){
		return cleanConst(cleanPointer(a));
	}
	else if(isString(a)){
		if(isRightConst(a)){
			return setConst(setInteger(0));
		}
		return setInteger(0);
	}

	yyerror("Invalid argument for value of operator");

	return cleanConst(cleanPointer(a));
}

int checkOperation(int a, int b){
	if(!isIntegerOrNum(a) || !isIntegerOrNum(b) || isPointer(a) || isPointer(b)){
		yyerror("Invalid argument for operator");
		return setInteger(0);
	}

	if(isNumber(a) || isNumber(b)){
		return setNumber(0);
	}
	else{
		return setInteger(0);
	}

	return setInteger(0);
}

int checkLocation(int a){
	if(isPointer(a)){
		yyerror("Cant apply location to pointer");
	}
	else if(isFunc(a)){
		yyerror("Cant apply location to function");
	}

	if(isConst(a)){
		return setRightConst(cleanConst(setPointer(a)));
	}

	return setPointer(a);
}

void checkDeclaration(int a, int b){

	if(isFunc(a) || isFunc(b)){
		yyerror("Illegal assignment");
		return;
	}

	if( ( getType(a) == getType(b) && isPointer(a) == isPointer(b)										   ) || 
	    ( isZero(b) 			   										   								   ) ||
	    ( (isInteger(a) && isPointer(a) && isString(b)) || (isInteger(b) && isPointer(b) && isString(a))   ) ){

		return;
	}

	yyerror("Illegal assignment");
}

int checkAssign(int a, int b){

	if(isFunc(a) || isFunc(b)){
		yyerror("Illegal assignment");
		return cleanFunction(b);
	}

	if(isConst(a)){
		yyerror("Cannot assign to constant variable");
		return a;
	}

	if(!isPointer(a) && !isPointer(b) && isIntegerOrNum(a) == isIntegerOrNum(b) && isIntegerOrNum(a)){
		return a;
	}

	int errorsBefore = errors;

	checkDeclaration(a, b);

	if(errors == errorsBefore){
		return a;
	}

	yyerror("Illegal assignment");

	return b;
}

void checkComparison(int a, int b){

	if(isZero(a) || isZero(b)){
		return;
	}

	if(!isPointer(a) && !isPointer(b) && isIntegerOrNum(a) == isIntegerOrNum(b)){
		return;
	}

	yyerror("Invalid arguments for comparison");
}

void pushArg(LinkedList *l){

	IDnew(l->type, l->id, 0);
}

int checkFunction(int type, char *id, LinkedList *l, int init){
	int declType = IDsearch(id, (long *)IDtest, IDlevel(), 0);
	FunctionInfo *info = 0;
	long aux;

	if(init == 2 && declType == -1){
		yyerror("Call to function that was not declared");

		return setInteger(0);
	}
	else if(init == 2 && declType != -1){

		if(!isFunc(declType)){
			yyerror("ID is not a function");

			return declType;
		}

		declType = IDsearch(id, &aux, IDlevel(), 0);

		info = (FunctionInfo *)aux;

		if(info == NULL){
			yyerror("Function information was not initialized");

			return cleanFunction(declType);
		}

		if(!compareLists(info->args, l)){
			yyerror("Incompatible arguments for function");
		}

		return cleanFunction(declType);
	}

	if(declType == -1){
		info = (FunctionInfo *)malloc(sizeof(FunctionInfo));

		info->initialized = 0;

		info->args = l;

		IDnew(type, id, (long)info);
	}
	else{

		declType = IDsearch(id, (long *)&aux, IDlevel(), 0);

		info = (FunctionInfo *)aux;

		if(declType != type){
			yyerror("Incompatible function returns");

			IDreplace(type, id, aux);

			return cleanFunction(type);
		}
		else if(!compareLists(info->args, l)){
			yyerror("Incompatible declared function arguments");

			IDreplace(type, id, aux);

			return cleanFunction(type);
		}
	}

	if(init == 1){
		if(info->initialized == 1){
			yyerror("Initialized a function twice");
		}

		IDpush();

		IDnew(cleanFunction(type), id, 0);

		forEachElement(l, pushArg);

		info->initialized = 1;

		return cleanFunction(type);
	}
}


char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

#line 975 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 70 "diy.y"
	{if(errors == 0) printNode(uniNode(ROOT, yystack.l_mark[0].n), 0, yynames);}
break;
case 2:
#line 73 "diy.y"
	{yyval.n = binNode(DECLS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 3:
#line 74 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 4:
#line 77 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, yystack.l_mark[-3].n, strNode(ID, yystack.l_mark[-2].s)), yystack.l_mark[-1].n)); checkDeclaration(setConst((yystack.l_mark[-3].n->value).i), yystack.l_mark[-1].n->info); IDnew(setConst((yystack.l_mark[-3].n->value).i), yystack.l_mark[-2].s, 0);}
break;
case 5:
#line 78 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, yystack.l_mark[-3].n, strNode(ID, yystack.l_mark[-2].s)), yystack.l_mark[-1].n)); checkDeclaration((yystack.l_mark[-3].n->value).i, yystack.l_mark[-1].n->info); IDnew((yystack.l_mark[-3].n->value).i, yystack.l_mark[-2].s, 0);}
break;
case 6:
#line 79 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(VAR, binNode(VARPROP, yystack.l_mark[-3].n, strNode(ID, yystack.l_mark[-2].s)), yystack.l_mark[-1].n)); checkDeclaration(setConst((yystack.l_mark[-3].n->value).i), yystack.l_mark[-1].n->info); IDnew(setConst((yystack.l_mark[-3].n->value).i), yystack.l_mark[-2].s, 0);}
break;
case 7:
#line 80 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(VAR, binNode(VARPROP, yystack.l_mark[-3].n, strNode(ID, yystack.l_mark[-2].s)), yystack.l_mark[-1].n)); checkDeclaration((yystack.l_mark[-3].n->value).i, yystack.l_mark[-1].n->info); IDnew((yystack.l_mark[-3].n->value).i, yystack.l_mark[-2].s, 0);}
break;
case 8:
#line 82 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, yystack.l_mark[-2].n, strNode(ID, yystack.l_mark[-1].s)), nilNode(NIL))); IDnew((yystack.l_mark[-2].n->value).i, yystack.l_mark[-1].s, 0);}
break;
case 9:
#line 83 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, yystack.l_mark[-2].n, strNode(ID, yystack.l_mark[-1].s)), nilNode(NIL))); IDnew((yystack.l_mark[-2].n->value).i, yystack.l_mark[-1].s, 0);}
break;
case 10:
#line 84 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(VAR, binNode(VARPROP, yystack.l_mark[-2].n, strNode(ID, yystack.l_mark[-1].s)), nilNode(NIL))); IDnew((yystack.l_mark[-2].n->value).i, yystack.l_mark[-1].s, 0);}
break;
case 11:
#line 87 "diy.y"
	{checkFunction(setFunction(yystack.l_mark[-5].n->value.i), yystack.l_mark[-4].s, (LinkedList*)yystack.l_mark[-2].n->user, 1);}
break;
case 12:
#line 87 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-9].n, strNode(ID, yystack.l_mark[-8].s)), yystack.l_mark[-6].n), yystack.l_mark[-2].n)); IDpop();}
break;
case 13:
#line 88 "diy.y"
	{checkFunction(setFunction(yystack.l_mark[-4].n->value.i), yystack.l_mark[-3].s, 0, 1);}
break;
case 14:
#line 88 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-8].n, strNode(ID, yystack.l_mark[-7].s)), nilNode(NIL)), yystack.l_mark[-2].n)); IDpop();}
break;
case 15:
#line 89 "diy.y"
	{checkFunction(setFunction(yystack.l_mark[-5].n->value.i), yystack.l_mark[-4].s, (LinkedList*)yystack.l_mark[-2].n->user, 1);}
break;
case 16:
#line 89 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-9].n, strNode(ID, yystack.l_mark[-8].s)), yystack.l_mark[-6].n), yystack.l_mark[-2].n)); IDpop();}
break;
case 17:
#line 90 "diy.y"
	{checkFunction(setFunction(yystack.l_mark[-4].n->value.i), yystack.l_mark[-3].s, 0, 1);}
break;
case 18:
#line 90 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-8].n, strNode(ID, yystack.l_mark[-7].s)), nilNode(NIL)), yystack.l_mark[-2].n)); IDpop();}
break;
case 19:
#line 92 "diy.y"
	{checkFunction(setFunction(setVoid(0)), yystack.l_mark[-4].s, (LinkedList*)yystack.l_mark[-2].n->user, 1);}
break;
case 20:
#line 92 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-8].s)), yystack.l_mark[-6].n), yystack.l_mark[-2].n)); IDpop();}
break;
case 21:
#line 93 "diy.y"
	{checkFunction(setFunction(setVoid(0)), yystack.l_mark[-3].s, 0, 1);}
break;
case 22:
#line 93 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-7].s)), nilNode(NIL)), yystack.l_mark[-2].n)); IDpop();}
break;
case 23:
#line 94 "diy.y"
	{checkFunction(setFunction(setVoid(0)), yystack.l_mark[-4].s, (LinkedList*)yystack.l_mark[-2].n->user, 1);}
break;
case 24:
#line 94 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-8].s)), yystack.l_mark[-6].n), yystack.l_mark[-2].n)); IDpop();}
break;
case 25:
#line 95 "diy.y"
	{checkFunction(setFunction(setVoid(0)), yystack.l_mark[-3].s, 0, 1);}
break;
case 26:
#line 95 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-7].s)), nilNode(NIL)), yystack.l_mark[-2].n)); IDpop();}
break;
case 27:
#line 97 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-5].n, strNode(ID, yystack.l_mark[-4].s)), yystack.l_mark[-2].n), nilNode(NIL))); checkFunction(setFunction(yystack.l_mark[-5].n->value.i), yystack.l_mark[-4].s, yystack.l_mark[-2].n->user, 0);}
break;
case 28:
#line 98 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-4].n, strNode(ID, yystack.l_mark[-3].s)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction(yystack.l_mark[-4].n->value.i), yystack.l_mark[-3].s, 0, 0);}
break;
case 29:
#line 99 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-5].n, strNode(ID, yystack.l_mark[-4].s)), yystack.l_mark[-2].n), nilNode(NIL))); checkFunction(setFunction(yystack.l_mark[-5].n->value.i), yystack.l_mark[-4].s, yystack.l_mark[-2].n->user, 0);}
break;
case 30:
#line 100 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, yystack.l_mark[-4].n, strNode(ID, yystack.l_mark[-3].s)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction(yystack.l_mark[-4].n->value.i), yystack.l_mark[-3].s, 0, 0);}
break;
case 31:
#line 102 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-4].s)), yystack.l_mark[-2].n), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), yystack.l_mark[-4].s, yystack.l_mark[-2].n->user, 0);}
break;
case 32:
#line 103 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PUBLIC), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-3].s)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), yystack.l_mark[-3].s, 0, 0);}
break;
case 33:
#line 104 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-4].s)), yystack.l_mark[-2].n), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), yystack.l_mark[-4].s, yystack.l_mark[-2].n->user, 0);}
break;
case 34:
#line 105 "diy.y"
	{yyval.n = binNode(DECL, nilNode(PRIVATE), binNode(FUNC, binNode(FUNCPROP, binNode(TYPEID, intNode(TYPE, setVoid(0)), strNode(ID, yystack.l_mark[-3].s)), nilNode(NIL)), nilNode(NIL))); checkFunction(setFunction(setVoid(0)), yystack.l_mark[-3].s, 0, 0);}
break;
case 35:
#line 108 "diy.y"
	{yyval.n = nilNode(ERROR);}
break;
case 36:
#line 109 "diy.y"
	{yyval.n = nilNode(ERROR);}
break;
case 37:
#line 112 "diy.y"
	{yyval.n = intNode(TYPE, setInteger(0));}
break;
case 38:
#line 113 "diy.y"
	{yyval.n = intNode(TYPE, setPointer(setInteger(0)));}
break;
case 39:
#line 114 "diy.y"
	{yyval.n = intNode(TYPE, setNumber(0));}
break;
case 40:
#line 115 "diy.y"
	{yyval.n = intNode(TYPE, setPointer(setNumber(0)));}
break;
case 41:
#line 116 "diy.y"
	{yyval.n = intNode(TYPE, setString(0));}
break;
case 42:
#line 117 "diy.y"
	{yyval.n = intNode(TYPE, setPointer(setString(0)));}
break;
case 43:
#line 120 "diy.y"
	{yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = setInteger(0); if(yystack.l_mark[0].i == 0) yyval.n->info = setZero(yyval.n->info);}
break;
case 44:
#line 121 "diy.y"
	{yyval.n = strNode(STRING, yystack.l_mark[0].s); yyval.n->info = setRightConst(setString(0));}
break;
case 45:
#line 122 "diy.y"
	{yyval.n = strNode(STRING, yystack.l_mark[0].s); yyval.n->info = setString(0);}
break;
case 46:
#line 123 "diy.y"
	{yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = setNumber(0);}
break;
case 47:
#line 124 "diy.y"
	{yyval.n = strNode(ID, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, 0);}
break;
case 48:
#line 125 "diy.y"
	{yyval.n = intNode(INT, -1 * yystack.l_mark[0].i); yyval.n->info = setInteger(0); if(yystack.l_mark[0].i == 0) yyval.n->info = setZero(yyval.n->info);}
break;
case 49:
#line 126 "diy.y"
	{yyval.n = realNode(NUM, -1 * yystack.l_mark[0].d); yyval.n->info = setNumber(0);}
break;
case 50:
#line 129 "diy.y"
	{yyval.n = binNode(PARAM, nilNode(NIL), binNode(PARAMTYPE, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s))); yyval.n->user = (void *)addElement(yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s, 0);}
break;
case 51:
#line 130 "diy.y"
	{yyval.n = binNode(PARAMS, yystack.l_mark[-3].n, binNode(PARAMTYPE, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s))); yyval.n->user = (void *)addElement(yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s, (LinkedList *)yystack.l_mark[-3].n->user);}
break;
case 52:
#line 133 "diy.y"
	{yyval.n = binNode(CORPO, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 53:
#line 134 "diy.y"
	{yyval.n = binNode(CORPO, yystack.l_mark[0].n, nilNode(NIL));}
break;
case 54:
#line 135 "diy.y"
	{yyval.n = binNode(CORPO, nilNode(NIL), yystack.l_mark[0].n);}
break;
case 55:
#line 136 "diy.y"
	{yyval.n = nilNode(NIL);}
break;
case 56:
#line 139 "diy.y"
	{yyval.n = binNode(PARAMS, yystack.l_mark[-3].n, binNode(PARAMTYPE, yystack.l_mark[-2].n, strNode(ID, yystack.l_mark[-1].s))); IDnew((yystack.l_mark[-2].n->value).i, yystack.l_mark[-1].s, 0);}
break;
case 57:
#line 140 "diy.y"
	{yyval.n = uniNode(PARAM, binNode(PARAMTYPE, yystack.l_mark[-2].n, strNode(ID, yystack.l_mark[-1].s))); IDnew((yystack.l_mark[-2].n->value).i, yystack.l_mark[-1].s, 0);}
break;
case 58:
#line 143 "diy.y"
	{yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 59:
#line 144 "diy.y"
	{yyval.n = uniNode(INSTR, yystack.l_mark[0].n);}
break;
case 60:
#line 147 "diy.y"
	{yyval.n = binNode(IF, yystack.l_mark[-2].n, yystack.l_mark[0].n); if(!isInteger(yystack.l_mark[-2].n->info) || isPointer(yystack.l_mark[-2].n->info)) yyerror("Invalid argument for if");}
break;
case 61:
#line 148 "diy.y"
	{yyval.n = binNode(IFELSE, binNode(IF, yystack.l_mark[-4].n, yystack.l_mark[-2].n), yystack.l_mark[0].n); if(!isInteger(yystack.l_mark[-4].n->info) || isPointer(yystack.l_mark[-4].n->info)) yyerror("Invalid argument for if");}
break;
case 62:
#line 149 "diy.y"
	{cycles++;}
break;
case 63:
#line 149 "diy.y"
	{yyval.n = binNode(WHILE, yystack.l_mark[-3].n, yystack.l_mark[-1].n); cycles--; if(!isInteger(yystack.l_mark[-1].n->info) || isPointer(yystack.l_mark[-1].n->info)) yyerror("Invalid argument for while");}
break;
case 64:
#line 150 "diy.y"
	{cycles++;}
break;
case 65:
#line 150 "diy.y"
	{yyval.n = binNode(FOR, yystack.l_mark[-6].n, binNode(PARAMS, yystack.l_mark[-4].n, binNode(INSTRS, yystack.l_mark[-3].n, yystack.l_mark[0].n))); cycles--; checkAssign(yystack.l_mark[-6].n->info, yystack.l_mark[-4].n->info);}
break;
case 66:
#line 151 "diy.y"
	{yyval.n = yystack.l_mark[-1].n;}
break;
case 67:
#line 152 "diy.y"
	{yyval.n = yystack.l_mark[-1].n; IDpop();}
break;
case 68:
#line 153 "diy.y"
	{yyval.n = binNode(CORPO, yystack.l_mark[-2].n, yystack.l_mark[-1].n); IDpop();}
break;
case 69:
#line 154 "diy.y"
	{yyval.n = binNode(ALLOC, yystack.l_mark[-3].n, yystack.l_mark[-1].n); if(!isInteger(yystack.l_mark[-1].n->info) || isPointer(yystack.l_mark[-1].n->info)) yyerror("Invalid argument for function");}
break;
case 70:
#line 156 "diy.y"
	{yyval.n = nilNode(ERROR);}
break;
case 71:
#line 157 "diy.y"
	{yyval.n = nilNode(ERROR);}
break;
case 72:
#line 160 "diy.y"
	{yyval.n = intNode(BREAK, 1); if(cycles < 1) yyerror("Not enough nested cycles for break instruction");}
break;
case 73:
#line 161 "diy.y"
	{yyval.n = intNode(BREAK, yystack.l_mark[-1].i); if(cycles < yystack.l_mark[-1].i) yyerror("Not enough nested cycles for break instruction argument");}
break;
case 74:
#line 162 "diy.y"
	{yyval.n = intNode(CONTINUE, 1); if(cycles < 1) yyerror("Not enough nested cycles for continue instruction");}
break;
case 75:
#line 163 "diy.y"
	{yyval.n = intNode(CONTINUE, yystack.l_mark[-1].i); if(cycles < yystack.l_mark[-1].i) yyerror("Not enough nested cycles for continue instruction argument");}
break;
case 76:
#line 166 "diy.y"
	{IDpush();}
break;
case 77:
#line 169 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 78:
#line 170 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 79:
#line 173 "diy.y"
	{yyval.n = binNode(DOWNUP, nilNode(UPTO), uniNode(STEP, intNode(INT, 1))); if(!isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid for arguments");}
break;
case 80:
#line 174 "diy.y"
	{yyval.n = binNode(DOWNUP, nilNode(UPTO), uniNode(STEP, yystack.l_mark[0].n)); if(!isInteger(yystack.l_mark[-2].n->info) || isPointer(yystack.l_mark[-2].n->info) || !isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid for arguments");}
break;
case 81:
#line 175 "diy.y"
	{yyval.n = binNode(DOWNUP, nilNode(DOWNTO), uniNode(STEP, intNode(INT, 1))); if(!isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid for arguments");}
break;
case 82:
#line 176 "diy.y"
	{yyval.n = binNode(DOWNUP, nilNode(DOWNTO), uniNode(STEP, yystack.l_mark[0].n)); if(!isInteger(yystack.l_mark[-2].n->info) || isPointer(yystack.l_mark[-2].n->info) || !isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid for arguments");}
break;
case 83:
#line 179 "diy.y"
	{yyval.n = strNode(ID, yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, 0);}
break;
case 84:
#line 180 "diy.y"
	{yyval.n = binNode(LVALUE, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n); if(!isInteger(yystack.l_mark[-1].n->info)) yyerror("Invalid address"); yyval.n->info = checkPointer(IDfind(yystack.l_mark[-3].s, 0));}
break;
case 85:
#line 183 "diy.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 86:
#line 184 "diy.y"
	{yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = setInteger(0); if(yystack.l_mark[0].i == 0) yyval.n->info = setZero(yyval.n->info);}
break;
case 87:
#line 185 "diy.y"
	{yyval.n = realNode(NUM, yystack.l_mark[0].d); yyval.n->info = setNumber(0);}
break;
case 88:
#line 186 "diy.y"
	{yyval.n = strNode(STRING, yystack.l_mark[0].s); yyval.n->info = setString(0);}
break;
case 89:
#line 187 "diy.y"
	{yyval.n = strNode(STRING, yystack.l_mark[0].s); yyval.n->info = setRightConst(setString(0));}
break;
case 90:
#line 188 "diy.y"
	{yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info;}
break;
case 91:
#line 189 "diy.y"
	{yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->info = checkFunction(-1, yystack.l_mark[-3].s, (LinkedList *)yystack.l_mark[-1].n->user, 2);}
break;
case 92:
#line 190 "diy.y"
	{yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-2].s), nilNode(NIL)); yyval.n->info = checkFunction(-1, yystack.l_mark[-2].s, 0, 2);}
break;
case 93:
#line 191 "diy.y"
	{yyval.n = uniNode(ADDRESS, yystack.l_mark[0].n); yyval.n->info = checkLocation(yystack.l_mark[0].n->info);}
break;
case 94:
#line 192 "diy.y"
	{yyval.n = uniNode(POINTER, yystack.l_mark[0].n); yyval.n->info = checkPointer(yystack.l_mark[0].n->info);}
break;
case 95:
#line 193 "diy.y"
	{yyval.n = uniNode(SYMMETRIC, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 96:
#line 194 "diy.y"
	{yyval.n = uniNode('!', yystack.l_mark[-1].n); if(!isInteger(yystack.l_mark[-1].n->info) || isPointer(yystack.l_mark[-1].n->info)) yyerror("Invalid argument for factorial"); yyval.n->info = setNumber(0);}
break;
case 97:
#line 195 "diy.y"
	{yyval.n = uniNode(RIGHTINC, yystack.l_mark[0].n); if(!isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid argument for increment"); yyval.n->info = setInteger(0);}
break;
case 98:
#line 196 "diy.y"
	{yyval.n = uniNode(LEFTINC, yystack.l_mark[-1].n); if(!isInteger(yystack.l_mark[-1].n->info) || isPointer(yystack.l_mark[-1].n->info)) yyerror("Invalid argument for increment"); yyval.n->info = setInteger(0);}
break;
case 99:
#line 197 "diy.y"
	{yyval.n = uniNode(LEFTDEC, yystack.l_mark[0].n); if(!isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid argument for decrement"); yyval.n->info = setInteger(0);}
break;
case 100:
#line 198 "diy.y"
	{yyval.n = uniNode(RIGHTDEC, yystack.l_mark[-1].n); if(!isInteger(yystack.l_mark[-1].n->info) || isPointer(yystack.l_mark[-1].n->info)) yyerror("Invalid argument for decrement"); yyval.n->info = setInteger(0);}
break;
case 101:
#line 199 "diy.y"
	{yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOperation(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 102:
#line 200 "diy.y"
	{yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOperation(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 103:
#line 201 "diy.y"
	{yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOperation(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 104:
#line 202 "diy.y"
	{yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOperation(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 105:
#line 203 "diy.y"
	{yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkOperation(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 106:
#line 204 "diy.y"
	{yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); checkComparison(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = setInteger(0);}
break;
case 107:
#line 205 "diy.y"
	{yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); checkComparison(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = setInteger(0);}
break;
case 108:
#line 206 "diy.y"
	{yyval.n = binNode(LEQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); checkComparison(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = setInteger(0);}
break;
case 109:
#line 207 "diy.y"
	{yyval.n = binNode(GEQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); checkComparison(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = setInteger(0);}
break;
case 110:
#line 208 "diy.y"
	{yyval.n = binNode(DIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); checkComparison(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = setInteger(0);}
break;
case 111:
#line 209 "diy.y"
	{yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); checkComparison(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = setInteger(0);}
break;
case 112:
#line 210 "diy.y"
	{yyval.n = uniNode('~', yystack.l_mark[0].n); if(!isInteger(yystack.l_mark[0].n->info) || !(isPointer(yystack.l_mark[0].n->info))) yyerror("Invalid argument for negation"); yyval.n->info = setInteger(0);}
break;
case 113:
#line 211 "diy.y"
	{yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); if(!isInteger(yystack.l_mark[-2].n->info) || isPointer(yystack.l_mark[-2].n->info) || !isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid arguments for logical AND"); yyval.n->info = setInteger(0);}
break;
case 114:
#line 212 "diy.y"
	{yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); if(!isInteger(yystack.l_mark[-2].n->info) || isPointer(yystack.l_mark[-2].n->info) || !isInteger(yystack.l_mark[0].n->info) || isPointer(yystack.l_mark[0].n->info)) yyerror("Invalid arguments for logical OR"); yyval.n->info = setInteger(0);}
break;
case 115:
#line 213 "diy.y"
	{yyval.n = binNode(ASSIGN, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = checkAssign(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); if(((isPointer(yystack.l_mark[-2].n->info) || isString(yystack.l_mark[-2].n->info)) && (isPointer(yystack.l_mark[0].n->info) || isString(yystack.l_mark[0].n->info))) && (isRightConst(yystack.l_mark[-2].n->info) != isRightConst(yystack.l_mark[0].n->info))) IDreplace(yystack.l_mark[0].n->info, yystack.l_mark[-2].n->value.s, 0);}
break;
case 116:
#line 216 "diy.y"
	{yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->user = (void *)addElement(yystack.l_mark[0].n->info, 0, yystack.l_mark[-2].n->user);}
break;
case 117:
#line 217 "diy.y"
	{yyval.n = yystack.l_mark[0].n; yyval.n->user = (void *)addElement(yystack.l_mark[0].n->info, 0, 0);}
break;
#line 1645 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
