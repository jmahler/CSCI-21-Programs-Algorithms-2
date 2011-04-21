
INCLUDES=DLNode.h DLList.h DataThing.h

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

input.txt.out: input.txt main
	./main $< > $@

check: input.txt.out
	./test
	# OK if diff shows no differences
	diff input.txt.out input.txt.out.check

clean:
	-rm -f main
	-rm -f test
	-rm -f $(OBJECTS)


