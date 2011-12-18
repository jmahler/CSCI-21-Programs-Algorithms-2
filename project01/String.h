
#include <string>

using namespace std;


/**
 *
 * Performs simple operations on strings such as counting the number of
 * characters or converting to upper case.
 *
 * <h2>Synopsis</h2>
 *
 * @code
 * #include "String.h"
 *
 * String s("My cRaZy String");
 *
 * cout << s << "\n";
 *
 * cout << s.toUppercase() << "\n";
 * cout << s.toLowercase() << "\n";
 *
 * // number of characters
 * cout << s.count() << "\n";
 *
 * cout << s.getString() << "\n";
 *
 * // does the string look like an integer?
 * s.isInteger();
 *
 * @endcode
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 * @version 0.01
 */
class String {
    string s;
public:
    /**
     * Construct a String object by initializing it with
     * a standard string.
     *
     */
    String(string s);
    ~String();

    /**
     * Convert all the letters in the string to uppercase.
     *
     * @return the converted string
     */
    string toUppercase();

    /**
     * Convert all the letters in the string to lowercase.
     *
     * @return the converted string
     */
    string toLowercase();

    /**
     * Get the representation as a standard string.
     *
     * @return the string
     */
    string getString();

    /**
     * The number of characters in the string.
     *
     * @return number of characters
     */
    int count();

    /**
     * Does this string represent an integer?
     *
     * A string representing an integer can contain spaces at
     * the begining or end, an optional negative sign, or any number
     * digits.
     *
     * @return true if an integer, false otherwise
     */
    bool isInteger();
};

/**
 *
 * Output stream operator for a 'String' type.
 *
 */
ostream& operator<<(ostream &stream, String s);
