
#include "UI.h"

// {{{ UI(), ~UI()
UI::UI ()
{
    cin = new CinReader();
}

UI::~UI ()
{
    delete cin;
}
// }}}

// {{{ UI::mainMenu()
void UI::mainMenu()
{
    string ps1 = "si> ";

    cout << " Enter 'h' for the help screen.\n";

    while (1) {
        string line;
        string cmd;
        string arg;

        cout << ps1;
        line = cin->readString();

        //cp->parse(line);
        CommandParser cp(line);

        cmd = cp.getCommand();
        arg = cp.getArgument();

        cout << "cmd: " << cmd << "\n";

        if (cmd.empty()) {
            // empty line
        } else if (cmd == "i") {
            int i;

            arg = cp.getArgument();

            String s(arg);

            if (! s.isInteger()) {
                cout << "  I can't understand that integer, please try again.\n";
            } else {
                // convert the ascii string to an integer
                stringstream ss(arg);
                ss >> i;

                // dispatch to the second level user interface for an integer
                this->submenuInt(i);
            }
        } else if (cmd == "s") {
            arg = cp.getArgument();

            // dispatch to submenu for string
            this->submenuString(arg);
        } else if (cmd == "h") {
            cout << " Help:\n"
                 << "  s <string>\n" 
                 << "  i <integer>\n" 
                 << "  h                 help\n"
                 << "  q                 quit\n";
        } else if (cmd == "q") {
            break;
        } else {
            cout << " Invalid Input.\n" 
                 << " Enter 'h' for the help screen.\n";
        }
    }

    return;  // quit
}
// }}}

// {{{ UI::submenuInt(int i)
void UI::submenuInt(int _i)
{
    string ps1 = "si/int> ";
    Integer i(_i);

    cout << " integer: " << i << "\n";
    cout << " Enter 'h' for the help screen.\n";

    while (1) {
        string line;
        string cmd;
        string arg;

        cout << ps1;

        line = cin->readString();

        CommandParser cp(line);

        cmd = cp.getCommand();
        arg = cp.getArgument();

        if (cmd.empty()) {
            // blank line
        } else if (cmd == "p") {
            // is it prime?

            if (i.isPrime()) {
                cout << " " << i << " is a prime number.\n";
            } else {
                cout << " " << i << " is NOT a prime number.\n";
            }
        } else if (cmd == "o") {
            if (i.isOdd()) {
                cout << " " << i << " is odd.\n";
            } else {
                cout << " " << i << " is NOT odd.\n";
            }
        } else if (cmd == "e") {
            if (i.isEven()) {
                cout << " " << i << " is even.\n";
            } else {
                cout << " " << i << " is NOT even.\n";
            }
        } else if (cmd == "d") {
            cout << " number: " << i << "\n";
        } else if (cmd == "q") {
            break;
        } else if (cmd == "h") {
            cout << " Help, integer:\n"
                 << "  d           display the number\n"
                 << "  o           is it odd?\n"
                 << "  e           is it even?\n"
                 << "  p           is it a prime number?\n"
                 << "  h           help\n"
                 << "  q           quit (to previous level)\n";
        } else {
            cout << " Invalid Input.\n"
                 << " Enter 'h' for the help screen.\n";
        }
    }

    return;
}
// }}}

// {{{ UI::submenuString(string s)
void UI::submenuString(string _s) {
    String s(_s);
    string ps1 = "si/str> ";

    cout << " String: '" << s << "'\n";
    cout << " Enter 'h' for the help screen.\n";

    while (1) {
        string line;
        string cmd;
        string arg;

        cout << ps1;

        line = cin->readString();

        CommandParser cp(line);

        cmd = cp.getCommand();
        arg = cp.getArgument();

        if (cmd.empty()) {
            // blank line
        } else if (cmd == "u") {
            cout << " uppercase: '" << s.toUppercase() << "'\n";
        } else if (cmd == "l") {
            cout << " lowercase: '" << s.toLowercase() << "'\n";
        } else if (cmd == "c") {
            cout << " count: " << s.count() << "\n";
        } else if (cmd == "d") {
            cout << " '" << s << "'\n";
        } else if (cmd == "q") {
            break; // quit
        } else if (cmd == "h") {
            cout << " Help, String:\n"
                 << "  c           count number of characters\n"
                 << "  d           display the string\n"
                 << "  l           to lowercase\n"
                 << "  u           to uppercase\n"
                 << "  h           help\n"
                 << "  q           quit (to previous level)\n";
        } else {
            cout << " Invalid Input.\n"
                 << " Enter 'h' for the help screen.\n";
        }
    }

    return;
}
// }}}

// vim:foldmethod=marker
