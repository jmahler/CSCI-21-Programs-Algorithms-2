
#include <string>

using namespace std;


/**
 *
 * A class for operations on string beyond what is provided
 * by the standard library (string).
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
 * @endcode
 */
class String {
    string s;
public:
    /**
     * Construct a String object by intializing it with
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
     * @return number of charcaters
     */
    int count();
};

ostream& operator<<(ostream &stream, String s);
