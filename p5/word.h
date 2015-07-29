/*
  Kyle Rush
  CSE109
  word.h
  This is the declaration of the Word class.
*/

#include "check.h"
#include <iostream>
using namespace std;

class Word{
private:
  char *wd, * delimiters;
  int count, size;
public:
  static const int DEFAULT_SIZE = 10;
  Word();
  Word(char c);
  Word(int x);
  Word(char *c, char *stoppers=" \t\n");
  Word(const Word &w);
  ~Word();
  const Word & operator =(const Word &w);
  void setDelimiters(char *c);
  Word & add(char ch);
  int length()const;
  char * getStr()const;
  int asInt()const;
  int countLetters(const Word &w) const;
  double asDouble()const;
  char & operator[](int loc);
  char operator[](int loc)const;
  bool operator==(const Word&b)const;
  friend bool operator==(char * a, const Word &b);
  friend bool operator==(char a, const Word &b);
  bool operator!=(const Word &b)const;
  Word & operator+(const Word &b);
  friend bool operator!=(char *a, const Word &b);
  friend bool operator!=(char a, const Word &b);
  friend bool operator<(const Word &a, const Word &b);
  friend bool operator<=(const Word &a, const Word &b);
  friend bool operator>(const Word &a, const Word &b);
  friend bool operator>=(const Word &a, const Word &b);
  friend ostream & operator<<(ostream &out,const Word &b);
  friend istream &operator>>(istream &in,Word &b);
private:
  void init(char *c,char *stoppers=" \t\n");
   void grow(); 
  bool stopCh(istream &in, char& ch);
};


