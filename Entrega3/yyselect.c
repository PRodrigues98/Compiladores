/*
generated at Mon May 13 16:53:59 2019
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "diy.brg"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yystmt_NT 1

static YYCONST char *yyntname[] = {
	0,
	"stmt",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "END",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "STRING",
	/* 260 */ "ID",
	/* 261 */ "NUM",
	/* 262 */ "INTEGER",
	/* 263 */ "NUMBER",
	/* 264 */ "STRING_TYPE",
	/* 265 */ "FOR",
	/* 266 */ "IF",
	/* 267 */ "THEN",
	/* 268 */ "ELSE",
	/* 269 */ "WHILE",
	/* 270 */ "DO",
	/* 271 */ "IN",
	/* 272 */ "STEP",
	/* 273 */ "UPTO",
	/* 274 */ "DOWNTO",
	/* 275 */ "BREAK",
	/* 276 */ "CONTINUE",
	/* 277 */ "GEQ",
	/* 278 */ "LEQ",
	/* 279 */ "DIF",
	/* 280 */ "ASSIGN",
	/* 281 */ "INC",
	/* 282 */ "DEC",
	/* 283 */ "VOID",
	/* 284 */ "PUBLIC",
	/* 285 */ "CONST",
	/* 286 */ "ROOT",
	/* 287 */ "DECL",
	/* 288 */ "DECLS",
	/* 289 */ "TYPE",
	/* 290 */ "PARAMS",
	/* 291 */ "PARAM",
	/* 292 */ "PARAMTYPE",
	/* 293 */ "FUNC",
	/* 294 */ "INSTR",
	/* 295 */ "INSTRS",
	/* 296 */ "CORPO",
	/* 297 */ "IFELSE",
	/* 298 */ "DOWNUP",
	/* 299 */ "EXPR",
	/* 300 */ "ALLOC",
	/* 301 */ "LVALUE",
	/* 302 */ "ARG",
	/* 303 */ "ARGS",
	/* 304 */ "RIGHTINC",
	/* 305 */ "LEFTINC",
	/* 306 */ "RIGHTDEC",
	/* 307 */ "LEFTDEC",
	/* 308 */ "CALL",
	/* 309 */ "VAR",
	/* 310 */ "PRIVATE",
	/* 311 */ "FUNCPROP",
	/* 312 */ "TYPEID",
	/* 313 */ "VARPROP",
	/* 314 */ "ERROR",
	/* 315 */ "NIL",
	/* 316 */ "POINTER",
	/* 317 */ "ADDRESS",
	/* 318 */ "SYMMETRIC",
	""
};

struct yystate {
	short cost[2];
	struct {
		unsigned int yystmt:1;
	} rule;
};

static short yynts_0[] = { 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"stmt: END",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_stmt[] = {
	0,
	1,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 1)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}


static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 59: /* END */
		/* stmt: END */
		yytrace(a, 1, 1 + 0, p->cost[yystmt_NT]);
		if (1 + 0 < p->cost[yystmt_NT]) {
			p->cost[yystmt_NT] = 1 + 0;
			p->rule.yystmt = 1;
		}
		break;
	case 257: /* INT */
		return;
	case 258: /* STRING */
		return;
	case 259: /* ID */
		return;
	case 260: /* NUM */
		return;
	case 261: /* INTEGER */
		return;
	case 262: /* NUMBER */
		return;
	case 263: /* STRING_TYPE */
		return;
	case 264: /* FOR */
		return;
	case 265: /* IF */
		return;
	case 266: /* THEN */
		return;
	case 267: /* ELSE */
		return;
	case 268: /* WHILE */
		return;
	case 269: /* DO */
		return;
	case 270: /* IN */
		return;
	case 271: /* STEP */
		return;
	case 272: /* UPTO */
		return;
	case 273: /* DOWNTO */
		return;
	case 274: /* BREAK */
		return;
	case 275: /* CONTINUE */
		return;
	case 276: /* GEQ */
		return;
	case 277: /* LEQ */
		return;
	case 278: /* DIF */
		return;
	case 279: /* ASSIGN */
		return;
	case 280: /* INC */
		return;
	case 281: /* DEC */
		return;
	case 282: /* VOID */
		return;
	case 283: /* PUBLIC */
		return;
	case 284: /* CONST */
		return;
	case 285: /* ROOT */
		return;
	case 286: /* DECL */
		return;
	case 287: /* DECLS */
		return;
	case 288: /* TYPE */
		return;
	case 289: /* PARAMS */
		return;
	case 290: /* PARAM */
		return;
	case 291: /* PARAMTYPE */
		return;
	case 292: /* FUNC */
		return;
	case 293: /* INSTR */
		return;
	case 294: /* INSTRS */
		return;
	case 295: /* CORPO */
		return;
	case 296: /* IFELSE */
		return;
	case 297: /* DOWNUP */
		return;
	case 298: /* EXPR */
		return;
	case 299: /* ALLOC */
		return;
	case 300: /* LVALUE */
		return;
	case 301: /* ARG */
		return;
	case 302: /* ARGS */
		return;
	case 303: /* RIGHTINC */
		return;
	case 304: /* LEFTINC */
		return;
	case 305: /* RIGHTDEC */
		return;
	case 306: /* LEFTDEC */
		return;
	case 307: /* CALL */
		return;
	case 308: /* VAR */
		return;
	case 309: /* PRIVATE */
		return;
	case 310: /* FUNCPROP */
		return;
	case 311: /* TYPEID */
		return;
	case 312: /* VARPROP */
		return;
	case 313: /* ERROR */
		return;
	case 314: /* NIL */
		return;
	case 315: /* POINTER */
		return;
	case 316: /* ADDRESS */
		return;
	case 317: /* SYMMETRIC */
		return;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 1: /* stmt: END */
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[0];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* stmt: END */
#line 13 "diy.brg"
{	}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yystmt == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 14 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;
