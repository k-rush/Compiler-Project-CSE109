/*
  Kyle Rush
  CSE109
  Program: p7

  This is the header file for the Lex class.  It defines all of the
  appropriate methods and variables used by Lex.
*/

#ifndef LEX_H
#define LEX_H

#include "pointerTemp.t"
#include "word.h"
#include "check.h"

class Lex {
public:
  static const int JUNK=43,NUMBER=0,IDENTIFIER=1,PLUS=2,MINUS=3,TIMES=4,DIVIDE=5,DIM=6,
    WRITE=10,READ=11,LBRACK=12,RBRACK=13,LPAR=14,RPAR=14,PUSH=16,POP=17,STACK=18,
    JUMP=19,JUMPL=20,JUMPG=21,JUMPLE=22,JUMPGE=23,JUMPE=24,JUMPNE=25,
    COLON=26,DOLLAR=27,END=28,LF=29,IF=30,THEN=31,ELSE=32,ENDIF=33,WHILE=34,DO=35,
    ENDWHILE=36,GT=37,LT=38,EQ=39,NEQ=40,GE=41,LE=42;

  Lex();
  void setString(const Word &w);
  int next();
  bool atEnd();
  void reset(int k=0);
  Word word() const;
  int position() const;
  int peek();
  void loadKeyWords(istream &in);
  void loadSymbols(istream &in);
private:
  Link<Word,int> lookUp, symbols;
  Word str, currentWd;
  int alpha();
  int symbol();
  int number();
  int loc;
};

#endif
