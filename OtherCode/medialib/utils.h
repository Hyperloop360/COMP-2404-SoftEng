// utils.h -- GLOBAL FUNCTIONS (not members of any class).
// Each line below is a function DECLARATION (prototype): it tells the
// compiler the name, parameter types and return type so that other
// files can CALL the function. The IMPLEMENTATION (body) is in utils.cc.
#ifndef UTILS_H
#define UTILS_H
#include "Date.h"
#include "Book.h"

// ---- Types of parameters (nothing to do with I/O!) -----------------
// INPUT parameter        : value flows INTO the function, not modified
// OUTPUT parameter       : function writes a result OUT to the caller
// INPUT-OUTPUT parameter : passed in, modified, visible to caller after
//
// ---- Parameter-passing mechanisms ----------------------------------
// by value     : function gets a COPY (caller's variable is safe)
// by reference : function gets an alias (int&)
// by pointer   : function gets the ADDRESS (int*)

int  square(int n);                          // n: input (by value)
void doubleByRef(int n, int& result);        // n: input, result: OUTPUT (ref)
void doubleByPtr(int n, int* result);        // n: input, result: OUTPUT (ptr)
void increment(int& x);                      // x: INPUT-OUTPUT (ref)
void swapByValue(int a, int b);              // BROKEN on purpose: swaps copies
void swapByPtr(int* a, int* b);              // works: pointers

void printBookByValue(Book b);               // triggers COPY constructor
void printBookByRef(const Book& b);          // no copy; const = input only

// Pointer passed BY REFERENCE using a DOUBLE pointer:
// the helper allocates, and the CALLER's pointer gets updated.
void allocateDate(int d, int m, int y, Date** out);

#endif
