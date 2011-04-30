
#include "IntegerThing.h"

IntegerThing::IntegerThing()
	: DataThing()
{
	val = 0;  // default
}

IntegerThing::IntegerThing(const int newVal)
	: DataThing()
{
	val = newVal;
}

IntegerThing::IntegerThing(const string& strVal)
	: DataThing()
{
	stringstream ss(strVal);
	int newVal;

	ss >> newVal;

	val = newVal;
}

IntegerThing::~IntegerThing() {}

IntegerThing::IntegerThing(const IntegerThing& s)
	: DataThing(s)
{
	val = s.val;
}

IntegerThing& IntegerThing::operator=(const IntegerThing& s)
{
	val = s.val;

	return *this;
}

