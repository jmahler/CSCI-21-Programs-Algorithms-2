
#include <ctime>    // time()
#include <iostream>
#include <string>

#include <stdlib.h> // random()

using namespace std;

class Pet {

    static const int max_energy = 10;
    static const int consumption_rate = 1; // 1 units engergy / x second
    //static const int consumption_rate = 120;  // 1 unit / 2 minutes

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
     */
    Pet(string name);

    /**
     * When the Pet object is destroy a message will be displayed
     * such as "Spot has passed out".
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
     * Try to feed the pet 1 unit of food.
     * If it is not hungry the food will be rejected.
     * It may output a message as a response.
     *
     */
    void feed();

    /**
     *
     * Refresh the pets current energy level based on how long
     * it has been since they last ate.
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
     */
    bool isAlive() { return (energy > 0 ? true : false); };
    bool isDead() { return (! this->isAlive()); };
};
