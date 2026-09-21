p2: file1.o file2.o
	g++ -o p2 file1.o file2.o

file1.o: file1.cc
	g++ -c file1.cc

file2.o: file2.cc
	g++ -c file2.cc

clean: 
	rm *.o p2
