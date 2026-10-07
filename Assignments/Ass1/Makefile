bank: main.o Bank.o Customer.o Account.o Transaction.o Date.o
	g++ -std=c++11 -Wall -o bank main.o Bank.o Customer.o Account.o Transaction.o Date.o

main.o: main.cc defs.h Bank.h
	g++ -std=c++11 -Wall -c main.cc

Bank.o: Bank.cc Bank.h Customer.h Transaction.h Account.h defs.h
	g++ -std=c++11 -Wall -c Bank.cc

Customer.o: Customer.cc Customer.h Account.h defs.h
	g++ -std=c++11 -Wall -c Customer.cc

Account.o: Account.cc Account.h
	g++ -std=c++11 -Wall -c Account.cc

Transaction.o: Transaction.cc Transaction.h Date.h Account.h defs.h
	g++ -std=c++11 -Wall -c Transaction.cc

Date.o: Date.cc Date.h
	g++ -std=c++11 -Wall -c Date.cc

clean:
	rm -f *.o bank
