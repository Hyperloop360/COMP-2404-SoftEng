#include <iostream>
#include <string>
using namespace std;

#include "Book.h"
#include "Movie.h"


void func(Movie);


int main()
{
  Book b1(1, "Ender's Game", "Orson Scott Card");
  Book b2(2, "Dune", "Frank Herbert");
  Book b3(3, "Foundation", "Isaac Asimov");
  Book b4(4, "Hitch Hiker's Guide to the Galaxy", "Douglas Adams");

  cout << endl << "Declaring and initializing movie..." << endl;
  Movie m1("Sherlock Holmes", "Johnson et al.", 128);

  cout << endl << "Printing movie..." << endl;
  m1.print();

  cout << endl << "Explicit call to conversion constructor movie from book..." << endl;
  Movie m2(b2);
  m2.print();

  cout << endl << "Declaring and initializing movie from book..." << endl;
  Movie m3 = b3;


  cout << endl << "Calling func()..." << endl;
  func(b1);


  cout << endl << "End of program" << endl;

  return 0;
}

void func(Movie m)
{
  m.print();
}

