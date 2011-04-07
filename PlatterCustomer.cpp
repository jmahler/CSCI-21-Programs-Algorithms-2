
#include "PlatterCustomer.h"

PlatterCustomer::PlatterCustomer(int newArrivalTime)
	: Customer(newArrivalTime)
{
	type = "platter";

	// 10% of these customers are VIPs and will be moved
	// to the front of the waiting line if they have been
	// waiting for more than 10 minutes
	if ((random() % 100) < 10) {
		vipIval = 10;
	}

	// time to serve set to random value between 5-7 minutes
	serviceIval = ((random() % 3) + 5);
}

