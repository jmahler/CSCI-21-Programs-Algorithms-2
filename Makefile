
INCLUDES=DLNode.h DLList.h DataThing.h

OBJECTS=DataThing.o BoolThing.o IntegerThing.o \
		CharThing.o DoubleThing.o StringThing.o

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

README.htm: README.md
	markdown $< > $@


input-int.txt.out: input-int.txt main
	./main $< > $@

input-bool.txt.out: input-bool.txt main
	./main $< > $@

input-char.txt.out: input-char.txt main
	./main $< > $@

input-double.txt.out: input-double.txt main
	./main $< > $@

input-string.txt.out: input-string.txt main
	./main $< > $@

check: test input-int.txt.out input-bool.txt.out input-char.txt.out input-double.txt.out input-string.txt.out
	./test
	# OK if diff shows no differences
	diff input-int.txt.out input-int.txt.out.check
	diff input-bool.txt.out input-bool.txt.out.check
	diff input-char.txt.out input-char.txt.out.check
	diff input-double.txt.out input-double.txt.out.check
	diff input-string.txt.out input-string.txt.out.check

build-check: main
	./main input-int.txt > input-int.txt.out.check
	./main input-bool.txt > input-bool.txt.out.check
	./main input-char.txt > input-char.txt.out.check
	./main input-double.txt > input-double.txt.out.check
	./main input-string.txt > input-string.txt.out.check


clean:
	-rm -f main
	-rm -f test
	-rm -f $(OBJECTS)
	-rm -f *.out


