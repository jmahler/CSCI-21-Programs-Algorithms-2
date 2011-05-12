
INCLUDE=
OBJECTS=
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: wc

wc: wc.cpp
	$(CC) $(CFLAGS) $< -o $@

#wc-input.txt.check: wc-input.txt wc 
#	cat wc-input.txt | ./wc > wc-input.txt.check

wc-input.txt.out: wc-input.txt wc
	cat wc-input.txt | ./wc > wc-input.txt.out


check: wc wc-input.txt.out
	# OK if no differences are shown
	diff wc-input.txt.out wc-input.txt.check


clean:
	-rm -f wc wc-input.txt.out

