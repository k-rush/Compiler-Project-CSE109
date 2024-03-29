/*
  Kyle Rush
  CSE109
  Program: p7

  This file was given to us to test our Lex class.
*/

#include "lex.h"
#include <fstream>
using namespace std;

int main(){
  ifstream fin,fin1;
  int tok,pos;
  Lex x;

  cout<< "-------------Loading Keyword and Symbols Tree------------------------\n";
  fin.open("data");
  char fail[] = "failure to open file data";
  check(fin.good(),fail);
  x.loadKeyWords(fin);
  fin.close();
  fin1.open("symbols");
  check(fin1.good(),fail);
  x.loadSymbols(fin1);


  cout<< "-------------Checking Keywords------------------------\n";
  x.setString("DIM x");
  tok=x.next();
  cout<<"Expect 'DIM' 6: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Expect 'x' 1: '"<<x.word()<<"' "<<tok<<"\n";


  cout<< "-------------Checking Reset------------------------\n";
  x.reset();
  tok=x.next();
  cout<<"Again, expect 'DIM' 6: '"<<x.word()<<"' "<<tok<<"\n";

  cout<< "-------------Checking Position------------------------\n";
  pos=x.position();
  cout << "Expect 3: " << pos << "\n";

  cout<< "-------------Checking Peek------------------------\n";
  tok = x.peek();  //should have 'jump'
  cout << "Testing Peek Token is: " << tok << endl;
  cout<<"Should have 'DIM': '"<<x.word()<<"'\n";
  x.next();
  cout<<"Should have 'x': '"<<x.word()<<"'\n";
  
  cout<< "-------------Checking junk and $------------------------\n";
  x.setString("JUMP END IF end");
  tok=x.next();
  cout<<"Expect 'JUMP' 19: '"<<x.word()<<"' "<<tok<<"\n";
  x.next();
  tok=x.next();
  cout<<"Expect 'IF' 30: '"<<x.word()<<"' "<<tok<<"\n";
  tok=x.next();
  cout<<"Expect 'end' 1: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Expect '$' 27: '"<<x.word()<<"' "<<tok<<"\n";

  
  cout<< "-------------Testing decimal place------------------------\n";
  x.setString("204.. .0 204.");
  x.next();
  cout << "Should have '204': '" << x.word()<< "' " << x.word().asDouble() <<"\n";
  x.next();
  cout << "Should have '.': '" << x.word()<< "'\n";
  x.next();
  cout << "Should have '.': '" << x.word()<< "'\n";
  x.next();
  cout << "Should have '.': '" << x.word()<< "'\n";
  x.next();
  cout << "Should have '0': '" << x.word()<< "' " << x.word().asDouble() <<"\n";
  x.next();
  cout << "Should have '204': '" << x.word()<< "' " << x.word().asDouble() <<"\n";


  
  cout << "--------------------Testing Symbols---------------------------- " << endl;
  x.setString("IF num > 30");
  tok = x.next();
  cout<<"Expect 'IF' 30: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Expect 'num' 1: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Expect '>' 56: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Expect '30' 30: '"<<x.word()<<"' "<<x.word().asInt()<<"\n";  
  x.setString("IF num >= 5678");
  tok = x.next();
  cout<<"Again, Expect 'IF' 30: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Again, Expect 'num' 1: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Expect '>=' 58: '"<<x.word()<<"' "<<tok<<"\n";
  tok = x.next();
  cout<<"Expect '5678' 5678: '"<<x.word()<<"' "<<x.word().asInt()<<"\n";
  
}

