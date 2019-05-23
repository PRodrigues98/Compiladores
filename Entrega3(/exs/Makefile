.SUFFIXES: .$(EXT) .asm
COMP=../diy # compiler
EXT=diy # file extension: .$(EXT)
LIB=diy # runtime library: lib$(LIB).a
RUN=../run # runtime directory
AS=nasm -felf32 # assembler command
LD=ld -melf_i386 # loader command


#SRC= Test/Tblock.diy
#SRC= Test/Tbreak.diy 
#SRC= Test/Tcontinue.diy
#SRC= Test/Tdoubleop.diy
#SRC= Test/Texterns.diy
#SRC= Test/Tfor.diy 
#SRC= Test/Tif.diy 
#SRC= Test/Tincr.diy 
#SRC= Test/Tlocal.diy 
#SRC= Test/Tmean.diy 
#SRC= Test/Toperation.diy 
#SRC= Test/Tref.diy
#SRC= Test/Tstring.diy
#SRC= Test/Tvariables.diy 
#SRC= Test/Twhile.diy 


#SRC= testeAndOr.diy 
#SRC= testeBreakContinueWithWhile.diy 
#SRC= ack.diy
#SRC= hello.diy 
#SRC= testeStringReference.diy
#SRC= testeAlloc.diy
#SRC= factorial.diy
SRC= testeStringComparisons.diy

EXE=$(SRC:%.diy=%)

all:: compiler runtime $(EXE)

compiler::
	make -C ..

runtime::
	make -C $(RUN)

%:%.$(EXT)
	$(COMP) -trace $<
	$(AS) $*.asm -o $*.o
	$(LD) -o $@ $*.o -L$(RUN) -l$(LIB)

clean::
	rm -f *.o *.asm *.s *~ $(EXE)
