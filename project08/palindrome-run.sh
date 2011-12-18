#!/bin/bash

# This script is used to run the palindrome command on
# every line of the input file.

FILE="palindrome-input.txt"

cat $FILE | while read line; do
	./palindrome $line
done

