LANG=diy
LEX=diy
YACC=inicial
CC=gcc
CFLAGS=-g -DYYDEBUG


$(LEX): $(YACC).y $(LEX).l
	byacc -dv $(YACC).y
	flex -l $(LEX).l
	$(LINK.c) -o $(LANG) lex.yy.c y.tab.c

clean::
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output
