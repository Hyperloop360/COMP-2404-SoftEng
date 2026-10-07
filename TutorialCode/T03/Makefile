t03:	main.o Movie.o MovieGroup.o 
	g++ -o t03 main.o Movie.o MovieGroup.o

main.o:	main.cc Movie.h MovieGroup.h
	g++ -c main.cc

Movie.o:	Movie.cc Movie.h 
	g++ -c Movie.cc

MovieGroup.o:	MovieGroup.cc MovieGroup.h Movie.h
	g++ -c MovieGroup.cc

clean:
	rm -f *.o t03
