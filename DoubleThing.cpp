
#include "DoubleThing.h"

DoubleThing::DoubleThing()
	: DataThing()
{
	val = 0;  // default
}

DoubleThing::DoubleThing(const double newVal)
	: DataThing()
{
	val = newVal;
}

DoubleThing::DoubleThing(const string& strVal)
	: DataThing()
{
	stringstream ss(strVal);
	double newVal;

	ss >> newVal;

	val = newVal;
}

DoubleThing::~DoubleThing() {}

DoubleThing::DoubleThing(const DoubleThing& s)
	: DataThing(s)
{
	val = s.val;
}

DoubleThing& DoubleThing::operator=(const DoubleThing& s) {
	val = s.val;

	return *this;
}


