# ============================================================
# Makefile  --  PROGRAM BUILDING IN LINUX
# ------------------------------------------------------------
# Manual equivalent of what this file automates:
#   g++ -c Date.cc            -> Date.o      (COMPILE: .cc -> object code)
#   g++ -c Book.cc            -> Book.o
#   ...
#   g++ -o medialib *.o       (LINK: object code -> ONE executable)
#
# Single-file case (no Makefile needed):
#   g++ -o hello hello.cc     (compile + link in one command)
#
# A Makefile is a rule list:  target: dependencies
#                                 <TAB> command
# make only rebuilds targets whose dependencies changed, e.g. editing
# Book.cc recompiles ONLY Book.o and then re-links.
# ============================================================

CXX      = g++
CXXFLAGS = -Wall -Wextra -g

OBJS = main.o Date.o Book.o Movie.o utils.o

# LINK step: input = many .o files, output = one executable
medialib: $(OBJS)
	$(CXX) $(CXXFLAGS) -o medialib $(OBJS)

# COMPILE steps: -c produces object code only (1 source file -> 1 .o file).
# Each .o depends on its .cc AND on every header it #includes.
main.o:  main.cc  Date.h Book.h Movie.h utils.h
	$(CXX) $(CXXFLAGS) -c main.cc
Date.o:  Date.cc  Date.h
	$(CXX) $(CXXFLAGS) -c Date.cc
Book.o:  Book.cc  Book.h
	$(CXX) $(CXXFLAGS) -c Book.cc
Movie.o: Movie.cc Movie.h Book.h
	$(CXX) $(CXXFLAGS) -c Movie.cc
utils.o: utils.cc utils.h Date.h Book.h
	$(CXX) $(CXXFLAGS) -c utils.cc

# Memory-leak check (slide: "use the valgrind utility in Linux")
valgrind: medialib
	valgrind --leak-check=full ./medialib

clean:
	rm -f *.o medialib

.PHONY: clean valgrind
