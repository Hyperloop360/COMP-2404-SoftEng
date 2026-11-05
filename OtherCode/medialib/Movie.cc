#include <iostream>
#include <cstring>
#include "Movie.h"
using namespace std;

Movie::Movie(int m) : minutes(m) {
    strcpy(title, "(untitled movie)");
    cout << "    [Movie conversion ctor from int " << m << "]\n";
}

Movie::Movie(const Book& b) : minutes(b.getPages() / 3) {  // ~3 pages/min
    strncpy(title, b.getTitle(), sizeof(title) - 1);
    title[sizeof(title) - 1] = '\0';
    cout << "    [Movie conversion ctor from Book \"" << title << "\"]\n";
}

Movie::~Movie() { cout << "    [Movie dtor       \"" << title << "\"]\n"; }

const char* Movie::getTitle()   const { return title; }
int         Movie::getMinutes() const { return minutes; }
