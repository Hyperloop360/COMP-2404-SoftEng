#include <iostream>
using namespace std;

#include "Movie.h"

Movie::Movie(string t, int y)
{
  title = t;
  year  = y;
}

Movie::Movie(Movie &m)
{
  cout << "Copy Constructor called for " << m.title << endl;

  title = m.title;
  year  = m.year;
}

Movie::~Movie() { }

int  Movie::getYear() { return year; }

void Movie::print()
{
  cout<<"** Year:  " << year << "   Title: " << title << endl;
}

