LANG=diy
CC=gcc
CFLAGS=-g -DYYDEBUG


$(LANG): $(LANG).y $(LANG).l
	byacc -dv $(LANG).y
	flex -l $(LANG).l
	$(LINK.c) -o $(LANG) lex.yy.c y.tab.c

clean::
	rm -f *.o $(LANG) lex.yy.c y.tab.c y.tab.h y.output yyselect.c *.asm *~
