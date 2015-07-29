/*
  Kyle Rush
  CSE109
  Program: p7
  This file is the implementation of the "Lex" class,
  which interprets a given string of values as either
  a keyword, identifier, symbol, or number.
*/

#include "lex.h"

/*Default constructor for Lex class. */
Lex::Lex() {
  str = "";
  currentWd = "";
}

/*Loads an input buffer as the list of keywords used by Lex. */
void Lex::loadKeyWords(istream &in) {
  Word w;
  w.setDelimiters(" \n");
  Word data;
  in>>w;
  while(in.good()) {
    in>>data;
    lookUp[w] = data.asInt();
    in>>w;
  }
  
}

/*Loads an input buffer as a list of symbols used by Lex. */
void Lex::loadSymbols(istream &in) {
  Word s;
  s.setDelimiters(" \n");
  Word data;
  in>>s;
  while(in.good()) {
    in>>data;
    symbols[s] = data.asInt();
    in>>s;
  }
}

/*Sets the current Word "str" to the arg for interpreting.*/
void Lex::setString(const Word &w) {
  str = w;
  str.add('$');
  loc=0;
}

/*Checks to see if we are within bounds of str */
bool Lex::atEnd() {
  return loc<0 || loc>=str.length();
}

/*Returns the appropriate token for the next item in str. */
int Lex::next() {
  while(str[loc] == ' ' || str[loc] == '\t' || str[loc] == '\r') 
    loc++;
  
  check(!atEnd(), "(Lex::next()) reading past end of string. ");
  currentWd = "";
  if((str[loc] >= 'a' && str[loc] <= 'z' || str[loc] >= 'A' && str[loc] <= 'Z')) return alpha();
  else if(str[loc] >= '0' && str[loc] <= '9') return number();
  return symbol();
}

/*Method used to interperet words, and check if they are keywords. */
int Lex::alpha() {
  while(str[loc] != '$' && (str[loc] >= 'a' && str[loc] <= 'z') || (str[loc] >= 'A' && str[loc] <= 'Z')) {
    currentWd.add(str[loc]);
    loc++;
  }
  if(lookUp.inList(currentWd)) return lookUp[currentWd];
  return IDENTIFIER;
}

/*Method used to input numbers from the buffer. */
int Lex::number() {
  while(str[loc] != '$' && (str[loc] >= '0' && str[loc] <= '9') ||
	(str[loc] == '.' &&  (str[loc+1] >= '0' && str[loc+1] <= '9'))) {
    currentWd.add(str[loc]);
    loc++;
  }
  return NUMBER;
}

/*Method used to input symbols and return the appropriate token. */
int Lex::symbol() {
  currentWd.add(str[loc]);
  
  if((str[loc] == '>' || str[loc] == '<' || str[loc] == '=' || str[loc] == '!') && str[loc+1] == '=') {
    loc++;
    currentWd.add(str[loc]);
    //if(symbols.inList(currentWd)) return symbols[currentWd];
  }
  loc++;
  if(symbols.inList(currentWd)) 
    return symbols[currentWd];
  
  return JUNK;
}

/*Used to look at what the next token would be, without moving the
  location in str or modifying currentWd. */
int Lex::peek() {
  int tempLoc = loc;
  Word temp(currentWd);

  while(str[tempLoc] == ' ' || str[tempLoc] == '\t' || str[tempLoc] == '\r') tempLoc++;
  check(!atEnd(), "(Lex::peek()) reading past end of string. ");
  temp = "";

  //ALPHA
  if((str[tempLoc] >= 'a' && str[tempLoc] <= 'z' || str[tempLoc] >= 'A' && str[tempLoc] <= 'Z')) {
    
    while(str[tempLoc] != '$' && (str[tempLoc] >= 'a' && str[tempLoc] <= 'z') || (str[tempLoc] >= 'A' && str[tempLoc] <= 'Z')) {
      temp.add(str[tempLoc]);
      tempLoc++;
    }
    if(lookUp.inList(temp)) return lookUp[temp];
    return IDENTIFIER;
  }

  
  //NUMBER
  else if(str[tempLoc] >= '0' && str[tempLoc] <= '9') {
    while(str[tempLoc] != '$' && (str[tempLoc] >= '0' && str[tempLoc] <= '9') ||
	(str[tempLoc] == '.' &&  (str[tempLoc+1] >= '0' && str[tempLoc+1] <= '9'))) {
    temp.add(str[tempLoc]);
    tempLoc++;
  }
  return NUMBER;

  }
  
  //SYMBOL
  temp.add(str[tempLoc]);
  if(symbols.inList(temp)) return symbols[temp];
  tempLoc++;
  if((str[tempLoc] == '>' || str[tempLoc] == '<' || str[tempLoc] == '=' || str[tempLoc] == '!') && str[tempLoc+1] == '=') {
    tempLoc++;
    temp.add(str[tempLoc]);
    if(symbols.inList(temp)) return symbols[temp];
  }
  return JUNK;
  
}

/* Reset to a location within str. */
void Lex::reset(int k) {
  check(k < str.length() && k >=0, "(Lex::reset(int) index out of bounds of str.");
  loc = k;
  currentWd = "";
}

/*Returns position within str. */
int Lex::position() const{
  return loc;
}

/*Returns contents of currentWd. */
Word Lex::word() const {
  return currentWd;
}

