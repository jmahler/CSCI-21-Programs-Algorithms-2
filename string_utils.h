
#include <string>

using namespace std;

/**
 *
 * Remove any preceeding spaces from a string.
 *
 * @returns string without spaces
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 * @version  0.01
 */
inline string prechomp(string s)
{
    int i = 0;
    while (isspace(s[i++])) {};

    return s.substr((i - 1), s.size() - (i - 1));
}

