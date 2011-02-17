
#include <ctime>    // time()
#include <iostream>
#include <string>

#include <stdlib.h> // random()

using namespace std;

/**
 * The Pet class is used for creating and updating pets.
 * Each pet has a name and a energy level that
 * decreases over time until they starve and die.
 *
 * @author Jeremiah Mahler <jmmahler@gmail.com>
 * @version 0.01
 */
class Pet {

    static const int max_energy = 10;
    //static const int consumption_rate = 5;    // 1 units engergy / x second
    static const int consumption_rate = 120;  // 1 unit / 2 minutes

    int energy;
    string name;
    time_t last_ate;

    /*
     * a random energy value between 5 and 10
     */
    int rand_energy() {
        return (random() % 6 + 5); // 5 to 10
    }

public:
    /**
     *  Construct a pet by initiating all values to defaults.
     */
    Pet();

    /**
     * Construct a pet with name specified and the rest defaults.
     *
     * @arg name of pet
     */
    Pet(string name);

    /**
     * When the Pet object is destroyed a message will be displayed
     * such as "Spot has passed out" where "Spot" is the name of the pet.
     */
    ~Pet();

    /**
     * @returns the name of the pet
     */
    string getName() { return name; };

    /**
     * @returns time, in number of seconds since the Epoch, when the pet last ate.
     */
    time_t getTimeLastAte() { return last_ate; };

    /**
     * @returns the current energy level.
     */
    time_t getEnergy() { return energy; };

    /**
     *
     * Try to feed the pet one unit of food.
     * If it is not hungry the food will be rejected
     * and it may output a message describing why.
     *
     */
    void feed();

    /**
     *
     * Refresh the pets current energy level based on how long
     * it has been since it last ate.
     *
     * @returns true if pet dies or is dead, false otherwise
     */
    bool refresh(time_t time = time(0));

    /**
     *
     * A pet can only consume food at a maximum rate.
     * Calculate how long until it will next be able to eat.
     *
     * @return  time in seconds it should eat next, or 0 if it is overdue
     */
    time_t timeUntilNextEat();

    /**
     *
     * Is the pet alive?
     * Current as of the last refresh().
     *
     * @returns true if pet is alive, false otherwise
     */
    bool isAlive() { return (energy > 0 ? true : false); };

    /**
     * Is the pet dead?
     * Current as of the last refresh().
     *
     * @returns true if pet is dead, false otherwise
     */
    bool isDead() { return (! this->isAlive()); };
};
