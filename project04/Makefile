
INCLUDE=

OBJECTS = JArray.o
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: main test

doc: *.cpp *.h 
	doxygen  # using Doxyfile 

test: test.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

main: main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

JArray.o: JArray.cpp JArray.h
	$(CC) $(CFLAGS) -c $<

# The check file should be updated and checked manually.
#lab4input.txt.check: main lab4input.txt
#	./main > $@
#lab3input.txt.check: main lab3input.txt
#	./main lab3input.txt > $@

lab4input.txt.out: main lab4input.txt
	./main > $@

lab3input.txt.out: lab3input.txt main
	./main $< > $@

# Run 'check' to run the unit tests and to check for
# differences between the check file (lab4input.txt.check).
check: test lab4input.txt.out lab4input.txt.check lab3input.txt.out lab3input.txt.check
	./test
	# OK if diff shows no differences
	diff lab4input.txt.out lab4input.txt.check
	diff lab3input.txt.out lab3input.txt.check

clean:
	-rm -f main test
	-rm -f $(OBJECTS)
	-rm -fr doc
	-rm -f lab4input.txt.out

