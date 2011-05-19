
INCLUDE=
OBJECTS=
CC=g++
CFLAGS=-Wall -ansi -pedantic $(INCLUDE)

all: wc config palindrome armies


armies: armies.cpp
	$(CC) $(CFLAGS) $< -o $@


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

check: wc config config-input.txt.out palindrome-input.txt.out
	# OK if no differences are shown
	diff config-input.txt.out config-input.txt.check
	diff palindrome-input.txt.out palindrome-input.txt.check


clean:
	-rm -f config config-input.txt.out
	-rm -f palindrome-input.txt.out
	-rm -f wc palindrome armies config

