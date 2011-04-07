#pragma once

#include <string>
#include <climits>  // INT_MAX

using namespace std;

/**
 * An object describing a Customer for a discrete event simulation.
 *
 * A customer goes through several states and with each
 * state is an associated time.
 *
\verbatim

                         arrived
                   (enter in to queue)
                            |
           +----------------+--------------+
           |                               |
        serviced                           |
   (assigned to a cashier)                 |
           |                               |
        departed                        departed
   (with a purchase)              (without a purchase)

\endverbatim
 *
 */
class Customer {
private:

protected:

	string type;
	int uid;

	int arrivalTime;
	int serviceTime;
	int departureTime;

	//bool arrived;
	bool serviced;
	bool departed;

	// Ival (interval)
	int serviceIval;
	int vipIval;
	int patienceIval;

public:

	// {{{ getType
	/**
	 * Get the type of this object.
	 *
	 * @returns string type
	 *
	 * The type can be used to identify the type of object if
	 * a dynamic_cast is necessary.
	 */
	string getType() {
		return type;
	}
	// }}}

	// {{{ Customer(int newArrivalTime) (constructor)
	/**
	 * Construct a new customer and specify their arrival time.
	 */
	Customer(int arrivalTime);
	/* }}} */

	virtual ~Customer() {};

	// {{{ setUid
	/**
	 * Set the unique id number for this customer.
	 *
	 * @arg int id
	 */
	void setUid(const int newUid) {
		uid = newUid;
	}
	// }}}

	// {{{ getUid
	/**
	 * Get the unique id number for this customer.
	 *
	 * @returns int id
	 */
	int getUid() {
		return uid;
	}
	// }}}


	// {{{ getArrivalTime()
	/**
	 * Get the time when the customer arrived.
	 *
	 * @returns int clock
	 */
	int getArrivalTime() {
		return arrivalTime;
	}
	// }}}

	// {{{ getServiceTime()
	/**
	 * Get the time when the customer was serviced.
	 *
	 * @returns int time
	 *
	 * If the value returned is 0 this may indicate that the
	 * customer has not been serviced yet.
	 * Use beenServiced() to test whether the customer has been serviced.
	 */
	int getServiceTime() {
		return serviceTime;
	}
	// }}}

	// {{{ getDepartedTime()
	/**
	 * Get the time when the customer departed.
	 *
	 * @returns departure time
	 *
	 * If the value returned is 0 this may indicate that the
	 * customer has not departed yet.
	 * Use hasDeparted() to test whether the customer has departed.
	 */
	int getDepartedTime() {
		return departureTime;
	}
	// }}}


	// {{{ setServiced(clock)
	/**
	 * Set the customer as having been serviced (queue -> cashier).
	 *
	 * @arg int clock
	 *
	 * A customer has "been serviced" when they have moved from
	 * the queue and assigned to a cashier.
	 */
	void setServiced(int clock) {
		serviced = true;
		serviceTime = clock;
	}
	// }}}

	// {{{ setDeparted(clock)
	/**
	 * Set the customer as departed (cashier -> departed || arrived -> departed).
	 *
	 * @arg int clock
	 */
	void setDeparted(int clock) {
		departed = true;
		departureTime = clock;
	}
	// }}}


	// {{{ beenServiced()
	/**
	 * Has this customer been serviced?
	 *
	 * @returns true if yes, false otherwise
	 *
	 * A customer has "been serviced" when they have moved from
	 * the queue and assigned to a cashier.
	 */
	bool beenServiced() {
		return serviced;
	}
	// }}}

	// {{{ hasDeparted()
	/**
	 * Has this customer departed?
	 *
	 * @returns true if yes, false otherwise
	 *
	 * A customer has "departed" when they have finished
	 * being served or if they have left the queue early.
	 */
	bool hasDeparted() {
		return departed;
	}
	// }}}


	// {{{ getServiceIval()
	/**
	 * Get the interval amount of time it will take to serve this customer.
	 * This could also be consider as the amount of time it takes the
	 * customer to make a decision.
	 *
	 * @returns int time interval
	 */
	int getServiceIval() {
		return serviceIval;
	}
	// }}}

	// {{{ setVipIval()
	/**
	 * The Vip time interval at which a vip customer
	 * will be moved to the front of the queue/line.
	 *
	 * @arg int time interval
	 *
	 * For example if a vip customer has waited for 10 minutes and
	 * the vip time is 10 minutes they would be moved to the front.
	 * Any time less than 10 minutes they would be left in the queue.
	 */
	void setVipIval(const int interval) {
		vipIval = interval;
	}
	// }}}

	// {{{ getVipIval()
	/**
	 * Get the Vip time.
	 * See also setVipIval().
	 *
	 * @returns int interval
	 *
	 */
	int getVipIval() {
		return vipIval;
	}
	// }}}

	// {{{ setPatience()
	/**
	 * Set the interval of time the customer is willing to wait before
	 * they lose their patience and leave.
	 *
	 * @arg int interval
	 */
	void setPatience(const int interval) {
		patienceIval = interval;
	}
	// }}}

	// {{{ getPatience()
	/**
	 * Get the customers patience level.
	 *
	 * @returns int patience
	 */
	int getPatience() {
		return patienceIval;
	}
	// }}}

};

// vim:foldmethod=marker
