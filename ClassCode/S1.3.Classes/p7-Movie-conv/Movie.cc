#include <iostream>
#include <string>
using namespace std;
#include "Movie.h"

Movie::Movie(string t, string w, int d)
{
  title        = t;
  screenwriter = w;
  duration     = d;
  cout << "-- Movie default ctor:  " << title << endl;
}

Movie::Movie(Movie& oldMovie)
{
  title        = oldMovie.title;
  screenwriter = oldMovie.screenwriter;
  duration     = oldMovie.duration;
  cout << "-- Movie copy ctor:  " << title << endl;
}

Movie::Movie(Book& b)
{
  title        = b.getTitle();
  screenwriter = b.getAuthor();
  duration     = 120;
  cout << "-- Movie conversion ctor:  " << title << endl;
}


Movie::~Movie()
{
  cout << "-- Movie dtor:  " << title << endl;
}

void Movie::print()
{
  cout << "Movie: " << title << " by " << screenwriter << ", " << duration
       << " minutes long" << endl;
}

