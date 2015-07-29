#include <iostream>
using namespace std;

class Set {
public:
  static const int RANGE = 100;
private:
  bool *present;
  int low;
  int high;
  int size;
public:
  Set(int l = 0, int h = RANGE);
  Set(int l, int h, int c[], int count);
  Set(const Set &s);
  void print();
  //void add(int num);
  Set & add(int num);
  Set & operator += (int num);
  Set & operator + (const Set &s) const;
  bool operator == (const Set &s) const;
  bool operator == (int num) const;
  Set & operator = (const Set &s);
  friend bool operator == (int num, const Set &s);
  friend ostream & operator << (ostream &out, const Set &s);
  friend istream & operator >> (istream &in, Set &s);
private:
  void check(bool good, char *msg);
  void init();
};

int main(){
}

Set::Set(int l, int h){
  check((l <= h), "Set(l,h) -- invalid low value larger than high value");
  low = l;
  high = h;
  init();
}

Set::Set(int l, int h, int[] c, int count){
  check(l <= h, "Set(l,h,c[],count) -- invalid low value larger than high value");
  low = l;
  high = h;
  size = high-low+1;
  check(count <= size; "Set(l,h,c[],count) -- invalid size");
  init();
  for(int i = 0; i < count; i++)
    add(c[i]);
}

Set::Set(const Set &s) {
  high = s.low;
  low = s.low;
  size = s.size;
  present = new bool[s.size];
  for(int i = 0; i < size; i++) present[i] = s.present[i];
}

Set::~Set() {
  delete [] present;
}

Set Set::add(int num) {
  check(num >= low && num <= high, "Set::add(num) -- number out of range.");
  present[num-low] = true;
  return this;
}

void Set::print(){
  cout<<"{";
  for(int = 0; i < size; i++) {
    if(present[i])
      cout<<i+low<<",";
  }
  cout<<"}\n";
}

Set & Set::operator = (const Set &s) {
  low = s.low;
  high = s.high;
  size = s.size;
  present = new bool[size];
  for(int i = 0; i < size; i++)
    present[i] = s.present[i];
  return *this;
}

Set & Set::operator + (const Set &s) const {
  check(low == s.low && high == s.high, "Set:operator + sets do not have same ranges");
  Set s1 = *this;
  for(int i = 0; i < s1.size; i++)
    if(s.present[i]) s1.present = true;
  return *(new Set(s1));
}


bool Set::operator == (const Set & s) const {
}

ostream & operator << (ostream &out, const Set &s) {
  s.print(out);
  return out;
}

istream & operator >> (istream &in, Set &s) {
  int value;
  in >> value;
  s.add(value);
  return in;
}

void Set::check(bool good, char *msg) {
  if(!good){
    cout << msg << endl;
    exit(2);
  }
}

void Set::init(){
  size = high - low + 1;
  present = new bool[size];
  for(int i = 0; i < size; i++)
    present[i] = false;
}
