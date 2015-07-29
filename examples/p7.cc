int main() {
  ifstream fin;
  int toke;
  Lex x;
  fin.open("data");
  //check
  x.loadKeyWords(fin);
  
  
