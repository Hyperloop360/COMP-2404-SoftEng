#include <iostream>
using namespace std;

#include "Library.h"

Library::Library()
{
    numBooks = 0;
}

void Library::addBook(Book& b)
{
    if (numBooks < MAX_ARR_SIZE)
    {
       books[numBooks].set(b.getId(), b.getTitle(), b.getAuthor(), b.getYear());
        numBooks++;
    }
}

void Library::print()
{
    cout << "/n Library Collection " << endl;
    for (int i = 0; i < numBooks; ++i) {
        books[i].print();
    }
    cout << endl;
}