#include "check.h"
//#include "pointerTemp.t"
#include "ALU.h"
#include "word.h"
#include "lex.h"

class SkLang: public ALU {
public:
  static const int MAXPROGRAM = 100;
  SkLang();
  void load(istream &in);
  void run();
protected:
  Word program[MAXPROGRAM];
  Link<Word,int> varTab;
  Link<Word,int> labels;
  Lex lex;
  int progsize;
  int varCount;
  int pc;
  int tok;
private:
  void checkLabel(const Word &w);
  void setInput();
  void skipLabel();
  void run();
  void doLine();
  void doWhile();
  void doIf();
  void doEndIf();
  void doBoolExpression();
  void doExpression();
  void doPlus();
  void doMinus();
  void doTimes();
  void doDivide();
  void doDim();
  void doIdentifier();
  void doStack();
  void doRead();
  void doWrite();
  void doClear();
  void doPush();
  void doPop();
};
