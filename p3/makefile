CPPFLAGS = -g -Wall -Wextra -std=c++11 -c #-DNDEBUG
OBJECT = main.o
BIN = main


all: main
	rm -f $(OBJECT)

main: main.o
	g++ -o $(BIN) $(OBJECT)

main2.o: main.cpp main.hpp donante.hpp boundedminheap.hpp
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f $(OBJECT) $(BIN)
