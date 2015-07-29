#include "SkLang.h"
#include <fstream>
using namespace std;

void SkLang::load(istream &in) {
  ifstream dataIn, symbolsIn;
  dataIn.open("data");
  check(dataIn.good(), "SkLang::load() - failure to open data file.");
  symbolsIn.open("symbols");
  check(symbolsIn.good(), "Failure to open symbols.");
  lex.loadKeyWords(dataIn);
  lex.loadSymbols(symbolsIn);

  progsize = 0;
  varCount = 0;
  cout<<"Loading...\n";
  while(in.good() && progsize < MAXPROGRAM) {
    pc = progsize;
    program[progsize].setDelimiters("\n");
    in>>program[progsize];
    cout<<progsize<<":"<<program[progsize]<<endl;
    checkLabel(program[progsize]);
    progsize++;
  }
  cout<<"-------------------------\n";
}

void SkLang::checkLabel(const Word &w) {
  Word temp;
  lex.setString(w);
  tok = lex.next();
  if(took == Lex::IDENTIFIER && lex.peek() == Lex::COLON) {
    temp = lex.word();
    check(!label.inList(temp), "Duplicate Labels.\n");
    label(temp) = progsize;
  }
}

void SkLang::skipLabel() {
  if(tok == Lex::IDENTIFIER && lex.peek()==Lex::COLON) {
    tok = lex.next();
    lex.setString(program[pc]);
    pc++;
    tok = lex.next();
  }
}

void SkLang::run() {
  pc = 0;
  cout<<"Running... \n";
  while(pc < progSize && program[pc] != "END") {
    lex.setString(program[pc]);
    pc++;
    tok = lex.next();
    skipLabel();
    doLine();
  }
}

void SkLang::doLine() {
  switch(tok) {
  case Lex::READ: doRead(); break;
  case Lex::WRITE: doWrite(); break;
  case Lex::PUSH: doPush(); break;
  case Lex::POP: doPop(); break;
  case Lex::DIM: doDim(); break;
  case Lex::IDENTIFIER: doIdentifier(); break;
  case Lex::STACK: doStack(); break;
  case Lex::IF: doIf() break;
  case Lex::PLUS: doPlus() break;
  case Lex::MINUS: doMinus(); break;
  case Lex::TIMES: doTimes(); break;
  case Lex::DIVIDE: doDivide(); break;
  case Lex::CLEAR: doClear(); break;
  case Lex::ENDIF: doEndIf(); break;
  case Lex::ENDWHILE: doEndIf() break;
  case Lex::WHILE: doWhile() break;
  default: cout<<"Error: command not recognized.\n";
    exit(2);
  }
}

void SkLang::doPlus(){
  tok=lex.next();
  check(tok==Lex::IDENTIFIER || tok==Lex::NUMBER,"ERROR: SkLang::doPlus() Expecting identifier or number");
  if(tok==Lex::IDENTIFIER) accumulator+=memory[varTab[lex.word()]];
  else accumulator+=lex.word().asDouble();
}

void SkLang::doMinus(){
  tok=lex.next();
  check(tok==Lex::IDENTIFIER || tok==Lex::NUMBER,"ERROR: SkLang::doPlus() Expecting identifier or number");
  if(tok==Lex::IDENTIFIER) accumulator-=memory[varTab[lex.word()]];
  else accumulator-=lex.word().asDouble();
}

void SkLang::doTimes(){
  tok=lex.next();
  check(tok==Lex::IDENTIFIER || tok==Lex::NUMBER,"ERROR: SkLang::doPlus() Expecting identifier or number");
  if(tok==Lex::IDENTIFIER) accumulator*=memory[varTab[lex.word()]];
  else accumulator*=lex.word().asDouble();
}

void SkLang::doDivide(){
  tok=lex.next();
  check(tok==Lex::IDENTIFIER || tok==Lex::NUMBER,"ERROR: SkLang::doPlus() Expecting identifier or number");
  if(tok==Lex::IDENTIFIER) accumulator/=memory[varTab[lex.word()]];
  else accumulator/=lex.word().asDouble();
}


void SkLang::doWhile() {
  doBoolExpression();
  if(accumulator == 1) {
    while(tok!=Lex::ENDWHILE && program[pc] != "END") {
      lex.setString(program[pc]);
      pc++;
      tok = lex.next();
      doLine();
    }
  }
  else {
    while(tok!=Lex::ENDWHILE &&program[pc] != "END") {
      lex.setString(program[pc]);
      pc++;
      tok = lex.next();
    }

  }
}

