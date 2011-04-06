
#include <string>
#include <climits>  // INT_MAX

using namespace std;

/**
 * An object describing a Customer for a discrete
 * event simulation.
 */
class Customer {
private:

	string name;
	int uid;

	int timeToServe;
	int enterQueueTime;
	int leaveQueueTime;
	int serveTimeStart;
	int serveTimeEnd;
	bool served;

	// TODO move to subclass
	int decisionTime;
	int vipTime;
	int patience;


public:

	/** {{{ Customer() (constructor)
	 * Construct a new customer with default values.
	 * See set* operations for what values can be assigned.
	 */
	Customer() {
		// defaults
		name = "default";
		uid = 0;
		enterQueueTime = 0;
		timeToServe = 0;
		decisionTime = 0;
		vipTime = INT_MAX;
		serveTimeStart = 0;
		serveTimeEnd = 0;
		served = false;
	}
	/* }}} */

	/** {{{ setName
	 * Set the name of this customer.
	 *
	 * @arg string name
	 */
	void setName(const string newName) {
		name = newName;
	}
	/* }}} */

	/** {{{ getName
	 * Get the name of this customer.
	 *
	 * @returns string name
	 */
	string getName() {
		return name;
	}
	/* }}} */
	
	/** {{{ setUid
	 * Set the unique id number for this customer.
	 *
	 * @arg int id
	 */
	void setUid(const int newUid) {
		uid = newUid;
	}
	/* }}} */

	/** {{{ getUid
	 * Get the unique id number for this customer.
	 *
	 * @returns int id
	 */
	int getUid() {
		return uid;
	}
	/* }}} */

	/** {{{ setDecisionTime()
	 * Set the amount time it will take this customer to make a decision.
	 *
	 * @arg int time interval
	 *
	 * Other factors such as how proficient the cashier is may
	 * speed up this process.
	 * For example a more proficient cashier might be able to help
	 * a customer make their decision faster.
	 */
	void setDecisionTime(const int interval) {
		decisionTime = interval;
	}
	/* }}} */

	/** {{{ getDecisionTime()
	 * Get the amount of time it will take this customer to make a decision.
	 * See also setDecisionTime().
	 *
	 * @returns int time interval
	 */
	int getDecisionTime() {
		return decisionTime;
	}
	/* }}} */

	/** {{{ setTimeToServe()
	 * Set the time it will take to serve this customer.
	 *
	 * @arg int time interval
	 */
	void setTimeToServe(const int interval) {
		timeToServe = interval;
	}
	/* }}} */

	/** {{{ getTimeToServe()
	 * Get the time it will take to serve this customer.
	 *
	 * @returns int clock
	 */
	int getTimeToServe() {
		return timeToServe;
	}
	/* }}} */

	/** {{{ setEnterQueueTime 
     * Set the time when the customer entered the queue.
	 *
	 * @arg int clock
	 */
	void setEnterQueueTime(int clock) {
		enterQueueTime = clock;
	};
	/* }}} */

	/** {{{ getEnterQueueTime 
	 * Retrieve the time when the customer entered the queue.
	 *
	 * @returns int time
	 */
	int getEnterQueueTime() {
		return enterQueueTime;
	};
	/* }}} */

	/** {{{ setLeaveQueueTime 
     * Set the time when the customer left the queue.
	 *
	 * @arg int clock
	 */
	void setLeaveQueueTime(const int clock) {
		leaveQueueTime = clock;
	};
	/* }}} */

	/** {{{ getLeaveQueueTime 
     * Set the time when the customer left the queue.
	 *
	 * @returns int clock
	 */
	int getLeaveQueueTime() {
		return leaveQueueTime;
	};
	/* }}} */

	/** {{{ setServeTimeStart()
	 * Set the time when the customer starts being served.
	 *
	 * @arg int clock
	 */
	void setServeTimeStart(const int clock) {
		serveTimeStart = clock;

		served = true;
	}
	/* }}} */

	/** {{{ getServeTimeStart()
	 * Get the time when the customer started being served.
	 *
	 * @returns int time
	 */
	int getServeTimeStart() {
		return serveTimeStart;
	}
	/* }}} */

	/** {{{ setServeTimeEnd()
	 * Set the time when the customer has finished being served.
	 *
	 * @arg int clock
	 */
	void setServeTimeEnd(const int clock) {
		serveTimeEnd = clock;
	}
	/* }}} */

	/** {{{ getServeTimeEnd()
	 * Get the time when the customer has finished being served.
	 *
	 * @returns int clock
	 */
	int setServeTimeEnd() {
		return serveTimeEnd;
	}
	/* }}} */

	/** {{{ setVipTime()
	 * The Vip time interval at which a vip customer
	 * will be moved to the front of the queue/line.
	 *
	 * @arg int time interval
	 *
	 * For example if a vip customer has waited for 10 minutes and
	 * the vip time is 10 minutes they would be moved to the front.
	 * Any time less than 10 minutes they would be left in the queue.
	 */
	void setVipTime(const int interval) {
		vipTime = interval;
	}
	/* }}} */

	/** {{{ getVipTime()
	 * Get the Vip time.
	 * See also setVipTime().
	 *
	 * @returns int clock
	 *
	 */
	int getVipTime() {
		return vipTime;
	}
	/* }}} */

	/** {{{ setPatience()
	 * Set the customers patience level.
	 * Patience is defined here as the interval of the time the
	 * customer will wait in the queue before they leave.
	 *
	 * @arg int patience
	 *
	 */
	void setPatience(const int interval) {
		patience = interval;
	}
	/* }}} */

	/** {{{ getPatience()
	 * Get the customers patience level.
	 *
	 * @returns int patience
	 */
	int getPatience() {
		return patience;
	}
	/* }}} */

	/** {{{ beenServed()
	 * Has this customer been served?
	 *
	 * @returns true if yes, false otherwise
	 *
	 * A customer is considered to have been served once a serve
	 * time has been set (setServeStartTime()).
	 *
	 */
	bool beenServed() {
		return served;
	}
	/* }}} */


};

// vim:foldmethod=marker
