
#include "CharThing.h"

CharThing::CharThing()
	: DataThing()
{
	val = 0;  // default
}

CharThing::CharThing(const char newVal)
	: DataThing()
{
	val = newVal;
}

CharThing::CharThing(const string& strVal)
	: DataThing()
{
	stringstream ss(strVal);
	char newVal;

	ss >> newVal;

	val = newVal;
}

CharThing::~CharThing() {}

CharThing::CharThing(const CharThing& s)
	:DataThing(s)
{
	val = s.val;
}

CharThing& CharThing::operator=(const CharThing& s)
{
	val = s.val;

	return *this;
}

