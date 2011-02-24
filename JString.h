
#include <string>

/**
 *
 * The JString class extends the std::string class.
 *
 * All of the std::string operations can be used normally
 * along with the additional operations provided here.
 *
 * <h2>Synopsis</h2>
 *
 * @code
 * 
 * #include "JString.h"
 *
 * JString js(" my StRiNg");
 * JString js1();
 *
 * // without preceeding spaces
 * js1 = js.prechomp();
 *
 * // use std::string operations
 * js.length();
 * js.find_first_of(' ');
 * // etc ...
 *
 * @endcode
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 * @version  0.01
 *
 */
class JString : public std::string {

public:

    /**
     * Construct a blank JString() object.
     */
    JString();

    /**
     * Construct a JString() by using a std::string.
     *
     */
    JString(const std::string& s);

    /**
     *
     * Get a string with the spaces at the front removed.
     *
     * @returns string without spaces
     *
     */
    JString prechomp();
};
