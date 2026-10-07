TARGETS = p1
all: $(TARGETS)

p1:		main.o Date.o Array.o
			g++ -o p1 main.o Date.o Array.o

main.o: main.cc Date.h Array.h
			g++ -c main.cc

Date.o: Date.cc Date.h
			g++ -c Date.cc

Array.o: Array.cc Array.h Date.h
			g++ -c Array.cc

clean: 
		rm -f *.o p1
