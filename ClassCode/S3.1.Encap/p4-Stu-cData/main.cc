#include <iostream>
using namespace std;

#include "Student.h"


int main()
{
  Student matilda("100567899", "Matilda", "CS", 9.0f);
  Student joe;

  matilda.print();
  joe.print();

  return 0;
}

