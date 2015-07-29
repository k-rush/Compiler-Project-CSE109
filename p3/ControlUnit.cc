#include "ControlUnit.h"
#include <iostream>
using namespace std;

/* Default constrctor that initializes the
   accumulator and each memory location to 0. */
ControlUnit::ControlUnit() {
  accumulator = 0;
  memory = new double[MAXMEM];
}

/* Copy constructor that creates a new ControlUnit
   object based on the passed to it in the parameter. */
ControlUnit::ControlUnit(ControlUnit &cu) {
  accumulator = cu.getAccumulator();
  memory = new double[MAXMEM];
  for(int i = 0; i < MAXMEM; i++) memory[i] = cu.memory[i];
}

/* A deconstructor used to deallocate the memory locations of the
   "memory" array */
ControlUnit::~ControlUnit() {
  delete memory;
}

/* The clear() function sets accumulator and all memory locations to
   zero. */
void ControlUnit::clear() {
  accumulator =0;
  for(int i = 0; i < MAXMEM; i++) memory[i] = 0;
}

/* The enter(double) function is used to set the accumulator value to
   the
   value passed in the parameter. */
ControlUnit & ControlUnit::enter(double d) {
  accumulator = d;
  return *this;
}

/* The addMem(int) function adds the value in the accumulator to the
   value stored in the memory location specified y the parameter. */
ControlUnit & ControlUnit::addMem(int mem) {
  memory[mem] += accumulator;
  return *this;
}

/* The setAcc(int) function sets the accumulator to the value in the
   memory
   location specified by the parameter. */
ControlUnit & ControlUnit::setAcc(int mem) {
  accumulator = memory[mem];
  return *this;
}

/* clearMem(int) sets the value of the specified memory location to
   0. */
ControlUnit & ControlUnit::clearMem(int mem) {
  memory[mem] = 0;
  return *this;
}

/* This function returns the value in the accumulator. */
double ControlUnit::getAccumulator() {
  return accumulator;
}

/* The opAcc(int, int) function is used to perform operations between
   the accumulator and the memory.  The first parameter specifies the
   operation to be used (see constant declarations in the class
   declaration).  The second parameter is the memory location in which
   the value in that location is used to perform the operation. */
ControlUnit & ControlUnit::opAcc(int op, int mem) {
  switch(op) {
  case ADD:
    accumulator += memory[mem];
    break;
  case SUB:
    accumulator -= memory[mem];
    break;
  case MUL:
    accumulator *= memory[mem];
    break;
  case DIV:
    accumulator /= memory[mem];
    break;
  default:
    cout<<"Invalid operation.\n";
  }
  return *this;
}

/* Overloads the "+" operator.  Adds the value to the right of the
   operator to the accumulator and then returns the modified object
   that
   called the operator. */
ControlUnit & ControlUnit::operator + (double num) {
  accumulator += num;
  return *this;
}

/* Overloads the "-" operator to perform a subraction of the value to
      the right of the operator to the accumulator in the calling
      object. */
ControlUnit & ControlUnit::operator - (double num) {
  accumulator -= num;
  return *this;
}

/* Overloads the "*" operator.  The accumulator is multiplied by the
   value to the right of the operator. */
ControlUnit & ControlUnit::operator * (double num) {
  accumulator *= num;
  return *this;
}

/* Overloads the "/" operator.  The accumulator in the calling object
   is divided by the value to the right of the operator. */
ControlUnit & ControlUnit::operator / (double num) {
  accumulator /= num;
  return *this;
}


/* Overloads the ostream "<<" operator to print out the value of the
   accumulator. */
ostream & operator << (ostream &out, ControlUnit &cu) {
out<<"ControlUnit("<<cu.getAccumulator()<<")";
return out;
}

/* Overloads the istream ">>" operator so the user can input the value
   for the accumulator. */
istream & operator >> (istream &in, ControlUnit &cu) {
in >> cu.accumulator;
return in;
}
