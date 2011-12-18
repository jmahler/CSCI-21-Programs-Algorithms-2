#include "CommandParser.h"

// {{{ parse()
CommandParser::CommandParser(string s) {
    size_t p;
    JString js(s);

    // defaults
    cmd = "";
    arg = "";

    if (js.empty())
        return;

    js = js.prechomp();

    if (js.empty())
        return;

    p = js.find_first_of(' ');
    if (p == std::string::npos) {
        cmd = s;
        return;
    }

    cmd = js.substr(0, p);

    if (p == js.length())
        return;

    js = js.substr(p + 1, s.length() - (p + 1));
    arg = js.prechomp();

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
