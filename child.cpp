
#include "Child.h"

#include <ctime>
#include <iostream>
#include <signal.h>
#include <string>
#include <unistd.h>

using namespace std;

Child *child;

/**
 *
 * Signal handler for consuming food when hungry or
 * rejecting it when it is not.
 *
 */
static void food(int sig, siginfo_t *signinfo, void *context);

/**
 * Called during a SIGALARM.
 * Currently used to break out of a pause() (see main below).
 */
static void update(int sig, siginfo_t *siginfo, void *context) {}

/**
 *
 * Creates a new child that must be fed before it starves.
 *
 * @verbatim
   child        # a random name
   child <name>
 * @endverbatim
 * The child is fed by sending it the HUP signal.
 * 1 signal is equal to 1 unit of food.
 *
 * @verbatim
    kill -HUP <pid>
    killall -HUP child
 * @endverbatim
 *
 * @arg name of new child 
 *
 */
int main(int argc, char** argv)
{
    struct sigaction sa_food;
    struct sigaction sa_update;
    string name;

    sa_food.sa_sigaction = &food;
    sigemptyset(&sa_food.sa_mask);
    sa_food.sa_flags = 0;

    sa_update.sa_sigaction = &update;
    sigemptyset(&sa_update.sa_mask);
    sa_update.sa_flags = 0;

    sigaction(SIGHUP, &sa_food, NULL);
    sigaction(SIGALRM, &sa_update, NULL);

    if (argc == 2) {
        child = new Child(argv[1]);
    } else {
        child = new Child();
    }

    // check the status periodically
    while (1) {
        time_t next;

        if (child->updateEnergy()) {
            break; 
        }

        next = child->timeUntilNextEat();

        if (next > 0) {
            alarm(next); // seconds
            pause();
        }
    }

    delete child;

    return 0;
}


static void food(int sig, siginfo_t *signinfo, void *context)
{
    child->feed();
}
