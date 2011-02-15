#include "CommandParser.h"

// {{{ parse()
CommandParser::CommandParser(string s) {
    size_t p;

    // defaults
    cmd = "";
    arg = "";

    if (s.empty())
        return;

    s = prechomp(s);

    if (s.empty())
        return;

    p = s.find_first_of(' ');
    if (p == string::npos) {
        cmd = s;
        return;
    }

    cmd = s.substr(0, p);

    if (p == s.length())
        return;

    arg = prechomp(s.substr(p + 1, s.length() - (p + 1)));

    return;
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

// vim:foldmethod=marker
