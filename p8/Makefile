#Kyle Rush
#Program #7

OBJS = p8.o SkLang.o alu.o lex.o check.o word.o
CFLAGS = -c -Wall -Werror

p8: $(OBJS)
	g++ -o p7 $(OBJS)
p8.o: p8.cc SkLang lex.h word.h pointerTemp.t check.h
	g++ $(CFLAGS) p8.cc
SkLang.o: SkLang.cc SkLang.h pointerTemp.h check.h word.h
	g++ $(CFLAGS) SkLang.cc
clean:
	rm *~

