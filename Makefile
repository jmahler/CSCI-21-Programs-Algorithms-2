
INCLUDE=

OBJECTS = JArray.o
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: main

doc: *.cpp *.h 
	doxygen  # using Doxyfile 

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

