#Makefile for p3.cc
#Sharon Kalafut  
#CSE 109
#Summer 2011

p3: p3.o ControlUnit.o 
	g++ -o p3 p3.o ControlUnit.o

p3.o: p3.cc 
	g++ -c -Wall -Werror p3.cc

ControlUnit.o: ControlUnit.cc ControlUnit.h
	g++ -c -Wall -Werror ControlUnit.cc
clean:
	rm -f *~ *.o p3


