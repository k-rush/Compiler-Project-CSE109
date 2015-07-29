/*
  Kyle Rush
  CSE109
  6/7/2011
  Assignment: p2
  This program asks the user to input values into
  a 2-dimensional array. The program then sorts the
  array using the bubble sort algorithm.
 */


#include <iostream>
using namespace std;

void bubbleSort(int[], int);

int main() {
  static int ROW = 3;
  static int COL = 5;
  
  int array[ROW][COL];

  
  /* The follwing inputs the array values from the user. */
  cout<<"Please enter values for the array...\n";
  for(int r = 0; r < ROW; r++) {
    for(int c = 0; c < COL; c++) {
      cout << "[" << r << "][" << c << "]: ";
      cin>> array[r][c];
      while(!cin.good()) {
	cout << "Not Valid. Please enter an integer value: ";
	cin.clear();
	cin.sync();
	cin >> array[r][c];
	}
    }
    }
  
  cout<<"\n\nUnsorted Array:\n";
  for(int i = 0; i < ROW; i++) {
    for(int j = 0; j < COL; j++) {
      cout << array[i][j] << "\t";
    }
    cout<<"\n";
  }

  
  for(int i = 0; i < ROW; i++) 
       bubbleSort(array[i], COL);

  
  cout<<"\n\nSorted Array:\n";
  for(int i = 0; i < ROW; i++) {
    for(int j = 0; j < COL; j++) {
      cout << array[i][j] << "\t";
    }
    cout<<"\n";
  }
  return 0;
}


/* Bubble sort algorithm: sorts an array by swapping
   consecutive values if they are out of order.
   It will continue to loop through the list until
   no swaps are performed. */

void bubbleSort(int list[], int length){
  int temp = 0;
  bool swapped = true;
  while(swapped) {
    swapped = false;
    for(int i = 0; i < length-1; i++){
      if(list[i]>list[i+1]) {
	temp = list[i+1];
	list[i+1] = list[i];
	list[i] = temp;
	swapped = true;
      }
    }
  }
}
