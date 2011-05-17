
#include <iostream>
#include <queue>
#include <cstdlib>  // rand()
#include <sstream>

using namespace std;

/**
 * Simulate a battle between two armies using random numbers.
 *
 * USAGE:
 *
 * ./armies <number of soldiers>
 */
int main(int argc, char** argv)
{
	if (argc != 2) {
		cout << "USAGE:\n"
		   	 << "  ./armies <number of soldiers>\n";
		return 1;
	}

	srand(time(0));

	unsigned int num_soldiers;
	// The number of soldiers of each army,
	// also equals the number of battles.

	stringstream ss(argv[1]);
	ss >> num_soldiers;

	queue<unsigned int> army1;
	queue<unsigned int> army2;

	//unsigned int range = ((rand() % 91) + 10);  // 10 - 100
	unsigned int range = ((rand() % 41) + 10);  // 10 - 50
	cout << "range: " << range << "\n";

	// build the battles
	for (unsigned int i = 0; i < num_soldiers; i++) {
		army1.push(rand() % range);
		army2.push(rand() % range);
		// Reducing the range of possible numbers (rand() % 10)
		// increases the occurance of draws and vice versa.
	}

	int army1_wins = 0;
	int army2_wins = 0;
	int draws = 0;

	// compare the battles and calculate results
	double a, b;
	for (unsigned int i = 0; i < num_soldiers; i++) {
		a = army1.front();
		b = army2.front();

		if (a > b)
			army1_wins++;
		else if (a < b)
			army2_wins++;
		else
			draws++;

		army1.pop();
		army2.pop();
	}

	// display the results
	cout << num_soldiers << " battles have been fought\n"
		 << "Army 1 had " << army1_wins << " wins\n"
		 << "Army 2 had " << army2_wins << " wins\n"
		 << "and there were " << draws << " draws\n";
	if (army1_wins > army2_wins)
		cout << "Army 1 is the winner!\n";
	else if (army2_wins > army1_wins)
		cout << "Army 2 is the winner!\n";
	else
		cout << "Both armies tied!\n";

	return 0;
}

