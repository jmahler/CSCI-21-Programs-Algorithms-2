#include "CommandParser.h"

using namespace std;

// {{{ parse()
CommandParser::CommandParser(string s) {
    size_t p1, p2;

    // defaults
    cmd = "";
    arg = "";

    if (s.empty()) {
        return;
    }

    p1 = s.find_first_of(" ", 0);
    if (p1 == string::npos) {
        // no spaces were found
        cmd = s;

        return;
    }

    p2 = s.find_first_not_of(" ", p1);

    if (p2 == string::npos) {
        return;
    }

    cmd = s.substr(0, p1);
    arg = s.substr(p2, s.length() - p2);
}
// }}}

// {{{ getCommand()
string CommandParser::getCommand() {
    return cmd;
}
// }}}

// {{{ getArgument()
string CommandParser::getArgument() {
    return arg;
}
// }}}

