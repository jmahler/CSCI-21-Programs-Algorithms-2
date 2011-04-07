/**
 * @mainpage
 *
 * A discrete event simulation of a simplified burger restaurant.
 *
 *
 * This program was completed for "project 5" of the
 * class CSCI 21 taught by <a href="http://www.foobt.net">Boyd Trolinger</a>
 * at <a href="http://www.butte.edu">Butte College</a> during Spring 2011.
 *
 * Detailed application requirements are available
 * at [<a href="http://foobt.net/csci21/S3513_11/labs/lab5.html">csci21/S3513_11/labs/lab5</a>]
 * and duplicated with this source [lab5.html].
 *
 * @author  Jeremiah Mahler <jmmahler@gmail.com>
 */

#include <iostream>
#include <sstream>
#include <cstdlib>  // random()
#include <vector>

#include "Customer.h"
#include "CustomerStats.h"
#include "HamburgerCustomer.h"
#include "MilkshakeCustomer.h"
#include "PlatterCustomer.h"
#include "Queue.h"

using namespace std;

int main(int argc, char* argv[]) {

	// global configs with default values,
	// altered by command line arguments
	int end_time = 100;
	int num_cashiers = 2;
	bool VERBOSE = false;

	// {{{ process command line arguments
	string usage;
	{
	stringstream ssu(stringstream::out);
	ssu << "USAGE:\n"
		<< "  ./main [args]\n"
		<< endl
		<< "  -h                    help screen\n"
		<< "  -v                    verbose output\n"
		<< "  -t <time>             length of time simulation should run\n"
		<< "  -c <num cashiers>     number of cashiers\n"
		<< endl;
	usage = ssu.str();
	}

	for (int i = 1; i < argc; i++) {
		string arg0(argv[i]);

		if (arg0 == "-h") {
			cout << usage;
			return 0;
		} else if (arg0 == "-v") {
			VERBOSE = true;
		} else if (arg0 == "-t") {
			if ((i + 1) < argc) {
				i++;
				string arg1(argv[i]);
				stringstream si(arg1);
				si >> end_time;
			} else {
				cerr << " option -t requires an argument\n";
				cerr << usage;
				return 1;
			}
		} else if (arg0 == "-c") {
			if ((i + 1) < argc) {
				i++;
				string arg1(argv[i]);
				stringstream si(arg1);
				si >> num_cashiers;
			} else {
				cerr << " option -c requires an argument\n";
				cerr << usage;
				return 1;
			}
		}
	}
	// }}}

	int clock = 0;
	int uid_alloc = 1;

	srandom(time(0));

	if (VERBOSE) {
		cout << "num cashiers: " << num_cashiers << endl
			 << "simulation time: " << end_time << endl
			 << endl;
	}

	Queue<Customer*> queue;
	CustomerStats custStats;

	Customer** cashiers = new Customer*[num_cashiers];
	for (int i = 0; i < num_cashiers; i++) {
		cashiers[i] = NULL;
	}

	while (++clock <= end_time) {
		if (VERBOSE)
			cout << "CLOCK: " << clock << endl;

		// {{{ new customer?
		if ((random() % 100) < 50) {
			if (VERBOSE)
				cout << "new customer\n";

			// new customer
			Customer* new_customer;
			// the dynamic object is created below for the specific type

			/* 50% hamburger
			 * 35% milkshake
			 * 15% platter
			 * The total percent probability should add to 100%
			 */
			int rt = (random() % 100);

			if (rt < 15) { // 15%
				new_customer = new PlatterCustomer(clock);
			} else if (rt < (15 + 35)) {  // 35%
				new_customer = new MilkshakeCustomer(clock);
			//} else if (rt < (15 + 35 + 50)) {  // 50%
			} else {
				new_customer = new HamburgerCustomer(clock);
			}

			new_customer->setUid(uid_alloc++);

			queue.push_back(new_customer); // to the end of the line
		}
		// }}}

		// {{{ are any cashiers finished with customers? XXX
		for (int i = 0; i < num_cashiers; i++) {

			if (cashiers[i] != NULL) {
				Customer* cust = cashiers[i];

				int si = cust->getServiceIval();
				int st = cust->getServiceTime();

				if (VERBOSE)
					cout << "cashier " << i << " serving customer " << cust->getUid() << ", time left: " << ((st + si) - clock) << endl;
				
				if (clock >= (st + si)) {
					if (VERBOSE)
						cout << "customer " << cust->getUid() << " served, " << "cashier " << i << " now available\n";

					cust->setDeparted(clock);

					custStats.recordCustomer(cust);

					delete cust;

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

		int at = (*ic)->getArrivalTime();
		int vipi = (*ic)->getVipIval();

		if ((clock - at) > vipi) {
			queue.to_front(ic);

			if (VERBOSE)
				cout << "VIP customer " << (*ic)->getUid() << " has waited over " << vipi << " minutes; moving to front\n";

			ic = queue.begin() + i;  // fix invalidated iterator
		}
	}
	}
	// }}}

	// {{{ assign waiting customers to open cashiers
	{
	int num_waiting = queue.size();

	if (VERBOSE)
		cout << num_waiting << " customers waiting.\n";

	for (int i = 0; (i < num_cashiers) && (num_waiting > 0); i++) {
		if (cashiers[i] == NULL) {  // a cashier is open

			Customer* c = queue.front();
			c->setServiced(clock);

			if (VERBOSE)
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

	for (ic = queue.begin(), i = 0; ic < queue.end(); ic = queue.begin() + i) {

		int at = (*ic)->getArrivalTime();
		int pt = (*ic)->getPatience();

		if ((clock - at) > pt) {

			if (VERBOSE)
				cout << "customer " << (*ic)->getUid() << " has lost their patience and left" << endl;

			(*ic)->setDeparted(clock);

			custStats.recordCustomer(*ic);

			delete (*ic);

			queue.erase(ic);

			// since we erased a position, the current position is the next
			// i = i;
		} else {
			i++;
		}
	}
	}
	// }}}

	}

	// {{{ summary
	int num_being_served = 0;
	for (int i = 0; i < num_cashiers; i++) {
		if (cashiers[i] != NULL) {
			num_being_served++;
		}
	}

	int num_in_queue = queue.size();

	cout 
		<< endl
		<< "              ***  SIMULATION COMPLETE ***\n"
		<< endl
		<< "simulation time: " << end_time << endl
		<< "number of cashiers: " << num_cashiers << endl
		<< "number of customers still being served: " << num_being_served << endl
		<< "number of customers still in queue: " << num_in_queue << endl
		<< custStats;
	// }}}

	delete[] cashiers;

	return 0;  // OK
}

// vim:foldmethod=marker
