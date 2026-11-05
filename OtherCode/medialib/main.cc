// ============================================================
// main.cc  --  the "CLASS USER". It #includes the HEADERS only; the
// class code arrives at LINK time through the .o files.
// An executable must contain EXACTLY ONE main().
// ============================================================
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Book.h"
#include "Movie.h"
#include "utils.h"
using namespace std;

// ---- GLOBAL SCOPE -------------------------------------------
// Visible to every function below. Constructed before main() starts,
// destroyed after main() ends (in reverse order of construction).
int  g_value = 100;
Date g_releaseDate(1, 1, 1999);

// Function DECLARATION (prototype) vs IMPLEMENTATION (bottom of file):
// the declaration lets us call it before the compiler has seen the body.
void banner(const char* text);

// A tiny struct WITHOUT a copy constructor -> compiler gives a
// member-wise (shallow) copy. Used only to show shallow vs deep.
struct RawNote { char* text; };

// ============================================================
void demoScopeAndOperators() {
    banner("2. STATEMENTS, BLOCKS, SCOPE, OPERATORS");

    int x = 5;                       // a statement ends with ';'
    {                                // a BLOCK { } groups statements
        int x2 = 10;                 // block (local) scope: dies at '}'
        int g_value = 7;             // shadows the global of the same name
        cout << "  inner block: x2=" << x2 << ", local g_value=" << g_value
             << ", global g_value=" << ::g_value << "  (:: = global scope)\n";
    }                                // x2 no longer exists here
    cout << "  outer: x=" << x << ", g_value=" << g_value << "\n";

    // ARITY = number of operands.
    int a = 2, b = 3, c = 4;
    int neg = -a;                    // unary    (1 operand)
    int sum = a + b;                 // binary   (2 operands)
    int pick = (a < b) ? b : c;      // ternary  (3 operands)
    cout << "  arity: -a=" << neg << "  a+b=" << sum << "  (a<b?b:c)=" << pick << "\n";

    // PRECEDENCE: which operator binds first.
    cout << "  precedence: a + b * c   = " << (a + b * c)   << "  (* before +)\n";
    cout << "              (a + b) * c = " << ((a + b) * c) << "  (parens override)\n";

    // ASSOCIATIVITY: order among operators of SAME precedence.
    cout << "  left-assoc : 100 / 10 / 5 = " << (100 / 10 / 5) << "  ((100/10)/5)\n";
    int p, q;
    p = q = 7;                       // '=' is RIGHT-assoc: p = (q = 7)
    cout << "  right-assoc: p = q = 7 -> p=" << p << ", q=" << q << "\n";

    // Same symbol, different roles (see section 5): a * b is BINARY
    // multiply; *ptr is UNARY dereference. & works the same way.
}

// ============================================================
void demoParameters() {
    banner("3. FUNCTIONS & PARAMETER PASSING");

    int n = 21, r1 = 0, r2 = 0;
    cout << "  square(21) by value        = " << square(n) << " (returned)\n";

    doubleByRef(n, r1);              // OUTPUT param via reference
    doubleByPtr(n, &r2);             // OUTPUT param via pointer: pass ADDRESS
    cout << "  doubleByRef -> r1=" << r1 << "   doubleByPtr -> r2=" << r2 << "\n";

    increment(n);                    // INPUT-OUTPUT: n is read AND modified
    cout << "  increment(n) -> n=" << n << "  (input-output param)\n";

    int a = 1, b = 2;
    swapByValue(a, b);
    cout << "  swapByValue : a=" << a << " b=" << b << "  (unchanged: swapped copies)\n";
    swapByPtr(&a, &b);
    cout << "  swapByPtr   : a=" << a << " b=" << b << "  (really swapped)\n";

    // REFERENCES: what they ARE and what they are NOT
    int  v = 10;
    int& ref = v;                    // MUST be initialized at declaration
    ref = 20;                        // changes v; does NOT rebind the ref
    int  w = 99;
    ref = w;                         // copies 99 INTO v; ref still aliases v
    cout << "  reference: v=" << v << " ref=" << ref
         << " same address? " << (&v == &ref ? "yes" : "no") << "\n";
    cout << "  A reference is an alias: no own value, no NULL, can't be\n"
            "  re-pointed, no arithmetic. A pointer is a real variable that\n"
            "  stores an address (can be NULL, reassigned, has its own address).\n";
}

