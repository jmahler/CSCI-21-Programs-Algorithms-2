
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

#input.txt.out.check: main input.txt
#	./main input.txt > input.txt.out.check

input.txt.out: input.txt main
	./main $< > $@

check: test input.txt.out input.txt.out.check
	./test
	# OK if diff shows no differences
	diff input.txt.out input.txt.out.check

clean:
	-rm -f main test
	-rm -f $(OBJECTS)
	-rm -f input.txt.out
