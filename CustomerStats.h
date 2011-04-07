#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <map>

#include "Customer.h"

using namespace std;

/**
 * Calculates statistics for a given group of Customers.
 */
class CustomerStats {
	private:
		int num_customers;
		map<string, int> type_count; 

		int n_queue_time;
		int sum_queue_time;

		int num_left;
	public:

	// {{{ CustomerStats() (constructor)
	/**
	 * Construct a CustomerStats() object.
	 */
	CustomerStats();
	// }}}

	// {{{ recordCustomer
	/**
	 * Update the statics by adding data from the given customer.
	 *
	 * @arg Customer
	 */
	void recordCustomer(Customer* cust);
	// }}}

	// {{{ operator<<
	/**
	 * Output operator for customer statistics.
	 *
	 * Displays various useful statistics and calculations
	 * such as the percentage of different types of customers,
	 * the number of customer served, the number of customers that
	 * left without buying, etc.
	 */
	friend ostream& operator<<(ostream& out, CustomerStats& cs)
	{
		string indent = "  ";

		out << endl
			<< "TYPE PERCENTAGES\n"
			<< endl;

		map<string, int>::iterator it;

		for (it = cs.type_count.begin(); it != cs.type_count.end(); it++) {
			float pcnt = (((float) ((*it).second)) / ((float) cs.num_customers)) * 100;
			out << fixed << setprecision(2)
				<< indent << (*it).first << ": " << pcnt << "%\n";
		}

		out << endl
			<< "GENERAL\n"
			<< endl
			<< indent << "number of customers: " << cs.num_customers << endl
			<< indent << "average queue time: " << ((float) (cs.sum_queue_time)) / ((float) cs.n_queue_time) << " [minutes]\n"
			<< indent << "number of customers that left (without buying): " << cs.num_left << endl
			<< endl;

		return out;
	}
	// }}}

};

// vim:foldmethod=marker
