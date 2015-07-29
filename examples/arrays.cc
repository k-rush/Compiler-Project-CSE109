#include <iostream>
using namespace std;

void test(int &a, int b);
void test2(int ar[][2], int size);
int main() {
  const int arraysize = 3;
  int num[arraysize];
  num[0] = 100;
  num[1] = 65;
  num[2] = 75;
  int number = 12;
  int number1 = 45;
  cout<< number << " " << number1 << endl;
  test(number, number1);

  cout << number << " " << number1 << endl;
  return 1;
}

void test(int &a, int b) {
  a = 25;
  b = 35;
}
void test2(int ar[][2], int size){
  ar[0][1] = 50;
}

