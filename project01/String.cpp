
#include "String.h"

using namespace std;

// {{{ String::String(string s)
String::String(string _s)
{
    s = _s;
}
// }}}

// {{{ String::~String()
String::~String()
{
    
}
// }}}

// {{{ String::toLowercase()
string String::toLowercase()
{
    string s2 = s;
    int len;
    int i;
    char c;
    
    len = s2.length();

    for (i = 0; i < len; i++) {
        c = s2[i];
        if (c >= 'A' && c <= 'Z') {
            s2[i] = c + 32;
        }

    }

    return s2;
}
// }}}

// {{{ String::toUppercase()
string String::toUppercase()
{
    string s2 = s;
     int len;
    int i;
    char c;
    
    len = s2.length();

    for (i = 0; i < len; i++) {
        c = s2[i];
        if (c >= 'a' && c <= 'z') {
            s2[i] = c - 32;
        }

    }
   
    return s2;
}
// }}}

// {{{ String::getString()
string String::getString()
{
    return s;
}
// }}}

// {{{ String::count()
int String::count()
{
    return s.size();
}
// }}}

// {{{ String::isInteger()
bool String::isInteger()
{
    int len = s.length();
    int i = 0;

    // skip preceeding spaces
    for (; i < len; i++) {
        if (s[i] != ' ')
            break;        
    }

    // false if it is all spaces
    if (i >= len)
        return false;

    // skip a sign if it has one
    if (s[i] == '-' or s[i] == '+')
        i++;

    // are all the characters a number?
    for (; i < len; i++) {
        // found a space
        if (s[i] == ' ')
            break;

        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    // everything after numbers should only be spaces
    for (; i < len; i++) {
        if (s[i] != ' ')
            return false;
    }

    return true;
}
// }}}

// {{{ operator<<
ostream& operator<<(ostream &stream, String s)
{
    stream << s.getString() ;

    return stream;
}
// }}}

