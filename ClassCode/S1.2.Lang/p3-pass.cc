#include <iostream>
using namespace std;

bool checkNum(int);
void doubleNum(int, int &);

int main() {
  bool input0k = false;
  int num, result;

  while (!input0k) {
    cout << "Please enter a number between 0 and 100: ";
    cin >> num;
    input0k = checkNum(num);
  }

  doubleNum(num, result);

  cout << "Result is " << result << endl;

  return 0;
}

void doubleNum(int n, int &res) { res = n * 2; }

bool checkNum(int n) { return (n >= 0 && n <= 100); }
