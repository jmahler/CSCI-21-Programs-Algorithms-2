
#include <string>
#include "JString.h"

using namespace std;
/**
 *
 * Parse a string in to its command and argument
 * by splitting it on the first space.
 * If there is no space it is a command without an argument.
 *
 * <h2>Synopsis</h2>
 *
 * @code
 *
 * #include "CommandParser.h"
 *
 *
 * CommandParser cp("command  argument with spaces");
 *
 * cp.getCommand();   // "command"
 * cp.getArgument();  // "argument with spaces"
 *
 *
 * CommandParser cp("i");
 *
 * cp.getCommand();   // "i"
 * cp.getArgument();  // ""
 *
 * @endcode
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 * @version 0.02
 *
 */
class CommandParser {
    string cmd;
    string arg;

public:
    /**
     * Parse the string in to an object
     * in which the command and argument can be retrived
     * (getCommand(), getArgument()).
     *
     * The string should be of the form:
     *
@verbatim
    "<cmd> <argument>"
      OR
    "<cmd>"
@endverbatim
     *
     * @return parsed string object
     */
    CommandParser(string s);

    /**
     * Get the command.
     *
     * @return the command or "" if it was blank
     */
    string getCommand();

    /**
     * Get the argument.
     *
     * There must have been a command otherwise the argument will be blank as well.
     *
     * @return the argument or "" if it was blank
     */
    string getArgument();
};

