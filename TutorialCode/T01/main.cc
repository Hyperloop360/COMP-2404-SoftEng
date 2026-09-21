#include <iostream>
#include <cstdlib>
#include "defs.h"

using namespace std;

int main() {
  int arr[MAX_ARR_SIZE];
  srand((unsigned)time(NULL));

  initArray(arr);
  printArray(arr);

  for (int i = 0; i < MAX_ARR_SIZE; ++i) {
    doubleNum(arr[i]);
  }
  printArray(arr);
}

void printArray(int* arr)
{
  for (int i=0; i<MAX_ARR_SIZE; i++)
    cout << arr[i] << " ";
  cout << endl;
}