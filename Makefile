
INCLUDE=
OBJECTS=
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: wc config palindrome


config: config.cpp
	$(CC) $(CFLAGS) $< -o $@

#config-input.txt.check: config-input.txt config 
#	cat config-input.txt | ./config > config-input.txt.check

config-input.txt.out: config-input.txt config
	cat config-input.txt | ./config > config-input.txt.out


palindrome: palindrome.cpp
	$(CC) $(CFLAGS) $< -o $@

palindrome-input.txt.out: palindrome palindrome-input.txt palindrome-run.sh
	./palindrome-run.sh > $@

#palindrome-input.txt.check: palindrome palindrome-input.txt palindrome-test.sh
#	./palindrome-test.sh > $@

wc: wc.cpp
	$(CC) $(CFLAGS) $< -o $@

#wc-input.txt.check: wc-input.txt wc 
#	cat wc-input.txt | ./wc > wc-input.txt.check

wc-input.txt.out: wc-input.txt wc
	cat wc-input.txt | ./wc > wc-input.txt.out


check: wc wc-input.txt.out config config-input.txt.out palindrome-input.txt.out
	# OK if no differences are shown
	diff wc-input.txt.out wc-input.txt.check
	diff config-input.txt.out config-input.txt.check
	diff palindrome-input.txt.out palindrome-input.txt.check


clean:
	-rm -f wc wc-input.txt.out
	-rm -f config config-input.txt.out
	-rm -f palindrome-input.txt.out

