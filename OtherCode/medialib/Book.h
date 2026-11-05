// Book.h -- a class that OWNS HEAP MEMORY (the title).
// That is exactly the situation where you must write your own
// destructor, copy constructor and assignment operator.
#ifndef BOOK_H
#define BOOK_H

class Book {
  public:
    // default ctor + multi-parameter ctor combined via default arguments
    Book(const char* title = "Untitled", int pages = 0);

    // COPY CONSTRUCTOR: ONE parameter, a REFERENCE to an object of the
    // same class (not by value -- that would recurse forever; not a pointer).
    // If we don't write one, the compiler supplies a member-wise (SHALLOW)
    // copy, which would copy the title POINTER, not the characters.
    Book(const Book& other);

    // Destructor: releases the heap memory we allocated in the ctors.
    // The compiler can't know this is needed -- we must write it.
    ~Book();

    // Assignment operator (preview of a later topic): assignment copies
    // into an EXISTING object; no constructor runs. Default = shallow.
    Book& operator=(const Book& other);

    const char* getTitle() const;
    int         getPages() const;

  private:
    char* title;   // pointer data member -> needs a DEEP copy
    int   pages;
};

#endif
