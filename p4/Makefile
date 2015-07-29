p4: p4.o ALU.o ControlUnit.o
	g++ -o p4 p4.o ALU.o ControlUnit.o
p4.o: p4.cc
	g++ -c -Wall -Werror p4.cc
ControlUnit.o: ControlUnit.cc ControlUnit.h
	g++ -c -Wall -Werror ControlUnit.cc
ALU.o: ALU.cc ALU.h
	g++ -c -Wall -Werror ALU.cc
