
INCLUDE=

OBJECTS = CommandParser.o Child.o BirthRecords.o BirthRecord.o Parent.o
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: parent child

doc: *.cpp *.h 
	doxygen  # using Doxyfile 

BirthRecords.o: BirthRecord.o

parent: parent.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

child: child.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cc %.h
	$(CC) $(CFLAGS) -c $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<


clean:
	-rm -f parent child
	-rm -f $(OBJECTS)
	-rm -fr doc

