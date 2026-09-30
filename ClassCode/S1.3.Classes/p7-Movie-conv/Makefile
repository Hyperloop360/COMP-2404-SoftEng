p7:	main.o Book.o Movie.o
	g++ -o p7 main.o Book.o Movie.o

main.o:	main.cc Book.h
	g++ -c main.cc

Book.o:	Book.cc Book.h
	g++ -c Book.cc

Movie.o:	Movie.cc Movie.h
	g++ -c Movie.cc

clean:
	rm -f *.o p7
