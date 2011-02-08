
#include "CinReader.h"
#include "CommandParser.h"

#include <unistd.h>
#include <iostream>
#include <string>
#include <errno.h>
#include <stdio.h>

int main() {

    CinReader cin;
    string ps1 = "$> ";

    cout << "So you think you're ready to be a parent?\n"
         << "\n"
         << "Lets see if you can keep your pets from starving...\n"
         << "\n"
         << "Enter 'h' for the help menu.\n";

    while (1) {
        string line;
        string cmd;
        string arg;

        cout << ps1;
        line = cin.readString();

        CommandParser cp(line);

        cmd = cp.getCommand();
        arg = cp.getArgument();

        if (cmd == "f") {
            // feed a pet
            
        } else if (cmd == "s") {
            // spawn a new child

            if (arg.empty()) {
                cout << "A name must be given for your new pet.\n";
            } else {
                pid_t pid = fork();

                if (0 == pid) {
                    int err;
                    // child
                    err = execl("./child", "./child", arg.c_str());

                    // will only get here if there was an error
                    perror(0);
                    return 1;
                } else {
                    // parent
                    // TODO store the pid
                }
            }
            //pid = arg;
            //kill(pid, SIGHUP);

        } else if (cmd == "q") {
            // quit

            break;
        } else if (cmd == "h") {
            // help menu
            cout << "Help Menu:\n"
                 << "\n"
                 << " h          help menu\n"
                 << " f <id>     feed a pet\n"
                 << " s <name>   spawn a new pet\n"
                 << " q          quit\n";
        }
    }

    // TODO - display obituaries
    return 0;
}
