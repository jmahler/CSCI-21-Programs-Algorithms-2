
INCLUDE=

OBJECTS = BTTimer.o
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: parent child

doc: main.cpp *.h 
	doxygen  # using Doxyfile 

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

