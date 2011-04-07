#pragma once

#include "Customer.h"
#include <cstdlib>

/**
 * A HamburgerCustomer is a specialized instance of a Customer.
 *
 * Internal times are randomly set by using random() provided by cstdlib.
 * The random number seed must be initialized elsewhere.
 */
class HamburgerCustomer : public Customer {
private:

public:
	/**
	 * Construct a HamburgerCustomer by specifying the arrival time.
	 *
	 * @arg arrival time
	 */
	HamburgerCustomer(int newArrivalTime);
};

