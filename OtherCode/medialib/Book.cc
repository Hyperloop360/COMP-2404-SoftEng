#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

Book::Book(const char* t, int p) : pages(p) {
    // DYNAMIC allocation: new[] reserves bytes on the HEAP at runtime.
    title = new char[strlen(t) + 1];
    strcpy(title, t);
    cout << "    [Book ctor        \"" << title << "\"]\n";
}

// DEEP COPY: allocate our OWN block and copy the characters.
Book::Book(const Book& other) : pages(other.pages) {
    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);
    cout << "    [Book COPY ctor   \"" << title << "\"]\n";
}

Book::~Book() {
    cout << "    [Book dtor        \"" << title << "\"]\n";
    delete[] title;                 // new[] pairs with delete[]
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {           // guard against self-assignment (b = b)
        delete[] title;             // free OLD block first -> no leak
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        pages = other.pages;
    }
    return *this;
}

const char* Book::getTitle() const { return title; }
int         Book::getPages() const { return pages; }
