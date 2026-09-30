#include <iostream>
#include <string>
using namespace std;

#include "Book.h"

void func1(Book);
void func2(Book &);

int main() {
  cout << "Declaring and initializing books 1 to 4..." << endl;

  Book b1(1, "Ender's Game", "Orson Scott Card");
  Book b2(2, "Dune", "Frank Herbert");
  Book b3(3, "Foundation", "Isaac Asimov");
  Book b4(4, "Hitch Hiker's Guide to the Galaxy", "Douglas Adams");

  cout << endl << "Printing all books:" << endl;
  b1.print();
  b2.print();
  b3.print();
  b4.print();

  cout << endl << "Declaring book 5" << endl;
  Book b5;
  b5.print();

  cout << endl << "Assigning book 4 to 5" << endl;
  b5 = b4;
  b5.print();

  cout << endl << "Explicit call to copy ctor" << endl;
  Book b6(b2);
  b6.print();

  cout << endl << "Initialzing book 7 from book 3" << endl;
  Book b7 = b3;
  b7.print();

  cout << endl << "Calling func1()" << endl;
  func1(b1);

  cout << endl << "Calling func2()" << endl;
  func2(b2);

  cout << endl;
  return 0;
}

void func1(Book b) { b.print(); }

void func2(Book &b) { b.print(); }
