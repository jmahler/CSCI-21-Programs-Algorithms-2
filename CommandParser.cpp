#include "CommandParser.h"

// {{{ parse()
CommandParser::CommandParser(string s) {
    size_t l;
    size_t p;
    size_t i = 0;

    // defaults
    cmd = "";
    arg = "";

    // no command, no arguments
    if (s.empty()) {
        return;
    }

    l = s.length();

    // skip any preceeding spaces
    for (; i < l; i++) {
        if (s[i] != ' ')
            break;
    }

    p = i; // possible start position of argument

    // find the next space or end
    for (; i < l; i++) {
        if (s[i] == ' ') {
            break;
        }
    }

    // we hit the end
    if (i == l) {
        // if there is at least one character
        if (i > p)
            cmd = s.substr(p, i - p);

        return;
    } else {
        // we hit a space
        cmd = s.substr(p, i - p);
    }

    // skip any spaces between the command and argument
    for (; i < l; i++) {
        if (s[i] != ' ')
            break;
    }

    // we hit the end
    if (i == l) {
        return;
    }

    // we haven't hit the end yet there might still
    // be an argument

    p = i; // possible start position of command

    // the argument is everything else
    arg = s.substr(p, l - i);
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
