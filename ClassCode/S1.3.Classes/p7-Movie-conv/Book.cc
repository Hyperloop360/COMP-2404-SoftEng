#include <iostream>
#include <string>
using namespace std;
#include "Book.h"

Book::Book(int i, string t, string a)
{
  id     = i;
  title  = t;
  author = a;
  cout << "-- Book default ctor:  " << id << endl;
}

Book::Book(const Book& oldBook)
{
  id     = oldBook.id;
  title  = oldBook.title;
  author = oldBook.author;
  cout << "-- Book copy ctor:  " << id << endl;
}

Book::~Book()
{
  cout << "-- Book dtor:  " << id << endl;
}

string Book::getAuthor() { return author; }
string Book::getTitle() { return title; }

void Book::print()
{
  cout << "Book:  " << title << " by " << author << endl;
}

