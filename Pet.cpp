
#include "Pet.h"

// {{{ Pet::Pet(), etc
Pet::Pet()
{
    name = "John Doe";
    energy = rand_energy();
    last_ate = time(0);
}

Pet::Pet(string _name)
{
    name = _name;
    energy = rand_energy();
    last_ate = time(0);
}

Pet::~Pet()
{
    cerr << name << " has passed out.\n";
}
// }}}

// {{{ Pet::feed()
void Pet::feed()
{
    if (energy >= max_energy) {
        cout << "No thanks, I'm not hungry (" << name << ").\n";
    } else {
        energy += 1;
        cout << "Thank You (" << name << ").\n";
    }
}
// }}}

// {{{ Pet::refresh(time_t now)
bool Pet::refresh(time_t now)
{
    // If the pet is dead it is pointless to do
    // anything else.
    if (energy < 0)
        return true; // is dead

    time_t d = now - last_ate;
    int n = d / consumption_rate;

    //cout << "energy: " << energy << "\n";

    if (n > 0) {
        energy -= n;

//        if (3 == energy)
//            cout << "I'm kinda hungry.\n";

        if (2 == energy)
            cout << "I'm starving! (" << name << ").\n";

        if (1 == energy)
            cout << "I'm sleepy (" << name << ").\n";

        if (n <= 0) {
            return true; // died
        } else {
            //cout << "munch, munch, munch...\n";

            last_ate = now;  // reset
        }
    }

    return false;  // still alive
}
// }}}

// {{{ Pet::timeUntilNextEat()
time_t Pet::timeUntilNextEat()
{
    time_t now = time(0);

    if ((now - last_ate) > consumption_rate)
        return 0; // can eat immediately

    return (last_ate + consumption_rate) - now;
}
// }}}

// vim:foldmethod=marker
