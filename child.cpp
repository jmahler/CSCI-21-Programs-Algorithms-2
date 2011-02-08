
#include <signal.h>
#include <unistd.h>
#include <ctime>

#include <iostream>
#include <string>

using namespace std;

volatile int hunger = 5; // initial hunger level
volatile int t = time(NULL);

/**
 *
 * Signal handler for consuming food when hungry or
 * rejecting it when it is not.
 *
 */
static void food(int sig, siginfo_t *signinfo, void *context)
{
    if (hunger >= 7) {
        cout << "Yuck, I'm not hungry!\n";
    } else {
        hunger += 1;
        cout << "Yummy\n";
    }

    return;
}

static void update(int sig, siginfo_t *siginfo, void *context)
{
}

/**
 *
 * Creates a new child that must be fed before it starves.
 *
 * The child is fed by sending it the HUP signal.
 * 1 signal is equal to 1 unit of food.
 * @verbatim
    kill -HUP <pid>
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

    t = time(NULL);
    t -= 10;

    sa_food.sa_sigaction = &food;
    sigemptyset(&sa_food.sa_mask);
    sa_food.sa_flags = 0;

    sa_update.sa_sigaction = &update;
    sigemptyset(&sa_update.sa_mask);
    sa_update.sa_flags = 0;

    sigaction(SIGHUP, &sa_food, NULL);
    sigaction(SIGALRM, &sa_update, NULL);

    /*
    if (argc == 2) {
        name = argv[1];
        //cout << "USAGE: a.out <name>\n";
        //return(1);
    } else {
        name = "John Doe";
    }
    */

    // check the status periodically
    while (1) {
        time_t now = time(NULL);

        // decrease the hunger periodically
        if ((now - t) >= 2) {
            if (--hunger < 0) {
                cout << "Good bye cruel world :-(\n";
                return 1;
            }

            cout << "munch, munch (" << hunger << ")\n";
            t = time(NULL);  // reset
        }

        alarm(2); // seconds
        pause();
    }

    return 0;
}

