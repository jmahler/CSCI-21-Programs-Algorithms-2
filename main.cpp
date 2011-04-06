
#include <iostream>
#include <stdlib.h>  // random()
#include <vector>

#include "Customer.h"
#include "Queue.h"

using namespace std;

int main(int argc, char** argv) {

	// config, TODO
	int end_time = 100;
	int num_cashiers = 1;
	const bool DEBUG = true;

	int clock = 0;
	int uid_alloc = 1;

	srandom(time(0));

	if (DEBUG) {
		cout << "num cashiers: " << num_cashiers << endl
			 << "simulation time: " << end_time << endl
			 << endl;
	}

	Queue<Customer*> queue;
	vector<Customer*> customer_history;
	Customer** cashiers = new Customer*[num_cashiers];

	while (++clock <= end_time) {
		if (DEBUG)
			cout << "CLOCK: " << clock << endl;

		// {{{ new customer?
		if ((random() % 100) < 50) {
			if (DEBUG)
				cout << "new customer\n";

			// new customer
			Customer* new_customer = new Customer();

			new_customer->setEnterQueueTime(clock);
			new_customer->setUid(uid_alloc++);

			/* 50% hamburger
			 * 35% milkshake
			 * 15% platter
			 * The total percent probablity should add to 100%
			 */
			int rt = (random() % 100);

			if (rt < 15) { // 15%
				// platter
				new_customer->setName("platter");

				// time to serve set to random value between 5-7 minutes
				new_customer->setTimeToServe((random() % 2) + 2);

				// 10% of these customers are VIPs and will be moved
				// to the front of the waiting line if they have been
				// waiting for more than 10 minutes
				if ((random() % 100) < 10) {
					new_customer->setVipTime(10);
				}

			} else if (rt < (15 + 35)) {  // 35%
				// milkshake
				new_customer->setName("milkshake");

				// time to serve set to random value between 2-3 minutes
				new_customer->setTimeToServe((random() % 2) + 2);

				// 50% of these customers will give up and
				// depart the waiting line if they have to wait more
				// than 10 minutes.
				if ((random() % 100) < 50) {
					new_customer->setPatience(10);
				}

			//} else if (rt < (15 + 35 + 50)) {  // 50%
			} else {
				// hamburger
				new_customer->setName("hamburger");

				// random service time modifier between 0-5 to
				// represent their lack of decisiveness
				new_customer->setDecisionTime((random() % 6));

				// time to serve set to random value between 3-5 minutes
				new_customer->setTimeToServe((random() % 3) + 3);
			}

			queue.push_back(new_customer); // to back of queue
		}

		// }}}
	
		// {{{ are any cashiers finished with customers?
		for (int i = 0; i < num_cashiers; i++) {
			Customer* cust = cashiers[i];

			if (cust != NULL) {
				int ts = cust->getTimeToServe();
				int sts = cust->getServeTimeStart();

				if (DEBUG)
					cout << "cashier " << i << " serving customer " << cust->getUid() << ", time left: " << ((sts + ts) - clock) << endl;
				
				if ((clock - sts) >= ts) {
					if (DEBUG)
						cout << "customer " << cust->getUid() << " served, " << "cashier " << i << " now available\n";

					// you've been served!
					cust->setServeTimeEnd(clock);

					// record
					customer_history.push_back(cust);

					cashiers[i] = NULL;  // cashier now available
				}
			}
		}
		// }}}

		// {{{ check for VIP's, move to front
		{
		Queue<Customer*>::iterator ic;
		int i = 0;	

		for (ic = queue.begin(), i = 0; ic < queue.end(); ic++, i++) {

			int eqt = (*ic)->getEnterQueueTime();
			int vipt = (*ic)->getVipTime();

			if ((clock - eqt) > vipt) {
				queue.to_front(ic);

				if (DEBUG)
					cout << "vip customer " << (*ic)->getUid() << " has waited over " << vipt << " minutes; moving to front\n";

				ic = queue.begin() + i;  // fix invalidated iterator
			}
		}
		}
		// }}}

	// {{{ assign waiting customers to open cashiers
	{
	int num_waiting = queue.size();

	if (DEBUG)
		cout << num_waiting << " customers waiting.\n";

	for (int i = 0; (i < num_cashiers) && (num_waiting > 0); i++) {
		if (cashiers[i] == NULL) {  // a cashier is open

			Customer* c = queue.front();
			c->setLeaveQueueTime(clock);
			c->setServeTimeStart(clock);

			if (DEBUG)
				cout << "assigned customer " << c->getUid() << " to cashier " << i << endl;

			// assign customer at front to a cashier
			cashiers[i] = c;

			// remove customer from queue
			queue.pop_front();

			num_waiting--;
		}
	}
	}
	// }}}

	// {{{ have any impatient customers left?
	{
	Queue<Customer*>::iterator ic;
	int i = 0;	

	for (ic = queue.begin(), i = 0; ic < queue.end(); ic++, i++) {

		int eqt = (*ic)->getEnterQueueTime();
		int pt = (*ic)->getPatience();

		if ((clock - eqt) > pt) {

			if (DEBUG)
				cout << "customer " << (*ic)->getUid() << " has lost their patience and left" << endl;

			(*ic)->setLeaveQueueTime(clock);

			customer_history.push_back(*ic);

			queue.erase(ic);

			ic = queue.begin() + i;  // fix invalidated iterator
		}
	}
	}
	// }}}

	}

	// {{{ summary
	{
	int num_left = 0;    // left queue without buying
	float pcnt_num_left;
	int num_in_queue = queue.size();
	int num_being_served = 0;
	int num_served = customer_history.size();  // complete
	int total_num_customers;
	float avg_queue_time = 0;

	float pcnt_milkshakes = 0;
	float pcnt_platters = 0;
	float pcnt_hamburgers = 0;

	Queue<Customer*>::iterator ic;
	for (ic = queue.begin(); ic < queue.end(); ic++) {
		Customer* cust = (*ic);

	}

	{
	unsigned int sum_queue_time = 0;
	int n_queue_time = 0;

	int num_milkshakes = 0;
	int num_platters = 0;
	int num_hamburgers = 0;

	vector<Customer*>::iterator ic;
	for (ic = customer_history.begin(); ic < customer_history.end(); ic++) {
		Customer* c = (*ic);

		if (c->beenServed()) {
			sum_queue_time += (c->getLeaveQueueTime() - c->getEnterQueueTime());
			n_queue_time++;
		} else {
			num_left++;	
		}

		if ("milkshake" == c->getName()) {
			num_milkshakes++;
		} else if ("platter" == c->getName()) {
			num_platters++;
		} else if ("hamburger" == c->getName()) {
			num_hamburgers++;
		}
	}

	avg_queue_time = ((float) (sum_queue_time)) / ((float) n_queue_time);

	pcnt_milkshakes = (((float) (num_milkshakes)) / ((float) num_served)) * 100;
	pcnt_platters = (((float) (num_platters)) / ((float) num_served)) * 100;
	pcnt_hamburgers = (((float) (num_hamburgers)) / ((float) num_served)) * 100;

	}

	pcnt_num_left = (( (float) num_left) / ((float) num_served)) * 100;

	for (int i = 0; i < num_cashiers; i++) {
		if (cashiers[i] != NULL) {
			num_being_served++;
		}
	}

	cout << endl;
	cout << "Summary:\n";
	cout << endl;
	cout << "number currently in queue: " << num_in_queue << endl;
	cout << "number being served: " << num_being_served << endl;
	cout << endl;
	cout << "time elapsed (minutes): " << (clock - 1) << endl;
	cout << "number of cashiers: " << num_cashiers << endl;
	cout << "number served: " << num_served << endl;
	cout << "number left (without being served): " << num_left << " (" << pcnt_num_left << "%)\n";
	cout << "average time in queue: " << avg_queue_time << " (minutes) " << endl;
	cout << "percent hamburgers: " << pcnt_hamburgers << " % " << endl;
	cout << "percent milkshakes: " << pcnt_milkshakes << " % " << endl;
	cout << "percent platters: " << pcnt_platters << " % " << endl;


	}
	// }}}

	delete[] cashiers;

	return 0;  // OK
}

// vim:foldmethod=marker
