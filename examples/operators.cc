
public class Set {
private:
  bool * present;
  int low;
  int high;
  int size;
public:
  Set(int l = 0, int h = RANGE);
  Set(int l, int h, int c [], int count);
  void print(ostream &out) const;
  Set &add(int num);
  Set &operator += (int num);
  bool operator ==(const Set &s) const;
  bool operator == (int num) const;
  friend bool operator == (int num, const Set &s);
  friend ostream & operator << (ostream &out, const Set &s);
  friend istream & operator >> (istream &in, Set &s);
 
};

Set & Set::operator += (int x) {
  add(x);
  return *this;;
}

bool operator == (Const Set &s) const
