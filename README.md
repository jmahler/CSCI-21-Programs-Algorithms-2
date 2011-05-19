
NAME
====

Miscellaneous C++ programs using STL components.

DESCRIPTION
===========

Four different programs are included. 

- palindrome - Tests whether a string is a palindrome.
- wc - Counts the number of words in a file and displays the top most occurrences.
- config - Parses a config file and display the values.
- armies - Simulates a battle between two armies using random numbers.

palindrome
----------

To test whether a string is a palindrome simply specify a string on
the command line.
It will respond stating whether it is or is not a palindrome.

	shell$ ./palindrome sit on a potato pan otis
    'sit on a potato pan otis' is a palindrome
	shell$ ./palindrome a b c b
	'a b c d' is NOT a palindrome

Also include is a utility (palindrome-run.sh) which will run palindrome
against a file with one string on each line.
See the source of this file for more information.

STL components used: stack

wc
--

Word count expects data to be provided on standard in and it will
terminate when it reaches the end of input.
At the end it will display all the words along with their count.
And it will also display a summary of the top most occurrences.

	shell$ cat scripts/ForrestGump.txt | ./wc

Various text files are included in the directory 'scripts/'.
The results can be quite entertaining.
For example, in the previous command the top occurrences unsurprisingly
are 'forrest' and 'jenny'.

To improve results the data is normalized somewhat.
For example: occurrences such as 'The', 'the', 'The!' are normalized
by lowering their case and removing any non alpha numeric characters.

STL components used: map, vector, algorithm

config
------

The config program reads a file containing items of 'key:val' on
each line and displays the results.
It expects its input to come from standard in.

	shell$ cat config-input.txt | ./config

	five: 5
	four: 4
	lucky: 7
	one: 1
	three: 3
	year: 2011

And the config file to produce the above output is shown below.

	lucky: 7    ;  the luckiest number
	year: 2011  ;  year
	one: 1      ;  the lonliest number
	three: 3    ;  three
	four:4
	five :5

Notice that the config format is very forgiving with spaces
and characters after the options.
Currently it only supports integer values.

STL components used: map

armies
------

The armies program simulates a battle between two armies by using
random numbers.
It takes a single argument specifying the number of battles.

	shell$ ./armies 10
	range: 40
	10 battles have been fought
	Army 1 had 5 wins
	Army 2 had 5 wins
	and there were 0 draws
	Both armies tied!
	shell$ 

The algorithm works by generating a random number for each army for
the number of battles and pushing them on to a queue for each army.
Then for the number of battles the values are popped off the stack
and compared.
The army with the larger value wins the battle.
And at the end a summary of the results is displayed.

STL components used: queue


DEVELOPER NOTES
===============

This project was developed under Linux
and commands such as 'make' and 'diff' are expected to
be present in order to build and test it properly.

This project includes an extensive test suite.
All assertion tests are placed in 'test.cpp'.
And verification of the proper output of the main program
is checked by viewing the differences ('diff' command) of
the various check files.
To run all the tests run 'make check'.


AUTHOR
======

This project was completed to satisfy [project 8][lab8]
in the class "Programs and Algorithms 2 (CSCI 21)".
This class was taught by [Boyd Trolinger][boyd] during the Spring of
2011 at [Butte College][butte].
This project is publicly hosted on [Github][gith] under the name [CSCI-21-Programs-Algorithms-2-project08][prj8].

 [lab8]: http://foobt.net/csci21/S3513_11/labs/lab8.html
 [butte]: http://www.butte.edu
 [boyd]: http://www.foobt.net
 [prj8]: https://github.com/jmahler/CSCI-21-Programs-Algorithms-2-project07
 [gith]: http://github.com

Jeremiah Mahler <jmmahler@gmail.com><br>
<http://www.google.com/profiles/jmmahler#about>


COPYRIGHT
=========

Copyright &copy; 2011, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

