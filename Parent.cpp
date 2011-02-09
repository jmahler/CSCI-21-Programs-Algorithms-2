
#include "Parent.h"

Parent::Parent()
{
    ps1 = "> ";  // first level command prompt
    ps2 = ">> "; // second level command prompt
}

// {{{ Parent::mainMenu()
void Parent::mainMenu()
{
    cout << "So you think you're ready to be a parent?\n"
         << "\n"
         << "Lets see if you can keep your children from starving...\n"
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
                cout << "Which child do you want to feed?.\n";
            }  else {
                //pid = arg;
                //kill(pid, SIGHUP);
                // TODO 
            }
        } else if (cmd == "s") {
            // spawn a new child

            spawn(arg);

        } else if (cmd == "sn") {
            // create n John Does

            int n;
            stringstream ss(arg);
            
            ss >> n;  // atoi()

            while (n-- > 0) {
                spawn();
            }

        } else if (cmd == "s+") {
            list<string> names;

            cout << "Enter each new child on a single line\n"
                 << "a blank line quits.\n";

            string ps1 = ">> ";

            /*
             * All the names are read in BEFORE any are spawned.
             * This was done because output will be generated from
             * the child as soon as they are spawned which can
             * make further input difficult.
             */
            while (1) {
                cout << ps1;

                getline(cin, line);

                if (line.empty())
                    break;

                names.push_front(line);
            }

            for(list<string>::iterator it = names.begin(); it != names.end();it++) {
                spawn(*it);
            }
        } else if (cmd == "q") {
            // quit

            break;
        } else if (cmd == "h") {
            // help menu
            cout << "Help Menu:\n"
                 << "\n"
                 << " h          help menu\n"
                 << " f <id>     feed a child\n"
                 << " s <name>   spawn a single named child\n"
                 << " s+         spawn multiple named children\n"
                 << " sn <n>     spawn n children unnamed children\n"
                 << "            WARNING: spawn too many and you could\n"
                 << "              crash your computer\n"
                 << " q          quit\n";
        }
    }
}
// }}}

void Parent::spawn(string name) {

    pid_t pid = fork();

    if (0 == pid) {
        // we are now a child

        //execl("./child", "./child", arg.c_str(), 0);
        execlp("./child", "./child", name.c_str(), 0);

        // if we got here there was an error
        // TODO - improve error messages
        perror(0);
        exit(1);
    } else {
        // we are the parent

        BirthRecords *brs = this->getBirthRecords();

        brs->addBirth(pid, name);
    }
}

// vim:foldmethod=marker
