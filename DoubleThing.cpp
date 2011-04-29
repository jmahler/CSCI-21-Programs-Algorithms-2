
#include "DoubleThing.h"

DoubleThing::DoubleThing()
{
	val = 0;  // default
}

DoubleThing::DoubleThing(double newVal)
{
	val = newVal;
}

DoubleThing::DoubleThing(const string& strVal) {
	stringstream ss(strVal);
	double newVal;

	ss >> newVal;

	val = newVal;
}

DoubleThing::~DoubleThing() { }

string DoubleThing::print() const {
	stringstream ss;

	ss << DataThing::print();

	ss << val;

	return ss.str();
}

void DoubleThing::setValue(double newVal) {
	val = newVal;
}


double DoubleThing::getValue() const {
	return val;
}

DoubleThing& DoubleThing::operator=(const DoubleThing& s) {
	val = s.val;

	return *this;
}

ostream& operator<<(ostream& out, const DoubleThing& s) {
	out << s.print();

	return out;
}

bool operator==(const DoubleThing& lhs, const DoubleThing& rhs) {
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const DoubleThing& lhs, const DoubleThing& rhs) {
	return (lhs.getValue() < rhs.getValue());
}

bool operator<=(const DoubleThing& lhs, const DoubleThing& rhs) {
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>(const DoubleThing& lhs, const DoubleThing& rhs) {
	return (rhs.getValue() < lhs.getValue());
}

bool operator>=(const DoubleThing& lhs, const DoubleThing& rhs) {
	return (rhs.getValue() <= lhs.getValue());
}

bool operator!=(const DoubleThing& lhs, const DoubleThing& rhs) {
	return (rhs.getValue() != lhs.getValue());
}

