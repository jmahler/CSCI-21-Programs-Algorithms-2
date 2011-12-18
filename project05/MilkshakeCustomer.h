#pragma once

#include "Customer.h"
#include <cstdlib>

/**
 * A MilkshakeCustomer is a specialized instance of a Customer.
 *
 * Internal times are randomly set by using random() provided by cstdlib.
 * The random number seed must be initialized elsewhere.
 */
class MilkshakeCustomer : public Customer {
private:

public:
	/**
	 * Construct a new Milkshake customer by specifying the arrival time.
	 *
	 * @arg arrival time
	 */
	MilkshakeCustomer(int newArrivalTime);
};

