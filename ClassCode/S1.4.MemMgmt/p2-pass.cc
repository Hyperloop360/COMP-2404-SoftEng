#include <iostream>
using namespace std;

bool checkNum(int);
void doubleNum(int, int &);
void doubleNum(int, int *);

int main() {
  bool inputOk = false;
  int num, result1, result2;

  while (!inputOk) {
    cout << "Please enter a number between 0 and 100: ";
    cin >> num;
    inputOk = checkNum(num);
  }

  doubleNum(num, result1);
  cout << "Result 1: " << result1 << endl;

  doubleNum(num, &result2);
  cout << "Result 2" << result2 << endl;

  return 0;
}

void doubleNum(int n, int *res) {
  cout << "inside pass-by-reference by pointer" << endl;
  *res = n * 2;
}

bool checkNum(int n) { return (n >= 0 && n <= 100); }