// ============================================================
void demoStackAndPointers() {
    banner("4. STACK vs HEAP, POINTERS");

    // STATIC allocation: size known at compile time -> function call stack
    int stackVar = 42;

    // DYNAMIC allocation: at runtime with new -> HEAP
    int* heapVar = new int(56);

    // POINTER: a variable whose VALUE is a memory address.
    int* p = &stackVar;              // & = address-of operator
    cout << "  stackVar value=" << stackVar << "  address=" << &stackVar << "\n";
    cout << "  p (points to stackVar): value(address)=" << p
         << "  *p=" << *p << "  (* = dereference)\n";
    cout << "  p has its OWN address too: &p=" << &p
         << "  sizeof(p)=" << sizeof(p) << " bytes\n";
    *p = 43;                         // modifies stackVar through pointer
    cout << "  after *p = 43 -> stackVar=" << stackVar << "\n";
    cout << "  heapVar -> " << heapVar << " (note: very different address range)\n";

    // Several pointers may point to one variable; one pointer points to one thing.
    int* p2 = p;
    cout << "  p2 == p ? " << (p2 == p ? "yes" : "no") << "\n";

    int* nothing = NULL;             // dereferencing this would crash
    if (nothing != NULL) cout << *nothing;   // so ALWAYS check first
    cout << "  (skipped *nothing because it is NULL)\n";

    delete heapVar;                  // every new needs a matching delete
    heapVar = NULL;

    // FUNCTION CALL STACK: each call pushes a STACK FRAME (locals,
    // parameters, return address); returning pops it (LIFO).
    // Locals in doubleByRef/square vanished as soon as they returned.
}

// ============================================================
void demoClasses() {
    banner("5. CLASSES: ctor / dtor / copy / conversion");

    cout << "  -- default arguments / default constructor --\n";
    Date d1;                         // all defaults -> 1/1/2000
    Date d2(23, 2);                  // year defaulted
    Date d3(4, 5, 2006);             // none defaulted

    cout << "  -- object declaration (ctor runs) --\n";
    Book original("Moby Dick", 635);

    cout << "  -- copy constructor, EXPLICIT call --\n";
    Book copy1(original);
    cout << "  -- copy constructor, on INITIALIZATION (this is not assignment!) --\n";
    Book copy2 = original;
    cout << "  -- copy constructor, IMPLICIT: pass by value --\n";
    printBookByValue(original);      // a temporary copy is made and destroyed
    cout << "  -- no copy: pass by const reference --\n";
    printBookByRef(original);

    cout << "  -- ASSIGNMENT: both objects already exist, NO ctor runs --\n";
    Book other("Dracula", 418);
    other = original;                // our operator= does a deep copy

    cout << "  -- SHALLOW vs DEEP copy --\n";
    RawNote n1; n1.text = new char[6]; strcpy(n1.text, "hello");
    RawNote n2 = n1;                 // member-wise copy: copies the POINTER
    cout << "  shallow: n1.text=" << (void*)n1.text << " n2.text=" << (void*)n2.text
         << "  -> same block! (deleting both = double free)\n";
    delete[] n1.text;                // free ONCE only
    cout << "  deep   : original=" << (void*)original.getTitle()
         << " copy1=" << (void*)copy1.getTitle() << "  -> separate blocks\n";

    cout << "  -- conversion constructors --\n";
    Movie m1(original);              // EXPLICIT call (Book -> Movie)
    Movie m2 = 120;                  // IMPLICIT call (int -> Movie)
    // Movie m3 = original;          // ERROR: Book ctor is 'explicit'
    cout << "  m1: \"" << m1.getTitle() << "\" " << m1.getMinutes() << " min;  m2: "
         << m2.getMinutes() << " min\n";

    cout << "  -- leaving scope: destructors run, REVERSE order of construction --\n";
}   // locals die here; the compiler inserts the dtor calls

