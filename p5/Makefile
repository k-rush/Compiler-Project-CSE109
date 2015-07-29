p5: p5.o word.o check.o
	g++ -Wall -Werror p5.o word.o check.o -o p5
p5.o: p5.cc word.h
	g++ -Wall -Werror p5.cc word.h -c
word.o: word.cc word.h check.h
	g++ -Wall -Werror word.cc word.h check.h -c
check.o: check.cc check.h
	g++ -Wall -Werror check.cc check.h -c
clean:
	rm *.o *~


