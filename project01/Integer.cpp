
#include "Integer.h"

// {{{ Integer::Integer, ~Integer
Integer::Integer(int _i)
{
    i = _i;
}

Integer::~Integer()
{

}
// }}}

// {{{ Integer::isEven()
bool Integer::isEven()
{
    return (! this->isOdd());
}
// }}}

// {{{ Integer::isOdd()
bool Integer::isOdd()
{
    return (i % 2 != 0);
}
// }}}

// {{{ Integer::isPrime()
bool Integer::isPrime()
{
    int n = i;
    int h;
    int j;

    // make it positive
    if (n < 0)
        n *= -1;

    if (n <= 1)
        return false;

    // A divisor greater than 1/2 of the number
    // will never divide evenly until it
    // is is the number.
    // 
    // h is used to abort at the half way point
    h = n / 2;

    for (j = 2; j <= h; j++) {
        if (0 == (n % j))
            return false; // not a prime
    }

    return true;
}
// }}}

// {{{ Integer::getVal(
int Integer::getVal()
{
    return i; 
}
// }}}

// {{{ Integer::setVal(int _i)
void Integer::setVal(int _i)
{
    i = _i;
}
// }}}

// {{{ operator<<
ostream& operator<<(ostream &stream, Integer i)
{
    stream << i.getVal() ;

    return stream;
}
// }}}

// vim:foldmethod=marker
