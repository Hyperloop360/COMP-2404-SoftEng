#include <iostream>
using namespace std;
#include <string>
#include "Date.h"

int main()
{
  Date d1(28, 1, 2013);
  d1.print();

  const Date newYear(1,1);
//  newYear.setDate(2,2,2000);
//  newYear.print();

  cout<< endl << "End of program" << endl;
  return 0;
}

