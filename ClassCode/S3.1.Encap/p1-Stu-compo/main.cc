#include <iostream>
using namespace std;

#include "Student.h"

int main() {
  cout << "Declaring matilda:" << endl;
  Student matilda("100567899", "Matilda", "CS", 9.0f, 123, "Main", "Moncton",
                  "NB");
  cout << endl;

  cout << "Declaring joe:" << endl;
  Student joe;
  cout << endl;

  cout << "Printing students:" << endl;
  matilda.print();
  joe.print();

  cout << endl << "End of program" << endl;

  return 0;
}
