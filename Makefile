
INCLUDE=

OBJECTS=Customer.o Queue.o
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: main test $(OBJECTS)

doc: *.cpp *.h 
	doxygen  # using Doxyfile 

test: test.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

main: main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f main
	-rm -f test
	-rm -f $(OBJECTS)
