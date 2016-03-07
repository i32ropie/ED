CPPFLAGS = -g -Wall -std=c++11 -DNDEBUG
OBJECT1 = main1.o
OBJECT2 = main2.o
BIN1 = main1
BIN2 = main2


all: main1 main2

main1: main1.o monomio.hpp
	g++ -o main1 $(OBJECT1)

main2: main2.o monomio.hpp polinomio.hpp
	g++ -o main2 $(OBJECT2)

main1.o: main1.cpp
	g++ -c $(CPPFLAGS) main1.cpp

main2.o: main2.cpp
	g++ -c $(CPPFLAGS) main2.cpp

clean:
	rm -f $(OBJECT1) $(OBJECT2) $(BIN1) $(BIN2)
