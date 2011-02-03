
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

// {{{ operator<<
ostream& operator<<(ostream &stream, String s)
{
    stream << s.getString() ;

    return stream;
}
// }}}

