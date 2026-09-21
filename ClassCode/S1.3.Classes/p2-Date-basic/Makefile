p2: main.o Date.o
	g++ -o p2 main.o Date.o

main.o: main.cc Date.h
	g++ -Wall -c main.cc

Date.o: Date.cc Date.h
	g++ -Wall -c Date.cc

clean: 
	rm -f *.o p2
