
#include "MilkshakeCustomer.h"

MilkshakeCustomer::MilkshakeCustomer(int newArrivalTime)
		: Customer(newArrivalTime)
{
	type = "milkshake";

	// 50% of these customers will give up and
	// depart the waiting line if they have to wait more
	// than 10 minutes.
	if ((random() % 100) < 50) {
		patienceIval = 10;
	}

	// time to serve set to random value between 2-3 minutes
	serviceIval = ((random() % 2) + 2);
}

