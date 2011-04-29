
#include "DataThing.h"

int DataThing::setid = 1;
bool DataThing::print_id = false;

DataThing::DataThing() {
	id = setid++;	
}

DataThing::DataThing(const DataThing& s) {
	id = s.id;
}

DataThing::~DataThing() {}

void DataThing::printIdOn() {
	print_id = true;
}

void DataThing::printIdOff() {
	print_id = false;
}

string DataThing::print() const {
	if (print_id) {
		stringstream ss;

		ss << "id=" << id << ";";

		return ss.str();
	}

	return "";
}

DataThing::DataThing(const int& newId) {
	id = newId;
}

DataThing& DataThing::operator=(const DataThing& s) {
	id = s.id;
	return *this;
}

int DataThing::getId() const {
	return id;
}

ostream& operator<<(ostream& out, const DataThing& s) {
	out << "id=" << s.getId() ;

	return out;
}

bool operator==(const DataThing& lhs, const DataThing& rhs) {
	return (lhs.getId() == rhs.getId());
}

bool operator<(const DataThing& lhs, const DataThing& rhs) {
	return (lhs.getId() < rhs.getId());
}

bool operator>(const DataThing& lhs, const DataThing& rhs) {
	return (rhs < lhs);
}

bool operator<=(const DataThing& lhs, const DataThing& rhs) {
	return ((lhs < rhs) && (lhs == rhs));
}

bool operator>=(const DataThing& lhs, const DataThing& rhs) {
	return (lhs > rhs && lhs == rhs);
}

bool operator!=(const DataThing& lhs, const DataThing& rhs) {
	return !(lhs == rhs);
}