// ============================================================
void demoDynamic() {
    banner("6. DYNAMIC MEMORY, LEAKS, DOUBLE POINTERS");

    cout << "  -- new calls the constructor, delete calls the destructor --\n";
    Date* dp1 = new Date;            // default ctor
    Date* dp2 = new Date(11, 11, 2011);
    dp1->print(); cout << "  "; dp2->print(); cout << "   (-> = deref + member)\n";
    delete dp1;
    delete dp2;

    cout << "  -- MEMORY LEAK: pointer overwritten before delete --\n";
    int* leaky = new int(1);
    // leaky = new int(2);           // LEAK: first block is now unreachable
    delete leaky;                    // correct: free, THEN reassign
    leaky = new int(2);
    delete leaky;
    cout << "  (other leak cause: a local pointer going out of scope\n"
            "   without delete. C++ has no garbage collector; use valgrind.)\n";

    cout << "  -- double pointer: helper allocates into OUR pointer --\n";
    Date* tmp = NULL;
    allocateDate(8, 8, 1988, &tmp);  // pass the ADDRESS of the pointer
    cout << "  tmp now -> "; tmp->print(); cout << "\n";
    delete tmp;
}

// ============================================================
void demoFourArrays() {
    banner("7. THE FOUR KINDS OF ARRAYS");
    const int N = 3;

    cout << "  #1 STATIC array of OBJECTS  (Date a1[3]) -> default ctor x3\n";
    Date a1[N];                              // declare+allocate on stack, ctors auto
    a1[0] = Date(1, 1, 1911);                // elements are real objects: use '.'
    // (Date(...) builds a TEMPORARY that is copied in then destroyed -> the
    //  extra ctor/dtor lines you see; the default copy is member-wise.)
    // no deallocation: destructors run automatically at end of scope

    cout << "  #2 STATIC array of POINTERS (Date* a2[3]) -> NO ctor yet\n";
    Date* a2[N];                             // only 3 pointers exist, no Dates!
    for (int i = 0; i < N; i++) a2[i] = NULL;
    a2[0] = new Date(3, 3, 1933);            // we allocate each object ourselves
    a2[1] = new Date(4, 4, 1944);            // a2[2] stays NULL
    for (int i = 0; i < N; i++)
        if (a2[i] != NULL) { a2[i]->print(); cout << " "; }   // '->' for pointers
    cout << "\n";
    for (int i = 0; i < N; i++) delete a2[i];// delete each object (delete NULL is safe)
    // the pointer array itself is on the stack -> nothing more to free

    cout << "  #3 DYNAMIC array of OBJECTS (Date* a3 = new Date[3])\n";
    Date* a3 = new Date[N];                  // heap; default ctor x3, no args allowed
    a3[1] = Date(6, 6, 1966);
    delete[] a3;                             // delete[] -> dtor x3. Plain delete = bug!

    cout << "  #4 DYNAMIC array of POINTERS (Date** a4 = new Date*[3])\n";
    Date** a4 = new Date*[N];                // heap array of pointers: no ctors
    for (int i = 0; i < N; i++) a4[i] = NULL;
    a4[0] = new Date(7, 7, 1977);
    a4[1] = new Date(8, 8, 1988);
    for (int i = 0; i < N; i++) delete a4[i];// 1) delete every object
    delete[] a4;                             // 2) THEN delete the pointer array

    cout << "  Live Date objects right now (expect 4 = 1 global + a1's 3): "
         << Date::liveCount << "\n";
    cout << "  -- leaving scope: a1's 3 objects are destroyed automatically --\n";
}

// ============================================================
int main() {
    cout << "MEDIALIB  --  C++ basics demo (see README for the concept map)\n";
    banner("1. PROGRAM BUILD: you are running the linked executable");
    cout << "  main.o + Date.o + Book.o + Movie.o + utils.o  ->  medialib\n";

    demoScopeAndOperators();
    demoParameters();
    demoStackAndPointers();
    demoClasses();
    demoDynamic();
    demoFourArrays();

    banner("END (global objects are destroyed AFTER main returns)");
    return 0;
}

void banner(const char* text) {              // implementation of the prototype above
    cout << "\n=== " << text << " ===\n";
}
