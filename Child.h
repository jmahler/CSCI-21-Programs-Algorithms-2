
#include <ctime>
#include <iostream>
#include <signal.h>
#include <string>
#include <unistd.h>

using namespace std;

class Child {
    int energy;
    static const int consumption_rate = 2; // 1 units engergy / x second
    //static const int consumption_rate = 120;  // 1 unit / 2 minutes
    string name;
    time_t last_ate;
    static const int max_energy = 10;

public:
    /**
     *
     *  Construct a child by initiating all values to defaults.
     *
     */
    Child();

    /**
     * Construct a child with name specified and the rest defaults.
     */
    Child(string name);

    /**
     * 
     * Construct a child with name specified and the initial energy given.
     *
     * @arg name
     * @arg energy, 1-10
     */
    Child(string name, int energy);

    ~Child();

    /**
     *
     * Try to feed the child 1 unit of food.
     * If it is not hungry the food will be rejected.
     * It may output a message as a response.
     *
     */
    void feed();

    /**
     *
     * Update the childs current energy level based on how long
     * it has been since they last ate.
     *
     * @returns true if child dies or is dead, false otherwise
     */
    bool updateEnergy();

    /**
     *
     * A child can only consume food at a maximum rate.
     * Calculate how long until it will next be able to eat.
     *
     * @return  time in seconds it should eat next, or 0 if it is overdue
     */
    time_t timeUntilNextEat();
};