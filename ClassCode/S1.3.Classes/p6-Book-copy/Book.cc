#include <iostream>
#include <string>
using namespace std;
#include "Book.h"

Book::Book(int i, string t, string a) {
  id = i;
  title = t;
  author = a;
  cout << "-- default constructor, book id: " << id << endl;
}

Book::Book(const Book &b) {
  id = b.id;
  title = b.title;
  author = b.author;
  cout << "--copy ctor, book id: " << id << endl;
}

Book::~Book() { cout << "-- dtor, book id: " << id << endl; }

void Book::print() { cout << "--Book: " << title << " by " << author << endl; }
