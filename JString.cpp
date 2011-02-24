
#include "JString.h"

JString::JString()
    :std::string() // initialize base
{

}

JString::JString(const std::string& s)
    :std::string(s) // initialize base
{

}

JString JString::prechomp()
{
    int i = 0;
    while (isspace((*this)[i++])) {};

    return JString(this->substr((i - 1), this->size() - (i - 1)));
}

