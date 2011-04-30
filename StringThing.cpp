
#include "StringThing.h"

StringThing::StringThing()
	: DataThing()
{
	val = "";  // default
}

StringThing::StringThing(const string strVal)
	: DataThing()
{
	val = strVal;
}

StringThing::~StringThing() {}

StringThing::StringThing(const StringThing& s)
	: DataThing(s)
{
	val = s.val;
}

StringThing& StringThing::operator=(const StringThing& s) {
	val = s.val;

	return *this;
}

