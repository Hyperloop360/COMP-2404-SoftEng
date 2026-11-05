#include <iostream>
#include "utils.h"
using namespace std;

int square(int n) { return n * n; }   // good design: returns one result

void doubleByRef(int n, int& result) { result = n * 2; }

void doubleByPtr(int n, int* result) {
    if (result == NULL) return;       // always check pointers before '*'
    *result = n * 2;                  // '*' = dereference
}

void increment(int& x) { x = x + 1; }

void swapByValue(int a, int b) { int t = a; a = b; b = t; }   // no effect!

void swapByPtr(int* a, int* b) {
    if (a == NULL || b == NULL) return;
    int t = *a; *a = *b; *b = t;
}

void printBookByValue(Book b) {       // 'b' is a COPY (copy ctor ran)
    cout << "    by value: \"" << b.getTitle() << "\"\n";
}                                      // copy's destructor runs here

void printBookByRef(const Book& b) {  // 'b' is an alias, nothing copied
    cout << "    by ref  : \"" << b.getTitle() << "\"\n";
}

// If 'out' were only a Date*, the helper would update its OWN local copy
// of the pointer and the caller would never see it (and the heap block
// would leak). Date** lets us write into the caller's pointer variable.
void allocateDate(int d, int m, int y, Date** out) {
    *out = new Date(d, m, y);
}
