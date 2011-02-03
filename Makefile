
INCLUDE=

OBJECTS = UI.o String.o Integer.o CinReader.o CommandParser.o
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: main

doc: main.cpp *.h 
	doxygen  # using Doxyfile 

main: main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<

#doc/doxygen-html: Doxyfile src/* include/*
#	doxygen $<


clean:
	-rm -f main
	-rm -f $(OBJECTS)
	-rm -fr doc

