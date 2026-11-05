# medialib – C++ basics in one small project

Build & run:

    make            # compile each .cc -> .o, then link into ./medialib
    ./medialib
    make valgrind   # leak check
    make clean

One-file build:  `g++ -o hello hello.cc`
Manual multi-file build:  `g++ -c X.cc` for each file, then `g++ -o medialib *.o`

| Concept | Where |
|---|---|
| Compile vs link, Makefile, dependencies | `Makefile` |
| Header vs source, include guards, class interface, access specifiers | `Date.h`, `Date.cc` |
| Default arguments / default ctor, dtor, static member | `Date.*` |
| Deep copy, copy ctor, destructor, operator= | `Book.*` |
| Conversion ctors, `explicit` | `Movie.*` |
| Global functions, declaration vs implementation, input/output/in-out params, by value/ref/pointer, double pointers | `utils.*`, `main.cc` |
| Scope, operators (arity, precedence, associativity), references vs pointers, stack vs heap | `main.cc` sections 2–4 |
| Ctor/dtor order, implicit vs explicit copy, shallow vs deep | `main.cc` section 5 |
| new/delete, leaks, the 4 array kinds | `main.cc` sections 6–7 |