void SkLang::doIf() {
  doBoolExpression();
  if(accumulator == 1) {
    lex.setString(program[pc]);
    pc++;
    tok = lex.next();
    doLine();
    while(tok != Lex::ENDIF) {
      lex.setString(program[pc]);
      pc++;
      tok = lex.next();
      doLine();
    }
  }
  else {
    lex.setString(program[pc]);
    pc++;
    tok = lex.next();
    while(tok != Lex::ENDIF) {
      lex.setString(program[pc]);
      pc++;
      tok = lex.next();
    }
  }
}

void SkLang::doExpression(){
  tok=lex.next();
  int sign = 1;
  check(tok==Lex::IDENTIFIER || tok==Lex::MINUS || tok==Lex::NUMBER, "SkLang::doExpression() Expected identifier, number, or minus sign");
  if(tok==Lex::MINUS){
      sign=-1;
      tok=lex.next();
      check(tok==Lex::NUMBER||tok==Lex::IDENTIFIER,"ERROR: expecting number or identifier after '-'");
   }
  
  if(tok==Lex::IDENTIFIER){
      check(varTab.inList(lex.word()), "SkLang::doExpression() Identifier not found.\n");
      enter(sign*memory[varTab[lex.word()]]);
      push();
   }
   else enter(sign*lex.word().asDouble());
   push();
}

void SkLang::doBoolExpression() {
  int op;
  doExpression();
  tok=lex.next();
  check(tok==Lex::GT || tok==Lex::LT || tok==Lex::EQ || tok==Lex::NEQ || tok==Lex::GE || tok==Lex::LE,"ERROR: SkLang::doBoolExpression() Expected boolean operator");
  op=tok;
  switch(op){
  case Lex::GT:
    doExpression();
    div();
    if(accumulator<1)
      enter(1);
    else enter(0);
    break;
  case Lex::LT:
    doExpression();
    div();
    if(accumulator>1) enter(1);
    else enter(0);
    break;
  case Lex::EQ:
    doExpression();
    div();
    if(accumulator==1) enter(1);
    else enter(0);
    break;
  case Lex::NEQ:
    doExpression();
    div();
    if(accumulator!=1) enter(1);
    else enter(0);
    break;
  case Lex::GE:
    doExpression();
    div();
    if(accumulator<=1) enter(1);
    else enter(0);
    break;
  case Lex::LE:
    doExpression();
    div();
    if(accumulator>=1) enter(1);
    else enter(0);
    break;
  }
}

void SkLang::doDim(){
  tok=lex.next();
  varTab[lex.word()]=varCount;
  memory[varTab[lex.word()]]=0;
  varCount++;
}

void SkLang::doIdentifier(){
  check(varTab.inList(lex.word()),"SkLang::doIdentifier() Variable not defined");
  int memLoc=varTab[lex.word()];
  memory[memLoc]+=accumulator;
  tok=lex.next();
  //check(tok==Lex::PLUS, "SkLang::doIdentifier() Expected '+' after identifier");
}

void SkLang::doStack(){
  tok=lex.next();
  if(tok==Lex::PLUS) add();
  else if(tok==Lex::MINUS) sub();
  else if(tok==Lex::TIMES) mul();
  else div();
}

void SkLang::doRead(){
  int sign;
  tok=lex.next();
  check(tok==Lex::NUMBER || tok==Lex::IDENTIFIER || tok==Lex::MINUS || tok==Lex::DOLLAR, "SkLang::doRead() Expecting identifier, number, or minus");
  if(tok==Lex::IDENTIFIER){
    check(varTab.inList(lex.word()),"SkLang::doRead() Variable not defined");
    int memLoc=varTab[lex.word()];
    enter(memory[memLoc]);
  }
  
  else if(tok==Lex::NUMBER || tok == Lex::MINUS){
    sign = 1;
    if(tok==Lex::MINUS){
      sign=-1;
      tok=lex.next();
      check(tok==Lex::NUMBER,"ERROR: expecting number after '-'");
    }
    enter(sign*lex.word().asDouble());
  }
  else{
    enter(0);
  }
}

void SkLang::doWrite(){
  tok=lex.next();
  if(tok==Lex::DOLLAR) cout<<"Accumulator ----->"<<getAccumulator()<<endl;
  else{
    check(varTab.inList(lex.word()), "ERROR: SkLang::doClear() Variable not defined");
    cout<<lex.word()<<"------>"<<memory[varTab[lex.word()]]<<endl;
  }
}

void SkLang::doClear(){
  tok=lex.next();
  if(tok==Lex::DOLLAR) clear();
  else{
    check(varTab.inList(lex.word()), "ERROR: SkLang::doClear() Variable not defined");
    clearMem(varTab[lex.word()]);
  }
}

void SkLang::doPush(){
  push();
}

void SkLang::doPop(){
  pop();
}


