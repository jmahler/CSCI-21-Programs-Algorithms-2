
#include <iostream>

using namespace std;

/**
 *
 * A class for performing operations on integers.
 * Operations such as whether an integer is odd, even or is a prime number.
 *
 * <h2>Synopsis</h2>
 *
 * @code
 *   #include "Integer.h"
 *
 *   Integer i(12);
 *
 *   // display the number
 *   cout << i << "\n";
 *
 *   if (i.isOdd()) {
 *      cout << i << " is odd\n";
 *   } else if (i.isEven()) {
 *      cout << i << " is even\n";
 *   }
 * 
 *   if (i.isPrime()) {
 *      cout << i << " is a prime number\n";
 *   } else {
 *      cout << i << " is NOT a prime number\n";
 *   }
 *
 * @endcode
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 * @version 0.01
 *
 */
class Integer
{
private:
    int i;

public:
    /**
     *
     * To construct an Integer argument a single integer of
     * the standard type 'int' must be provided.
     *
     * @arg integer
     *
     */
    Integer(int i);
    ~Integer();

    // {{{ isPrime()
    /**
     * Is the number a prime number?
     *
     * @return true if prime, false otherwise
     *
     * A prime number is a number that has only two divisors,
     * 1 and the number itself.
     * For a more in depth background on prime numbers see
     * [<a href="http://en.wikipedia.org/wiki/Prime_number">Wikipedia: Prime number</a>].
     *
     * The algorithm used here is a simple brute force approach.
     * Excluding the number 1 or the number itself it tries
     * to find any number in between that divides in evenly.
     * If any number divides in then there are more than two divisors
     * and this number is not a prime.
     * It can be quite slow for very large numbers.
     */
    bool isPrime();
    // }}}

    // {{{ isEven()
    /**
     * Is the number an even number?
     *
     * @return true if even, false otherwise
     */
    bool isEven();
    // }}}

    // {{{ isOdd()
    /**
     * Is the number an odd number?
     *
     * @return true if even, false otherwise
     */
    bool isOdd();
    // }}}

    // {{{ getVal()
    /**
     * Get the integer value.
     *
     * @return int 
     *
     */
    int getVal();
    // }}}

    // {{{ setVal()
    /**
     *
     * Set the value of this Integer.
     *
     */
    void setVal(int i);
    // }}}
};

ostream& operator<<(ostream &stream, Integer i);

// vim:foldmethod=marker
