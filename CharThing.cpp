
#include "CharThing.h"

CharThing::CharThing()
	: DataThing<char>()
{
	val = 0;  // default
}

CharThing::CharThing(const char newVal)
	: DataThing<char>()
{
	val = newVal;
}

CharThing::CharThing(const string& strVal)
	: DataThing<char>()
{
	stringstream ss(strVal);
	char newVal;

	ss >> newVal;

	val = newVal;
}

CharThing::~CharThing() {}

CharThing::CharThing(const CharThing& s)
	:DataThing<char>(s)
{
	val = s.val;
}

CharThing& CharThing::operator=(const CharThing& s)
{
	val = s.val;

	return *this;
}

