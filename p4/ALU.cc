/*
  Kyle Rush
  CSE109
  The following is the implementation of the ALU class. */

#include "ALU.h"
//#include "ControlUnit.h"

/* Default constructor for the ALU class. Sets stack and stack
   position to 0. */
ALU::ALU() : ControlUnit() {
  for(int i = 0; i < 20; i++)
    stack[i] = 0;
  position = 0;
}

/*Cpoy constructor - creates a copy of another ALU object. */
ALU::ALU(const ALU & a) : ControlUnit((ControlUnit &)a) {
  for(int i = 0; i < 20; i++)
    stack[i] = a.stack[i];
  position = a.position;
}

/* Pushes the accumulator to the next position in the stack. */
ALU & ALU::push() {
  stack[position] = getAccumulator();
  ++position;
  return *this;
}

/* Pops the last value on the stack to the accumulator. */
ALU & ALU::pop() {
  enter(stack[position-1]);
  --position;
  return *this;
}

/* Adds the last two values on the stack into the accumulator and then
   puts the value back on the stack. */
ALU & ALU::add() {
  //  cout << pop().getAccumulator() << " " << pop().getAccumulator() << endl;
  stack[position-2] = stack[position -1] + stack[position-2];
  position -=1;
  /enter(pop().getAccumulator() + pop().getAccumulator());
  push();
  return *this;
}

/* Subtracts the last two values on the stack into the accumulator and then
   puts the value back on the stack. */
ALU & ALU::sub() { 
  enter(pop().getAccumulator() - pop().getAccumulator());
  push();
  return *this;
}

/* Multiplies the last two values on the stack into the accumulator and then
   puts the value back on the stack. */
ALU & ALU::mul() {
 cout << pop().getAccumulator() << " " << pop().getAccumulator()<< endl;

  double temp = pop().getAccumulator();
  temp *= pop().getAccumulator();
  enter(temp);
  push();
  return *this;
}

/* Divides the last two values on the stack into the accumulator and then
   puts the value back on the stack. */
ALU & ALU::div() {
  enter(pop().getAccumulator() / pop().getAccumulator());
  push();
  return *this;
}

/* Adds value to the accumulator */
ALU & ALU::operator += (double num) {
  enter(getAccumulator() + num);
  return *this;
}

/* Checks if value is equal to accumulator. */
bool ALU::operator == (double num) {
  return getAccumulator() == num;
}


