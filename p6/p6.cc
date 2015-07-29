#include "pointerTemp.t"
#include "word.h"
int main(){
  Link<Word,int> list;
  list["CAT"] =150;
  list["DOG"] =200;
  list["BIRD"]=300;
  list["SNAKE"]=500;
  list["DOG"] = 400;
  list["SNAKE"] = 600;
  Link<Word,int> copyList(list);
  copyList["BEAR"]= 50;
  cout << list << endl;
  cout << list.inList("CAT");
  cout << list["CAT"] << endl;
  cout << copyList << endl;
}

    
