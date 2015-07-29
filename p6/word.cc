/*
  Kyle Rush
  CSE 109
  p5
  This is the implementation of the Word class.
*/


#include "word.h"

/* Default constructor */
Word::Word(){
  init("");
}

/* 2-arg constructor which accepts a string and and array of
   delimiters. */
Word::Word(char *c,char *stoppers){
  init(c,stoppers);
}

Word::Word(const char *c) {
  init(c);
}

/* Copy contructor. */
Word::Word(const Word &w){
  init(w.wd,w.delimiters);
}

/* Constructor that creates a Word object from a single character. */
Word::Word(char c){
  char temp[]={c,'\0'};
  init(temp);
}

/* Creates a word object from an integer value. */
Word::Word(int x){
  int sz, temp;
  char *w;
  check(x>0,"(Word(int)) can not have a negative argument");
  temp = x;
  sz = 0;
  if(temp==0)
    sz = 1;
  while(temp >0){
    temp/=10;
    sz++;
  }
  w=new char[sz+1];
  check(wd!=NULL,"Word init(int)) heap overflow");
  w[sz] = '\0';
  while(sz >0){
    sz--;
    w[sz] = x%10 +'0';
    x/=10;
  }
  init(w);
}

/* Returns the integer value of a word (if it can be represented as
   one. */
int Word::asInt() const{
  int temp;
  check(wd!=NULL,"Word asInt() heap overflow");
  temp = 0;
  for(int j = 0; j<count; j++){
   check(wd[j] >='0' && wd[j] <= '9',"Word::asInt()Non integer string");
    temp = 10*temp+wd[j] - '0';
  }
  return temp;
}

/* Deconstructor. */
Word::~Word(){
  delete [] wd;
  delete [] delimiters;
}

/* This function helps the contructors create the object. */
void Word::init(const char * c, char *stoppers){
  char *temp = "\0";
  if(c == NULL)
    c = temp;
  check(stoppers != NULL,"(Word(char*,char*))Null pointer");
  if(strlen(c) == 0)
    size = DEFAULT_SIZE;
  else
    size = strlen(c) + 1 + DEFAULT_SIZE;
  wd = new char[size];
  check(wd!=NULL,"Word(char *,char *)) heap overflow");
  delimiters = new char(strlen(stoppers) + 1);
  check(delimiters!=NULL,"Word(char *,char *)) heap overflow");
  strcpy(wd,c);
  strcpy(delimiters,stoppers);
  count = strlen(wd);
}

/* Adds a character to the end of the word. */
Word & Word::add(char ch){
  if(count > size -1)
    grow();
  wd[count] = ch;
  count++;
  wd[count]= '\0';
  return *this;
}

/* Expands the size of the character array. */
void Word::grow(){
  char *temp;
  size+= 10;
  temp = new char[size +1];
  // check(temp!=NULL,"Word::grow() heap overflow");
  strcpy(temp,wd);
  delete []wd;
  wd = temp;
}

/* overloading the [] operator o that bounds can be checked. */
char & Word::operator[](int loc){
  check(loc>0 && loc < count,"(Word::[]) range error");
  return wd[loc];
}

/* Again, overloading the [] operator to check for bounds. */
char Word::operator[](int loc) const{
  check(loc>= 0 && loc < count,"(Word::[]) range error");
  return wd[loc];
}

/* returns true if the string held by two words are identical. */
bool Word::operator==(const Word &b) const{
  return strcmp(wd,b.wd)==0;
}

