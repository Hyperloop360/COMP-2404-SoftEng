OPT = -Wall

t02:	main.o Book.o Library.o
	g++ $(OPT) -o t02 main.o Book.o Library.o

main.o:	main.cc Book.h Library.h
	g++ $(OPT) -c main.cc 

Library.o: Library.cc Library.h Book.h
	g++ $(OPT) -c Library.cc

Book.o:	Book.cc Book.h Library.h
	g++ $(OPT) -c Book.cc

clean:
	rm -f *.o t02
