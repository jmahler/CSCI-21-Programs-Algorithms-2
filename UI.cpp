
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

        if (cmd.empty()) {
            // empty line
        } else if (cmd == "i") {
            int i;

            arg = cp.getArgument();

            // convert the ascii string to an integer
            i = atoi(arg.c_str());

            // dispatch to the second level user interface for an integer
            this->submenuInt(i);
        } else if (cmd == "s") {
            arg = cp.getArgument();

            // dispatch to submenu for string
            this->submenuString(arg);
        } else if (cmd == "h") {
            cout << " Help:\n";
            cout << "  s <string>\n";
            cout << "  i <integer>\n";
            cout << "  h                 help\n";
            cout << "  q                 quit\n";
        } else if (cmd == "q") {
            break;
        } else {
            cout << " Invalid Input.\n";
            cout << " Enter 'h' for the help screen.\n";
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
            cout << " Help, integer:\n";
            cout << "  d           display the number\n";
            cout << "  o           is it odd?\n";
            cout << "  e           is it even?\n";
            cout << "  p           is it a prime number?\n";
            cout << "  h           help\n";
            cout << "  q           quit (to previous level)\n";
        } else {
            cout << " Invalid Input.\n";
            cout << " Enter 'h' for the help screen.\n";
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
            cout << " count: '" << s.count() << "'\n";
        } else if (cmd == "d") {
            cout << " '" << s << "'\n";
        } else if (cmd == "q") {
            break; // quit
        } else if (cmd == "h") {
            cout << " Help, String:\n";
            cout << "  c           count number of characters\n";
            cout << "  d           display the string\n";
            cout << "  l           to lowercase\n";
            cout << "  u           to uppercase\n";
            cout << "  h           help\n";
            cout << "  q           quit (to previous level)\n";
        } else {
            cout << " Invalid Input.\n";
            cout << " Enter 'h' for the help screen.\n";
        }
    }

    return;
}
// }}}

