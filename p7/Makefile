#Kyle Rush
#Program #7

OBJS = p7.o lex.o check.o word.o
CFLAGS = -c -Wall

p7: $(OBJS)
	g++ -o p7 $(OBJS)
p7.o: p7.cc lex.h word.h pointerTemp.t check.h
	g++ $(CFLAGS) p7.cc
lex.o: lex.cc lex.h word.h pointerTemp.t check.h
	g++ $(CFLAGS) lex.cc
check.o: check.cc check.h
	g++ $(CFLAGS) check.cc check.h
word.o: word.cc word.h check.h
	g++ $(CFLAGS) word.cc word.h check.h
clean:
	rm *.o *~ p6

