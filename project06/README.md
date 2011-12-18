
NAME
----

Doubly linked lists in C++

INTRODUCTION
------------

This project implements a doubly linked list structure in C++ and
provides a command line utility for testing it using commands from
a file.
The structure is built using C++'s template facilities and so it
is not specific to any type.
The command line utility is type generic by using an abstract
class (DataThing) and derived children (IntegerThing, BoolThing, ...).

Instructions for operation are show below as produced using (./main -h).

    shell$ ./main -h
    
    USAGE:
      ./main -h                # this help screen
      ./main                   # reads "input-int.txt"
      ./main -                 # reads input from stdin
      ./main <file>            # reads input from <file>
    
      # pipe commands from a file
        cat input.txt | ./main -
      # execute commands interactively
       ./main -
    
    COMMANDS:
      <type>  (FIRST LINE) # set type on first line of file
                           # integer, bool, char, double, string
      n                    # get the node count
      puf <val>            # push a value to the FRONT
      pub <val>            # push a value to the BACK
      pof                  # pop a value from the FRONT
      pob                  # pop a value from the BACK
      i   <val>            # insert value and keep sorted
      r   <val>            # remove a value
      rd  <val>            # remove a value and its duplicates
      f   <val>            # find a value
      fr  <val>            # find a value (recusive)
      d                    # display the array
      c                    # clear all values
      cr                   # clear all values (recursive)
      -1                   # quit


Show below is a sample input command file for the 'string' (input-string.txt).

    string      # type
    n           # node count
    d           # display the list
    f one       # find this string
    fr one
    i abc
    i ghi       # insert, out of order
    i def
    d           # display, (should be sorted)
    f abc       # find
    fr abc      # find, recursively
    fr aef      # find, (shouldn't be found)
    puf jkl     # push front
    d
    c           # clear
    d
    -1          # quit

And the following is the output produced by processing input-string.txt.

    shell$ ./main input-string.txt
    
    node count is 0
    ( )
    one not found
    one not found (recursive)
    inserted: abc
    inserted: ghi
    inserted: def
    ( abc def ghi )
    abc found
    abc found (recursive)
    aef not found (recursive)
    pushed jkl on to front of list
    ( jkl abc def ghi )
    all values cleared
    ( )

There are various other examples for other types included
(input-int.txt, input-char.txt, input-double.txt, ...)

DEVELOPER NOTES
---------------

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
------

This project was completed to satisfy [project 6][lab6]
in the class "Programs and Algorithms 2 (CSCI 21)".
This class was taught by [Boyd Trolinger][boyd] during the Spring of
2011 at [Butte College][butte].
This project is publicly hosted on [Github][gith] under the name [CSCI-21-Programs-Algorithms-2-project05][prj6].

 [lab6]: http://foobt.net/csci21/S3513_11/labs/lab6.html
 [butte]: http://www.butte.edu
 [boyd]: http://www.foobt.net
 [prj6]: https://github.com/jmahler/CSCI-21-Programs-Algorithms-2-project06
 [gith]: http://github.com

Jeremiah Mahler <jmmahler@gmail.com><br>
<http://www.google.com/profiles/jmmahler#about>

COPYRIGHT
---------

Copyright &copy; 2011, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

