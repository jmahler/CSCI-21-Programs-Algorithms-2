
#include "CustomerStats.h"

// {{{ CustomerStats
CustomerStats::CustomerStats()
{
	num_customers = 0;

	n_queue_time = 0;
	sum_queue_time = 0;

	num_left = 0;
}
// }}}

// {{{ recordCustomer
void CustomerStats::recordCustomer(Customer* cust) {

	num_customers++;

	// type_count
	{
	map<string, int>::iterator it;
	it = type_count.find(cust->getType());

	if (it != type_count.end()) {
		// found
		type_count[cust->getType()]++;
	} else {
		// not found
		type_count[cust->getType()] = 1;
	}
	}

	// average queue time
	{
		if (cust->beenServiced()) {
			sum_queue_time += (cust->getServiceTime() - cust->getArrivalTime());
			n_queue_time++;
		} else if (cust->hasDeparted()) {
			// left without being serviced
			sum_queue_time += (cust->getDepartedTime() - cust->getArrivalTime());
			n_queue_time++;

			num_left++;
		}
	}
}
// }}}

// vim:foldmethod=marker

