
#include "StringThing.h"

StringThing::StringThing()
	: DataThing<string>()
{
	val = "";  // default
}

StringThing::StringThing(const string strVal)
	: DataThing<string>()
{
	val = strVal;
}

StringThing::~StringThing() {}

StringThing::StringThing(const StringThing& s)
	: DataThing<string>(s)
{
	val = s.val;
}

StringThing& StringThing::operator=(const StringThing& s) {
	val = s.val;

	return *this;
}

