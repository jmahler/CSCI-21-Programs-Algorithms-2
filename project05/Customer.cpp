
#include "Customer.h"

// {{{ Customer(int)
Customer::Customer(int newArrivalTime)
{
		type = "default";
		uid  = 0;

		arrivalTime   = newArrivalTime;
		serviceTime   = 0;
		departureTime = 0;

		//arrived = true;
		serviced = false;
		departed = false;

		serviceIval  = 0;
		vipIval      = INT_MAX;
		patienceIval = INT_MAX;
}
// }}}

// vim:foldmethod=marker
