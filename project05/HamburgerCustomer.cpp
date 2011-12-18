
#include "HamburgerCustomer.h"

HamburgerCustomer::HamburgerCustomer(int newArrivalTime)
	: Customer(newArrivalTime)
{
	type = "hamburger";

	// time to serve set to random value between 3-5 minutes
	serviceIval = ((random() % 3) + 3);

	// The service time interval modifier adds 0-5 minutes
	// representing their lack of decisiveness (wishy washy)
	serviceIval += (random() % 6);
}

