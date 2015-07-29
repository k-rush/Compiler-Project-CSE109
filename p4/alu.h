#include "ControlUnit.h"
/* The ALU class provides a stack of double variables and functions to
   act on that stack. */
class ALU: public ControlUnit {
private:
  double stack[];
  int position;
public:
  ALU();
  ALU(const ALU & a);
  ALU & push();
  ALU & pop();
  ALU & add();
  ALU & sub();
  ALU & mul();
  ALU & div();
  ALU & operator += (double num);
  bool  operator == (double num);
};


  
  
