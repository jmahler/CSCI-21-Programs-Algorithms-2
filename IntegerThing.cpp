
#include "IntegerThing.h"

IntegerThing::IntegerThing()
	: DataThing<int>()
{
	val = 0;  // default
}

IntegerThing::IntegerThing(const int newVal)
	: DataThing<int>()
{
	val = newVal;
}

IntegerThing::IntegerThing(const string& strVal)
	: DataThing<int>()
{
	stringstream ss(strVal);
	int newVal;

	ss >> newVal;

	val = newVal;
}

IntegerThing::~IntegerThing() {}

IntegerThing::IntegerThing(const IntegerThing& s)
	: DataThing<int>(s)
{
	val = s.val;
}

IntegerThing& IntegerThing::operator=(const IntegerThing& s)
{
	val = s.val;

	return *this;
}

