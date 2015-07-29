#include "ALU.h"
int main(){
  
  ALU a;  a.enter(2);
  a.push().enter(3);
  a.push().add().pop();
  cout<<"Expect ControlUnit(5): "<<a<<endl;
  a.push().enter(4);
  cout<<"Expect ControlUnit(20): "<<a.push().mul().pop()<<endl;
  a.push().enter(8);
  cout<<"Expect ControlUnit(2.5): "<<a.push().div().pop()<<endl;
  a.push().enter(3);
  cout<<"Expect ControlUnit(-0.5): "<<a.push().sub().pop()<<endl;
  a.push().enter(0);
  a+= 65.5;
  cout << "Expect ControlUnit(65.0): "<<a << endl;
  // a.push().div();  //should crash
  /*  a.push().push().push().push().push().push().push();
  a.push().push().push().push().push().push().push();
  a.push().push().push().push().push().push().push();*/ //should crash
							//if run


  ALU cu;
  cout << "Maximum number of memory areas for our Control Unit " << cu.MAXMEM << endl;

  cout << "Enter a number" << endl;

  cin>>cu;  //overload >> for reading in a double and storing the
  //double into the accumulator of our Control Unit
  //Assume a 10.25 is entered

  cout<<"Expect ControlUnit(10.25): "<<cu <<endl;
  // overload << so it prints the
  // accumulator value

  cout << "Expect ControlUnit(11.1951): " << ((((cu + 25 )+ 5 )-2)* 3) / cu.getAccumulator() << endl;
    cout<<"Expect 11.1951: "<<cu.getAccumulator()<<endl;
  ALU cu1(cu); //test of copy constructor
  (cu1 - 4) * (5 /3);
  cout<<"Expect ControlUnit(11.1951), ControlUnit(7.19512): "<<cu<<", "<<cu1<<endl;
  cu.clear();
  cu.clearMem(2).enter(25.50).addMem(2).opAcc(cu.ADD,2).opAcc(cu.MUL,2).opAcc(ControlUnit::SUB,2);
  cu.opAcc(cu.DIV,2);
  cout<<"Expect ControlUnit(50): "<<cu<<endl;
  cout<<"Expect ControlUnit(25.5): "<<cu.setAcc(2)<<endl;  //gets mem2
							   //to
  //accumulator
  ALU cu2(cu);
  cout << "Expect 1: " << (cu2 == 25.5) << endl;
  cout<<"Expect ControlUnit(25.5): "<<cu2.setAcc(2)<<endl;

  cout << "Expect 0: " << (a == 25.5) << endl;
   
  }
  
