OBJ = main.o Control.o View.o Telco.o SubArray.o MsgList.o Msg.o ExternMsg.o InternMsg.o Subscriber.o Date.o Time.o
CXXFLAGS = -std=c++11 -Wall

a3: $(OBJ)
	g++ $(CXXFLAGS) -o a3 $(OBJ)

main.o: main.cc defs.h Control.h
	g++ $(CXXFLAGS) -c main.cc

Control.o: Control.cc Control.h View.h Telco.h defs.h
	g++ $(CXXFLAGS) -c Control.cc

View.o: View.cc View.h defs.h
	g++ $(CXXFLAGS) -c View.cc

Telco.o: Telco.cc Telco.h SubArray.h MsgList.h Msg.h InternMsg.h ExternMsg.h defs.h
	g++ $(CXXFLAGS) -c Telco.cc

SubArray.o: SubArray.cc SubArray.h Subscriber.h defs.h
	g++ $(CXXFLAGS) -c SubArray.cc

MsgList.o: MsgList.cc MsgList.h Msg.h defs.h
	g++ $(CXXFLAGS) -c MsgList.cc

Msg.o: Msg.cc Msg.h Date.h Time.h defs.h
	g++ $(CXXFLAGS) -c Msg.cc

ExternMsg.o: ExternMsg.cc ExternMsg.h Msg.h
	g++ $(CXXFLAGS) -c ExternMsg.cc

InternMsg.o: InternMsg.cc InternMsg.h Msg.h Subscriber.h
	g++ $(CXXFLAGS) -c InternMsg.cc

Subscriber.o: Subscriber.cc Subscriber.h defs.h
	g++ $(CXXFLAGS) -c Subscriber.cc

Date.o: Date.cc Date.h defs.h
	g++ $(CXXFLAGS) -c Date.cc

Time.o: Time.cc Time.h defs.h
	g++ $(CXXFLAGS) -c Time.cc

clean:
	rm -f $(OBJ) a3
