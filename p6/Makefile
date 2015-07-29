#Kyle Rush
#Program #6

OBJS = p6.o word.o check.o
CFLAGS = -c -Wall -Werror

p6: $(OBJS)
	g++ -o p6 p6.o word.o check.o
p6.o: p6.cc pointerTemp.t check.h
	g++ $(CFLAGS) p6.cc
check.o: check.cc check.h
	g++ $(CFLAGS) check.cc check.h
word.o: word.cc word.h check.h
	g++ $(CFLAGS) word.cc word.h check.h
clean:
	rm *.o *~ p6

