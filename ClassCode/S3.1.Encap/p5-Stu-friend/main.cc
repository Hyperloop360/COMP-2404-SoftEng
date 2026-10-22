#include <iostream>
using namespace std;

#include "Student.h"

void where(Student&);

int main()
{
  Student matilda("100567899", "Matilda", "CS", 9.0f, 123, "Main", "Moncton", "NB");
  Student joe;

  cout << endl << "All students:" << endl;
  matilda.print();
  joe.print();

  matilda.moveTo("Vancouver", "BC");
  joe.moveTo("Iqaluit", "NU");

  cout << endl << "All students:" << endl;
  matilda.print();
  joe.print();

  cout << endl << "Where are the students:" << endl;
  where(matilda);
  where(joe);

  cout << endl << "End of program" << endl;
  return 0;
}

void where(Student& stu)
{
  cout << "Found student in " << stu.homeAddr.city << ", "
       << stu.homeAddr.province << endl;
}


