
INCLUDES=DLNode.h DLList.h

OBJECTS=

CC=g++
CFLAGS=-Wall -ansi -pedantic

all: main test $(OBJECTS)

doc: *.cpp *.h 
	doxygen  # using Doxyfile 

test: test.cpp $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $< $(OBJECTS) -o $@

main: main.cpp $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $< $(OBJECTS) -o $@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f main
	-rm -f test
	-rm -f $(OBJECTS)

