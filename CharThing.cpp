
#include "CharThing.h"

CharThing::CharThing()
{
	val = 0;  // default
}

CharThing::CharThing(char newVal)
{
	val = newVal;
}

CharThing::CharThing(const string& strVal) {
	stringstream ss(strVal);
	char newVal;

	ss >> newVal;

	val = newVal;
}

CharThing::~CharThing() { }

string CharThing::print() const {
	stringstream ss;

	ss << DataThing::print();

	ss << val;

	return ss.str();
}

void CharThing::setValue(char newBVal) {
	val = newBVal;
}


char CharThing::getValue() const {
	return val;
}

CharThing& CharThing::operator=(const CharThing& s) {
	val = s.val;

	return *this;
}

ostream& operator<<(ostream& out, const CharThing& s) {
	out << s.print();

	return out;
}

bool operator==(const CharThing& lhs, const CharThing& rhs) {
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const CharThing& lhs, const CharThing& rhs) {
	return (lhs.getValue() < rhs.getValue());
}

bool operator<=(const CharThing& lhs, const CharThing& rhs) {
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>(const CharThing& lhs, const CharThing& rhs) {
	return (rhs.getValue() < lhs.getValue());
}

bool operator>=(const CharThing& lhs, const CharThing& rhs) {
	return (rhs.getValue() <= lhs.getValue());
}

bool operator!=(const CharThing& lhs, const CharThing& rhs) {
	return (rhs.getValue() != lhs.getValue());
}

