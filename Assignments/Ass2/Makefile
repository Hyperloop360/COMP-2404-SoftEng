CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

EXEC = telco
OBJS = main.o Date.o Time.o Msg.o MsgArray.o Subscriber.o Telco.o Control.o View.o

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

main.o: main.cc Control.h
	$(CXX) $(CXXFLAGS) -c main.cc

Control.o: Control.cc Control.h Telco.h View.h defs.h
	$(CXX) $(CXXFLAGS) -c Control.cc

Telco.o: Telco.cc Telco.h Subscriber.h MsgArray.h defs.h
	$(CXX) $(CXXFLAGS) -c Telco.cc

Subscriber.o: Subscriber.cc Subscriber.h MsgArray.h Msg.h
	$(CXX) $(CXXFLAGS) -c Subscriber.cc

MsgArray.o: MsgArray.cc MsgArray.h Msg.h
	$(CXX) $(CXXFLAGS) -c MsgArray.cc

Msg.o: Msg.cc Msg.h Date.h Time.h
	$(CXX) $(CXXFLAGS) -c Msg.cc

Date.o: Date.cc Date.h
	$(CXX) $(CXXFLAGS) -c Date.cc

Time.o: Time.cc Time.h
	$(CXX) $(CXXFLAGS) -c Time.cc

clean:
	rm -f *.o $(EXEC)
