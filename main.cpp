/**
 * @mainpage
 *
 * A discrete event simulation of a simplified burger restaurant.
 *
 *
 * This program was completed for "project 5" of the
 * class CSCI 21 taught by <a href="http://www.foobt.net">Boyd Trolinger</a>
 * at <a href="http://www.butte.edu">Butte College</a> during Spring 2011.<br>
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
	int rate = 80;  // rate of incoming customers /100

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
		<< "  -r <%>                probability of new customer 1-100%\n"
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

				if (end_time <= 0) {
					cerr << " option -t, time must be greater than or equal to 1\n";
					return 1;
				}
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

				if (num_cashiers <= 0) {
					cerr << " option -c, number of cashiers must be greater than or equal to 1\n";
					return 1;
				}
			} else {
				cerr << " option -c requires an argument\n";
				return 1;
			}
		} else if (arg0 == "-r") {
			if ((i + 1) < argc) {
				i++;
				string arg1(argv[i]);
				stringstream si(arg1);
				si >> rate;

				if (rate <= 0 || rate > 100) {
					cerr << " option -r, rate must be from 1 to 100 (%)\n";
					return 1;
				}

				rate -= 1; // adjust for 1 to 100 -> 0 to 99
			} else {
				cerr << " option -r requires an argument\n";
				return 1;
			}
		}

	}
	// }}}

	int clock = 0;
	int uid_alloc = 1;
	srandom(time(0));


	Queue<Customer*> waitingLine;
	CustomerStats custStats;

	Customer** cashiers = new Customer*[num_cashiers];
	for (int i = 0; i < num_cashiers; i++) {
		cashiers[i] = NULL;
	}


	while (++clock <= end_time) {
		if (VERBOSE)
			cout << "CLOCK: " << clock << endl;

		// {{{ new customer?
		if ((random() % 100) < rate) {
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

			waitingLine.push_back(new_customer); // to the end of the line
		}
		// }}}

		// {{{ are any cashiers finished with customers?
		for (int i = 0; i < num_cashiers; i++) {

			if (cashiers[i] != NULL) {
				Customer* cust = cashiers[i];

				int si = cust->getServiceIval();
				int st = cust->getServiceTime();

				if (clock >= (st + si)) {
					if (VERBOSE)
						cout << "customer " << cust->getUid() << " served, " << "cashier " << i << " now available\n";

					cust->setDeparted(clock);

					custStats.recordCustomer(cust);

					delete cust;

					cashiers[i] = NULL;  // cashier now available
				} else {
					if (VERBOSE)
						cout << "cashier " << i << " serving customer " << cust->getUid() << ", time left: " << ((st + si) - clock) << endl;
				}
			}
		}
		// }}}

		// {{{ check for VIP's, move to front
		{
		Queue<Customer*>::iterator ic;
		int i = 0;	

		for (ic = waitingLine.begin(), i = 0; ic < waitingLine.end(); ic++, i++) {

			int at = (*ic)->getArrivalTime();
			int vipi = (*ic)->getVipIval();

			if ((clock - at) > vipi) {
				waitingLine.to_front(ic);

				if (VERBOSE)
					cout << "VIP customer " << (*ic)->getUid() << " has waited over " << vipi << " minutes; moving to front\n";

				ic = waitingLine.begin() + i;  // fix invalidated iterator
			}
		}
		}
		// }}}

		// {{{ assign waiting customers to open cashiers
		{
		int num_waiting = waitingLine.size();

		if (VERBOSE)
			cout << num_waiting << " customers waiting.\n";

		for (int i = 0; (i < num_cashiers) && (num_waiting > 0); i++) {
			if (cashiers[i] == NULL) {  // a cashier is open

				Customer* c = waitingLine.front();
				c->setServiced(clock);

				if (VERBOSE)
					cout << "assigned customer " << c->getUid() << " to cashier " << i << endl;

				// assign customer at front to a cashier
				cashiers[i] = c;

				// remove customer from queue
				waitingLine.pop_front();

				num_waiting--;
			}
		}
		}
		// }}}

		// {{{ have any impatient customers left?
		{
		Queue<Customer*>::iterator ic;
		int i = 0;	

		for (ic = waitingLine.begin(), i = 0; ic < waitingLine.end(); ic = waitingLine.begin() + i) {

			int at = (*ic)->getArrivalTime();
			int pt = (*ic)->getPatience();

			if ((clock - at) > pt) {

				if (VERBOSE)
					cout << "customer " << (*ic)->getUid() << " has lost their patience and left" << endl;

				(*ic)->setDeparted(clock);

				custStats.recordCustomer(*ic);

				delete (*ic);

				waitingLine.erase(ic);
				// invalidates pointer, fixed in for loop

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

	// CustomerStats takes care of most of the statistics but
	// it only has access to the departed customers.
	// Any additional statistics must be calculated here.

	int num_being_served = 0;
	for (int i = 0; i < num_cashiers; i++) {
		if (cashiers[i] != NULL) {
			num_being_served++;
		}
	}

	int num_in_queue = waitingLine.size();

	cout 
		<< endl
		<< "              ***  SIMULATION COMPLETE ***\n"
		<< endl
		<< "simulation time: " << end_time << endl
		<< "number of cashiers: " << num_cashiers << endl
		<< "number of customers still being served: " << num_being_served << endl
		<< "number of customers still in queue: " << num_in_queue << endl
		<< "probability of new customer arriving: " << (rate + 1) << "%" << endl
		<< custStats;
	// }}}

	delete[] cashiers;

	return 0;  // OK
}

// vim:foldmethod=marker
