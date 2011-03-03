
NAME
----

CSCI 21 - Programs and Algorithms 2 - Project 3

INTRODUCTON
-----------

This project provides a simple dynamic array and allows
commands to be defined in a file to manipulate them.

DESIGN
------

As per the [specification][lab3] the value -1 is to be returned to
indicate an error.
But it is also possible to store the value -1.
This creates a conflict and makes it impossible to determine if
it was an error without calling a secondary operation.
One possible solution to this problem would be to use exceptions.

The -1 return value also implies that the object stored must be
a signed integer.
This eliminates the possiblility of defining the array in a more
generic way using templates.

AUTHOR
------

This project was completed to satisfy for [project 3][lab3]
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

