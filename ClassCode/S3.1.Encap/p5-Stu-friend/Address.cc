#include <iostream>
using namespace std;
#include <string>

#include "Address.h"


Address::Address(int n, string s, string c, string p) 
    : number(n), street(s), city(c), province(p) 
{ 
  cout << "-- Address ctor:  " << city << ", " << province << endl;
}

Address::~Address()
{
  cout << "-- Address dtor:  " << city << ", " << province << endl;
}

void Address::print() const
{
  cout << "          Address:  " << number << " " << street << ", " 
       << city << ", " << province;
}

