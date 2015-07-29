#include <iostream>
#inlcude "ControlUnit.h"
using namespace std;

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
