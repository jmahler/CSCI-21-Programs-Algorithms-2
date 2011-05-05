
INCLUDE=

OBJECTS=

CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: main test $(OBJECTS)

doc: *.cpp *.h 
	doxygen  # using Doxyfile 

main: main.cpp BSTNode.h BSTree.h
	$(CC) $(CFLAGS) $< -o $@

test: test.cpp BSTNode.h BSTree.h
	$(CC) $(CFLAGS) $< -o $@

#%.o: %.cpp %.h
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f main test
	-rm -f $(OBJECTS)
