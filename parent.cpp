
#include "CommandParser.h"

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <iomanip>
#include <cstring>

static void reaper(int sig, siginfo_t *siginfo, void *context) {

    cout << "A child has died!\n";

    while (waitpid(-1, NULL, WNOHANG) > 0) {}

    return;
}

int main() {

    string ps1 = "$> ";
    struct sigaction sa_reaper;

    sa_reaper.sa_sigaction = &reaper;
    sigemptyset(&sa_reaper.sa_mask);
    sa_reaper.sa_flags = 0;

    sigaction(SIGCHLD, &sa_reaper, NULL);

    cout << "So you think you're ready to be a parent?\n"
         << "\n"
         << "Lets see if you can keep your pets from starving...\n"
         << "\n"
         << "Enter 'h' for the help menu.\n";

    while (1) {
        string line;
        string cmd;
        string arg;

        // TODO display alive child summary

        cout << ps1;

        while (1) {
            getline(cin, line);
            if (cin.fail() or cin.bad()) { // *
                cin.clear();
            } else {
                break;
            }
        }
        /*
         * * When the SIGCHLD interrupt is executed the bad bit
         *   will be set on cin.  This is fixed by using clear().
         */

        CommandParser cp(line);

        cmd = cp.getCommand();
        arg = cp.getArgument();

        if (cmd == "f") {
            // feed a pet
            
            if (arg.empty()) {
                cout << "Which pet do you want to feed?.\n";
            }  else {
                //pid = arg;
                //kill(pid, SIGHUP);
                // TODO 
            }
        } else if (cmd == "s") {
            // spawn a new child

            if (arg.empty()) {
                cout << "A name must be given for your new pet.\n";
            } else {
                pid_t pid = fork();

                if (0 == pid) {
                    // child

                    //execl("./child", "./child", arg.c_str(), 0);
                    execlp("./child", "./child", arg.c_str(), 0);

                    // will only get here if there was an error
                    perror(0);
                    exit(1);
                } else {
                    // parent
                    // TODO store the pid
                }
            }
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
