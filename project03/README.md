
NAME
----

CSCI 21 - Programs and Algorithms 2 - Project 3

INTRODUCTON
-----------

A simple dynamic array and a utility to test it using commands from a file.

The utility is run as shown below (./main -h)

    USAGE:
      ./main -h                # this help screen
      ./main                   # reads "lab3input.txt"
      ./main -                 # reads input from stdin
      ./main <file>            # reads input from <file>
    
      # pipe commands from a file
        cat lab3input.txt | ./main -
      # execute commands interactively
       ./main -
    
    COMMANDS:
      i  <val> <idx>      # replace value at index
      ii <val> <idx>      # insert value at index
      g  <idx>            # get value at index
      a  <val>            # append a value
      r  <idx>            # remove value at index
      c                   # get capacity
      n                   # get size
      p                   # describe the array
      -1                  # quit

AUTHOR
------

This project was completed to satisfy [project 3][lab3]
in the class "Programs and Algorithms 2".
This class was taught by [Boyd Trolinger][boyd] during the Spring of
2011 at [Butte College][butte].
This project is publicly hosted on [Github][gith] under the name [CSCI-21-Programs-Algorithms-2-project03][prj3].

 [lab3]: http://foobt.net/csci21/S3513_11/labs/lab3.html
 [butte]: http://www.butte.edu
 [boyd]: http://www.foobt.net
 [prj3]: https://github.com/jmahler/CSCI-21-Programs-Algorithms-2-project03
 [gith]: http://github.com

Jeremiah Mahler <jmmahler@gmail.com><br>
<http://www.google.com/profiles/jmmahler#about>

COPYRIGHT
---------

Copyright &copy; 2011, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

