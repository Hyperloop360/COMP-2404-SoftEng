#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#define MAX_ARR_SIZE 128

class Library
{
  public:
    Library();
    void addBook(Book&);
    void print();

  private:
    Book books[MAX_ARR_SIZE];
    int numBooks;
};

#endif