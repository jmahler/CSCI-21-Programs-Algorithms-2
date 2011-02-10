
NAME
----

CSCI 21 - Programs and Algorithms 2 - Project 2

INTRODUCTON
-----------

This project is a game of virtual pets.
The goal is to keep the pets fed before they die.

DESIGN
------

The purpose of this project is to continue to learn more about
the basics of object oriented design in C++ [[lab2][lab2]].

 [lab2]: http://foobt.net/csci21/S3513_11/labs/lab2.html

If the game is built using only the very basics of C++ it is
very limited.  The parent must manually check (poll) to
see if the children are hungry.

But the concept of virtual children (pets) suggests a more dynamic
design would result in a more realistic game.
Children bug their parents when they are hungry and they
do not wait for the parent to ask.
This design can be accomplished by using several standard Linux
system calls (fork, exec, signals, interrupts, etc).
And this design is what is implemented in this project.

The parent process is in charge of the children (or pets).
It can create new children or feed hungry ones.
But each child is an independent process.
It's hunger (or energy) increases (or decreases) over time.
The child can bug the parent for food by using standard output
since these file handles are shared after a fork.
And the parent can feed the children using inter-process
communication (IPC).  In this case the HUP signal (man 7 signal).

    $ ./parent
    $ >
    $ > s Joe Bob
     (spawned new child named "Joe Bob")
     ...

An interesting consequence of encapsulating the child in to its own process
is that it can be run and tested without the parent.
Simply start a child process and send it HUP signals to keep it fed.
Note, it may be easier to do this in two separate terminals because
the child will clutter the screen when it is begging for food.

    $ ./child &
    $ # find the pid
    $ ps -a
     PID   TTY          TIME CMD
     24195 pts/0    00:00:00 child
     24196 pts/0    00:00:00 ps
    $ kill -HUP 24195     # feed one child
    $ killall -HUP child  # feed all the children


AUTHOR
------

This project was completed to satisfy for project 2 
in the class "Programs and Algorithms 2".
This class was taught by [Boyd Trolinger][boyd] during the Spring of
2011 at [Butte College][butte].
This project is publicly hosted on [Github][gith] under the name [CSCI-21-Programs-Algorithms-2-project02][gitprj2].

 [butte]: http://www.butte.edu
 [boyd]: http://www.foobt.net
 [gitprj2]: https://github.com/jmahler/CSCI-21-Programs-Algorithms-2-project02
 [gith]: http://github.com

Jeremiah Mahler <jmmahler@gmail.com><br>
<http://www.google.com/profiles/jmmahler#about>

COPYRIGHT
---------

Copyright &copy; 2011, Jeremiah Mahler.  All Rights Reserved.<br>
This project is free software and released under
the [GNU General Public License][gpl].

 [gpl]: http://www.gnu.org/licenses/gpl.html

