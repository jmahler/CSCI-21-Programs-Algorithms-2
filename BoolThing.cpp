
#include "BoolThing.h"

BoolThing::BoolThing()
{
	val = false;  // default
}

BoolThing::BoolThing(bool newVal)
{
	val = newVal;
}

BoolThing::BoolThing(const string& newVal) {
	if (newVal == "true")
		val = true;
	else
		val = false;
}

BoolThing::~BoolThing() { }

string BoolThing::print() const {
	stringstream ss;

	ss << DataThing::print();

	if (val)
		ss << "true";
	else
		ss << "false";

	return ss.str();
}

void BoolThing::setValue(bool newBVal) {
	val = newBVal;
}


bool BoolThing::getValue() const {
	return val;
}

BoolThing& BoolThing::operator=(const BoolThing& s) {
	val = s.val;

	return *this;
}

ostream& operator<<(ostream& out, const BoolThing& s) {
	out << s.print();

	return out;
}

bool operator==(const BoolThing& lhs, const BoolThing& rhs) {
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const BoolThing& lhs, const BoolThing& rhs) {
	return (lhs.getValue() < rhs.getValue());
}

bool operator<=(const BoolThing& lhs, const BoolThing& rhs) {
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>(const BoolThing& lhs, const BoolThing& rhs) {
	return (rhs.getValue() < lhs.getValue());
}

bool operator>=(const BoolThing& lhs, const BoolThing& rhs) {
	return (rhs.getValue() <= lhs.getValue());
}

bool operator!=(const BoolThing& lhs, const BoolThing& rhs) {
	return (rhs.getValue() != lhs.getValue());
}

