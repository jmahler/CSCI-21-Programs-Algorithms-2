
#include "DoubleThing.h"

DoubleThing::DoubleThing()
	: DataThing<double>()
{
	val = 0;  // default
}

DoubleThing::DoubleThing(const double newVal)
	: DataThing<double>()
{
	val = newVal;
}

DoubleThing::DoubleThing(const string& strVal)
	: DataThing<double>()
{
	stringstream ss(strVal);
	double newVal;

	ss >> newVal;

	val = newVal;
}

DoubleThing::~DoubleThing() {}

DoubleThing::DoubleThing(const DoubleThing& s)
	: DataThing<double>(s)
{
	val = s.val;
}

DoubleThing& DoubleThing::operator=(const DoubleThing& s) {
	val = s.val;

	return *this;
}


