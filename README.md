
NAME
----

Binary Search Tree in C++

INTRODUCTION
------------

This project impements a binary search tree structure in C++ and
provides a command line utility for testing it using commands from
a file.

Instructions for operation are show below as produced using (./main -h).

    shell$ ./main -h

    USAGE:
      ./main -h                # this help screen
      ./main                   # reads "input.txt"
      ./main -                 # reads input from stdin
      ./main <file>            # reads input from <file>
    
      # pipe commands from a file
        cat input.txt | ./main -
      # execute commands interactively
       ./main -
    
    COMMANDS:
      x                    # destroy the current object and
                           #   create a new one.
      n                    # get the node count
      i   <val>            # insert value
      r   <val>            # remove a value
      f   <val>            # find a value
      min                  # minium value
      max                  # maximum value
      p                    # print in sorted order
      pe                   # print in post-order
      pp                   # print in pre-order
      pr                   # print in reverse order
      c                    # clear all values
      -1                   # quit

Shown below is a sample input command file.

    n
    p
    i 10
    i 20
    i 30
    pe
    pp
    pr
    r 10
    f 10
    f 20
    n
    p
    pe
    pp
    pr
    min
    max
    c
    min
    max
    -1

And the following is the output produced by processing the above commands.

    creating new object
    sorted-order:   ( ) 
    inserted: 10
    inserted: 20
    inserted: 30
    post-order:     ( 30 20 10 ) 
    pre-order:      ( 10 20 30 ) 
    reverse-order:  ( 30 20 10 ) 
    removed: 10
    10 not found
    20 found
    node count is 2
    sorted-order:   ( 20 30 ) 
    post-order:     ( 30 20 ) 
    pre-order:      ( 20 30 ) 
    reverse-order:  ( 30 20 ) 
    minimum value is: 20
    maximum value is: 30
    all values cleared
    minimum value of an empty list is undefined
    maximum value of an empty list is undefined


AUTHOR
------

This project was completed to satisfy [project 7][lab7]
in the class "Programs and Algorithms 2 (CSCI 21)".
This class was taught by [Boyd Trolinger][boyd] during the Spring of
2011 at [Butte College][butte].
This project is publicly hosted on [Github][gith] under the name [CSCI-21-Programs-Algorithms-2-project07][prj7].

 [lab7]: http://foobt.net/csci21/S3513_11/labs/lab7.html
 [butte]: http://www.butte.edu
 [boyd]: http://www.foobt.net
 [prj7]: https://github.com/jmahler/CSCI-21-Programs-Algorithms-2-project07
 [gith]: http://github.com

Jeremiah Mahler <jmmahler@gmail.com><br>
<http://www.google.com/profiles/jmmahler#about>

COPYRIGHT
---------

Copyright &copy; 2011, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

