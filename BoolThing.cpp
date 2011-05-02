
#include "BoolThing.h"

BoolThing::BoolThing()
{
	val = false;  // default
}

BoolThing::BoolThing(const bool newVal)
	: DataThing<bool>()
{
	val = newVal;
}

BoolThing::BoolThing(const string& strVal)
	: DataThing<bool>()
{
	if (strVal == "true")
		val = true;
	else
		val = false;
}

BoolThing::~BoolThing() {}

BoolThing::BoolThing(const BoolThing& s)
	: DataThing<bool>(s)
{
	val = s.val;
}

BoolThing& BoolThing::operator=(const BoolThing& s)
{
	val = s.val;

	return *this;
}

string BoolThing::print() const {
	stringstream ss;

	if (this->getPrintId()) {
		ss << "id=" << this->getId() << ";";
	}

	if (val)
		ss << "true";
	else
		ss << "false";

	return ss.str();
}

