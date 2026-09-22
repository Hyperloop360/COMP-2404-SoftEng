t01:	main.o init.o process.o random.o
	g++ -o t01 main.o init.o process.o random.o

main.o:	main.cc 
	g++ -c main.cc

init.o: init.cc
	g++ -c init.cc

process.o: process.cc
	g++ -c process.cc

random.o:	random.cc
	g++ -c random.cc

clean:
	rm -f *.o t01
