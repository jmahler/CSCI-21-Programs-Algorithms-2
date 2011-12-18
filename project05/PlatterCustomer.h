#pragma once

#include "Customer.h"
#include <cstdlib>

/**
 * A PlatterCustomer is a specialized instance of a Customer.
 *
 * Internal times are randomly set by using random() provided by cstdlib.
 * The random number seed must be initialized elsewhere.
 *
 */
class PlatterCustomer : public Customer {
private:

public:

	/**
	 * Construct a new PlatterCustomer by specifying the arrival time.
	 *
	 * @arg arrival time
	 */
	PlatterCustomer(int newArrivalTime);

};