/* Returns the string as a double value. */
double Word::asDouble()const{
  double fract, temp, divisor;
  int loc;
  check(wd!=NULL && count >0,"(Word::asDouble()) String is not a double");
  temp = 0;
  loc = 0;
  fract=0;
  check(wd[0]>='0' &&wd[0]<='9',"(Word::asDouble() String is not double");
  while(loc <count && wd[loc] >= '0' && wd[loc] <= '9'){
    temp = 10 * temp +wd[loc]-'0';
    loc++;
  }
  check(loc >=count || wd[loc]=='.',"(word::asDouble())'.' or end of string expected");
  if(wd[loc] =='.'){
    loc++;
    check(loc <count && wd[loc]>='0' &&wd[loc] <='9',"(Word::asDouble()) digit expected");
    divisor=10;
    while(loc < count && wd[loc]>='0' &&wd[loc]<='9'){
      fract+= (wd[loc] - '0')/divisor;
      divisor *= 10;
      loc++;
    }
  }
  return temp + fract;
}

/* Checks to see if the character is in the delimiter array. */
bool Word::stopCh(istream &in, char& ch){
  in.get(ch);
  if(!in.good())
    ch = '\n';
  for(unsigned j=0; j<strlen(delimiters);j++)
    if(ch==delimiters[j])
      return true;
  return false;
}

/* Overloads the >> operator so a word can be inputted from the input
   buffer. */
istream &operator>>(istream &in, Word &b){
  char ch;
  b.count=0;
  while(!b.stopCh(in,ch)){
    b.add(ch);
  }
  return in;
}

/* Sets the delimiter array to the specified array of characters. */
void Word::setDelimiters(char * c) {
  delimiters = new char(strlen(c) + 1);
  check(delimiters!=NULL,"setDelimeters(char *,c) heap overflow");
  strcpy(delimiters, c);
}
/* returns count. */
int Word::length() const {
  return count;
}
/* returns a copy of the word represented as a string. */
char * Word::getStr() const {
  char * temp;
  strcpy(temp,wd);
  return temp;
}

/* Overloads the assignment operator. */
const Word & Word::operator = (const Word & w) {
  strcpy(wd,w.wd);
  strcpy(delimiters,w.delimiters);
  size = w.size;
  count = w.count;
  return *this;
}

/* Checks to see if a string is equal to a Word. */
bool operator == (char * a, const Word & b) {
  if(a==NULL) return false;
  return strcmp(a,b.wd) == 0;
}

/* checks to see if a character is equal to a Word. */
bool operator == (char a, const Word & b) {
  char temp[] = {a, '\0'}; 
  return strcmp(temp,b.wd) == 0;
}

/* Checks if to words are not equal. */
bool Word::operator != (const Word &b) const {
  return strcmp(b.wd, wd) != 0;
}

/* checks to see if string and Word are not equal. */
bool operator != (char * a, const Word &b) {
  if(a == NULL) return true;
  return strcmp(a, b.wd) != 0;
}

/*Checks to see if char and Word are not equal. */
bool operator != (char a, const Word &b) {
  char temp[] = {a, '\0'};
  return strcmp(temp, b.wd) != 0;
}

/* This operator is used to concatenate two Word objects. */
Word & Word::operator + (const Word &b) {
  for(int i = 0; i < (int)strlen(b.wd); i++)
    add(b.wd[i]);
  return *this;
}

/* Is Word a < Word b? */
bool operator < (const Word &a, const Word &b) {
  //if(a == NULL) return true;
  //if(b == NULL) return false;
  return strcmp(a.wd,b.wd) < 0;
}

/* Is Word a <= Word b? */
bool operator <= (const Word &a, const Word &b) {
  //if(a == NULL) return true;
  return strcmp(a.wd,b.wd) < 0 || strcmp(a.wd,b.wd) == 0;
}

/* Is Word a > Word b? */
bool operator > (const Word &a, const Word &b) {
  //if(a == NULL) return false;
  return strcmp(a.wd,b.wd) > 0;
}

/* Is Word a >= Word b? */
bool operator >= (const Word &a, const Word &b) {
  //if(a == NULL) return false;
  return strcmp(a.wd,b.wd) > 0 ||   strcmp(a.wd,b.wd) == 0;
}

/* Outputs the string to the given ostream object. */
ostream & operator << (ostream &out, const Word &b) {
  out<<b.wd;
  return out;
}
