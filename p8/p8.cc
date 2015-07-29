
//p8.cc
int main(int ct, char **arg) {
  if(ct == 1); //error
  else if (ct > 2);//error
  ifstream in;
  in.open(arg[1]);
  //check if opened
  SkLang sk;
  sk.load(in);
  sk.run();
}

//SkLang.h
class SkLang: public ALU {
public:
  static const int MAXPROGRAM = 100;
  SkLang();
  //copy copy and destructor
  void load(istream &in);
  void run();
protected:
  Word program[MAXPROGRAM];
  Link<Word, int> variables;
  Link<Word, int> labels;
  Lex lex;
  int progsize, varCount, pc;
private:
  void checkLabel(const Word &w);
  void setInput();
  void doREAD();
  void doWRITE();
  void doPUSH();
  void doPOP();
  void doMINUS();
  void doPLUS();
};

void SkLang::load(istream &in) {
  fstream fin, fin1;
  fin.open("data");
  check(fin.good(), "failure to open data file");
  fin1.open("symbols");
  check(fin1.good(), "failure to open symbols");
  lex.loadKeyWords(fin);
  lex.loadSymbols(fin1);
  progsize = 0;
  varCount = 0;
  cou<<"Loading:\n";
  while(in.good()&&progsize<MAXPROGRAM) {
    pc= progsize;
    program[progsize].setDelimiters("\n");
    in>>program[progsize];
    cout<<progsize<<": "<<program[progsize]<<endl;
    checkLabel(program[progsize]);
    progsize++;
  }
  setInput();
  cout<<"Program successfully loaded.\n------------------------------\n";
}

void SkLang::checkLabel(const Word &w) {
  Word temp;
  lex.setString(w);
  tok = lex.next();
  if(tok==Lex::IDENTIFIER && lex.peek() == Lex::COLON)
    temp = lex.word();
  //check for duplicate labels
  check(!label.inList(temp),"Duplicate labels");
  label[temp] = progsize; //puts the line nuber associated with label
}

void SkLang::run() {
  steps = 0;
  pc = 0;
  cout<<"Running \n---------------------------\n";
  while(pc < progsize && program[pc] != "END") {
    lex.setString(program[pc]);
    pc++;
    tok = lex.next();
    skipLabel();
    doLine();
    check(tok == Lex::DOLLAR, "(SkLang::run() end of line expected");
  }
}

voidd SkLang::doLine(){
  switch(tok) {
  case Lex::READ:
    doREAD();
    break;
  case Lex::PUSH:
    doPUSH();
    break;
  case Lex::POP:
    doPOP();
    break;
  case Lex::WRITE:
    doWRITE();
    break;
  case Lex::CLEAR:
    doCLEAR();
    break;
  case Lex::MINUS:
    doMINUS();
    break;
  case Lex::PLUS:
    doPLUS();
    break;
  default: cout<<"Token not found.\n";
  }
}

void doREAD() {
  int sign;
  tok = lex.next();
  check(tok==Lex::NUMBER || tok == Lex::IDENTIFIER || tok == Lex::MINUS || tok== Lex::DOLLAR, "error");
  if(tok == Lex::IDENTIFIER) {
    check(variable.inList(lex.word()), "error");
    int memLoc = varTab[lex.word()];
    enter(memory[memLoc];
	  }
    else if(tok == Lex::NUMBER || tok == Lex::MINUS) {
      sign = 1;
      if(tok == Lex::MINUS) {
	sign = -1;
	tok = len.next();
	check(tok == Lex::NUMBER, "(SkLang::doREAD()) - token not a number.");
      }
      enter(sign*lex.word().asDouble());
    }
    else enter(getInput());
  }
}

void SkLang::doWRITE() {
  tok = lex.next();
  if(tok == Lex::DOLLAR) {
    cout<<"Accumulator ------> "<<getAccumulator()<<endl;
  }
  else {
    check(varTab.inList(lex.word()), "(SkLang::doWRITE()) - variable not defined.");
    cout<<lex.word()<<"------> "<<memory[varTab[lex.word()]]<<endl;
  }
}

void SkLang::doCLEAR() {
  tok = lex.next();
  if(tok == Lex::DOLLAR) {
    cout<<"ACcumulator ------> "<<getAccumulator()<<endl;
  }
  else {
    check(varTab.inList(lex.word()), "(SkLang::doCLEAR()) - variable not defined.");
    clearMem(varTab[lex.word()]);
  }
}

