/*
  Kyle Rush
  cse 109
  p3
  This program creates a class called ControlUnit, which saves an
  acccumulator, as well as 10 memory locations for saving partial
  calculations.
*/
#include "ControlUnit.h"
#include <iostream>
using namespace std;


/* The main method here is used to test the code of the ControlUnit
   class. */

int main(){
  ControlUnit cu;
  cout << "Maximum number of memory areas for our Control Unit " << cu.MAXMEM << endl;

  cout << "Enter a number" << endl;

  cin>>cu;  //overload >> for reading in a double and storing the
	    //double into the accumulator of our Control Unit
	    //Assume a 10.25 is entered
  
  cout<<"Expect ControlUnit(10.25): "<<cu <<endl;
                                      // overload << so it prints the
				      // accumulator value 
  
  cout << "Expect ControlUnit(11.1951): " << ((((cu + 25 )+ 5 )-2)* 3) / cu.getAccumulator() << endl;


  //overload the +, -, * and / operators where the operation is
  //performed on the accumulator of the control Unit - where it takes
  //what is in the accumulator adds, subtracts, multiplies or
  //divides with some number and then puts the value back into
  //accumulator        for example     accumulator = accumulator + 5;

  cout<<"Expect 11.1951: "<<cu.getAccumulator()<<endl;
  ControlUnit cu1(cu); //test of copy constructor

  
  (cu1 - 4) * (5 /3);   
  cout<<"Expect ControlUnit(11.1951), ControlUnit(7.19512): "<<cu<<", "<<cu1<<endl;
  cu.clear();
  cu.clearMem(2).enter(25.50).addMem(2).opAcc(cu.ADD,2).opAcc(cu.MUL,2).opAcc(ControlUnit::SUB,2);
  cu.opAcc(cu.DIV,2);
  cout<<"Expect ControlUnit(50): "<<cu<<endl;
  cout<<"Expect ControlUnit(25.5): "<<cu.setAcc(2)<<endl;  //sets mem2
							   //to accumulator
  ControlUnit cu2(cu);
  cout<<"Expect ControlUnit(25.5): "<<cu2.setAcc(2)<<endl;
}

/*OUTPUT WHEN THE ABOVE IS RUN AND THE USER ENTERED 10.25
Maximum number of memory areas for our Control Unit 10
Enter a number
10.25
Expect ControlUnit(10.25): ControlUnit(10.25)
Expect ControlUnit(11.1951): ControlUnit(11.1951)
Expect 11.1951: 11.1951
Expect ControlUnit(11.1951), ControlUnit(7.19512):
ControlUnit(11.1951), ControlUnit(7.19512)
Expect ControlUnit(50): ControlUnit(50)
Expect ControlUnit(25.5): ControlUnit(25.5)
Expect ControlUnit(25.5): ControlUnit(25.5)
*/

/* The following code is the implementation of the methods declared in
   the ControlUnit class. */

