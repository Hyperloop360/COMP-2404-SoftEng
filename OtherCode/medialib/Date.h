// ============================================================
// Date.h  --  CLASS HEADER FILE
// Goes in a header:  the class DEFINITION = data member declarations
//                    + member function PROTOTYPES (never the code).
// Goes in Date.cc:   member function IMPLEMENTATIONS and
//                    static data member initialization.
// ============================================================

// INCLUDE GUARDS: if two files include this header (directly or
// indirectly) into the same compilation unit, the class would be
// defined twice -> compile error. The guard makes the 2nd include empty.
#ifndef DATE_H
#define DATE_H

class Date {
  // CLASS INTERFACE = class name + its PUBLIC members.
  // This is all a "class user" needs to know to use Date.
  public:
    // DEFAULT ARGUMENTS live in the PROTOTYPE (not the implementation).
    // Defaulted parameters must be right-most. Because EVERY parameter
    // has a default, this one constructor is ALSO the default
    // constructor (callable with no arguments). Only one default ctor
    // per class is allowed, so we don't write a separate Date().
    Date(int d = 1, int m = 1, int y = 2000);

    // DESTRUCTOR: no parameters, never called explicitly, runs
    // automatically when the object dies. Date owns no heap memory so
    // it has nothing to clean up; we only print a trace message.
    ~Date();

    // const member functions promise not to modify the object
    int  getDay()   const;
    int  getMonth() const;
    int  getYear()  const;
    void print()    const;

    // static data member: ONE copy shared by all Date objects.
    // Declared here, INITIALIZED in Date.cc. Used to detect leaks.
    static int liveCount;

  // ACCESS SPECIFIERS: public / protected / private.
  //  public    : visible to everyone
  //  protected : visible to sub-classes only (only matters with inheritance)
  //  private   : visible only inside the class (default for 'class')
  // Principle of least privilege: make members as private as possible.
  private:
    int day;
    int month;
    int year;
};

#endif
