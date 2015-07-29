/* Kyle Rush
   CSE109
   p5
   this file is used to test the word class.
*/
#include "word.h"
using namespace std;

int main(){
  cout<<"---------Start testWord()-----------------------------\n";
  Word a,b("one"), c(b), d('x'),e("pqrst"),f(100);
  char *temp;
  cout<<"Expect: ' one one x 100'\n        ";
  cout<<"'"<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<f<<"'\n";
  a=b;
  b='y';
  c="two";
  cout<<"Expect: 'oneytwo'\n        ";
  cout<<"'"<<a<<b<<c<<"'\n";
  e[2]='S';
  cout<<"Expect: 'pqSstt'\n        '"<<e<<e[4]<<"'\n";
  temp=a.getStr();
  temp[0]='H';
  cout<<"Expect: 'one Hne' \n        '"<<a<<" "<<temp<<"'\n";
  delete [] temp;
  e.add('!').add('!').add('!').add('!').add('!').add('!').add('!');
  cout<<"'"<<e<<"' has "<<e.length()<<" letters\n";
  
  cout<<"Expect: 'pqSst!!!!!!!'\n        '"<<e<<"'\n";
  e + b + a;
  cout <<"'" << e <<"' has " << e.length()<<" letters\n";
  cout<<"Expect: 'pqSst!!!!!!!yone'\n        '"<<e<<"'\n";
  b + 'Z' + "Why not a string";
  cout <<"'" << b <<"' has " << b.length()<<" letters\n";
  cout<<"Expect: 'yZWhy not a string'\n        '"<<b<<"'\n";
  cout<<"Expect: 010110\n        ";
  cout<<(a<a)<<(a<=a)<<(a>a)<<(a>=a)<<(a==a)<<(a!=a)<<endl;
  cout<<"Expect: 010110\n        ";
  cout<<(a<"one")<<(a<="one")<<(a>"one")<<(a>="one")<<(a=="one")
      <<(a!="one")<<endl;
  cout<<"Expect: 010110\n        ";
  cout<<("one"<a)<<("one"<=a)<<("one">a)<<("one">=a)<<("one"==a)
      <<("one"!=a)<<endl;
  cout<<"Expect: 001101\n        ";
  cout<<(a<'a')<<(a<='a')<<(a>'a')<<(a>='a')<<(a=='a')<<(a!='a')<<endl;
  cout<<"Expect: 110001\n        ";
  cout<<('a'<a)<<('a'<=a)<<('a'>a)<<('a'>=a)<<('a'==a)<<('a'!=a)<<endl;
  temp=NULL;
  cout<<"Expect: 110001 \n        ";
  cout<<(temp<a)<<(temp<=a)<<(temp>a)<<(temp>=a)<<(temp==a)<<(temp!=a)<<endl;
  cout<<"Expect 100: "<<Word("100").asInt()<<endl;
  cout<<"Expect 101.23: "<<Word("101.23").asDouble()<<endl;
  cout<<"Enter a line of text: ";
  e.setDelimiters("\n");
  cin>>e;
  cout<<"You entered: '"<<e<<"'\n";
  cerr<<"Expect crash (non double): \n";
  cout<<Word().asDouble()<<endl;
} 


#define OUTPUT
#ifndef OUTPUT
/*---------Start testWord()-----------------------------
Expect: ' one one x 100'
        ' one one x 100'
Expect: 'oneytwo'
        'oneytwo'
Expect: 'pqSstt'
        'pqSstt'
Expect: 'one Hne' 
        'one Hne'
'pqSst!!!!!!!' has 12 letters
Expect: 'pqSst!!!!!!!'
        'pqSst!!!!!!!'
'pqSst!!!!!!!yone' has 16 letters
Expect: 'pqSst!!!!!!!yone'
        'pqSst!!!!!!!yone'
'yZWhy not a string' has 18 letters
Expect: 'yZWhy not a string'
	'yZWhy not a string'	 
Expect: 010110
        010110
Expect: 010110
        010110
Expect: 010110
        010110
Expect: 001101
        001101
Expect: 110001
        110001
Expect: 110001 
        110001
Expect 100: 100
Expect 101.23: 101.23
Enter a line of text: enter a string of chars
You entered: 'enter a string of chars'
Expect crash (non double): 
ERROR: (Word::asDouble()) String is not a double

END OUT OUTPUT */
#endif

