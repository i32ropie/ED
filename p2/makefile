CPPFLAGS = -g -Wall -Wextra -std=c++11 #-DNDEBUG
OBJECT1 = main1.o
OBJECT2 = main2.o
BIN1 = main1
BIN2 = main2


all: main1 main2
	rm -f $(OBJECT1) $(OBJECT2)

main1: main1.o
	g++ -o main1 $(OBJECT1)

main2: main2.o
	g++ -o main2 $(OBJECT2)

main1.o: main1.cpp
	g++ -c $(CPPFLAGS) main1.cpp

main2.o: main2.cpp main2.hpp
	g++ -c $(CPPFLAGS) main2.cpp

clean:
	rm -f $(OBJECT1) $(BIN1) $(OBJECT2) $(BIN2)
