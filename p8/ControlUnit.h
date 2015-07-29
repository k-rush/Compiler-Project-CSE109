#include <iostream>
using namespace std;

/* Class ControlUnit holds an accumulator and a memory unit
      with ten locations for saving partial calcutlations.
         It also provides methods for manipulating the accumulator and
	 the memory array. */
class ControlUnit {
public:

  /* The following constants are used with the opAcc method for
     performing operations on the accumulator. */
  static const int ADD = 0;
  static const int SUB = 1;
  static const int MUL = 2;
  static const int DIV = 3;

  /* this value specifies the size of the memory array. */
  static const int MAXMEM = 10;

private:

  /* the accumulator holds a double value in which operations can be
     performed. */
  double accumulator;

  /* this memory pointer acts as an array that can store double values
     as partial calculations. */
  double *memory;

public:

  /*The purpose of these methods and operators are described below the
    main() method with their implementation. */
  ControlUnit();
  ControlUnit(ControlUnit &cu);
  ~ControlUnit();
  void clear();
  ControlUnit & enter(double d);
  ControlUnit & addMem(int mem);
  ControlUnit & setAcc(int mem);
  ControlUnit & clearMem(int mem);
  ControlUnit & opAcc(int op, int mem);
  double getAccumulator();
  ControlUnit & operator + (double num);
  ControlUnit & operator - (double num);
  ControlUnit & operator * (double num);
  ControlUnit & operator / (double num);
  friend ostream &operator << (ostream &out, ControlUnit &cu);
  friend istream &operator >> (istream &in, ControlUnit &cu);
};
