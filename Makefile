
INCLUDE=

OBJECTS = JArray.o CommandParser.o JString.o
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: main test

doc: *.cpp *.h 
	doxygen  # using Doxyfile 

test: test.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

main: main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cc %.h
	$(CC) $(CFLAGS) -c $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<


clean:
	-rm -f main
	-rm -f $(OBJECTS)
	-rm -fr doc

