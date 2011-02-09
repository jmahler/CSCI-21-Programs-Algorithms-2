
#include "Child.h"

Child::Child()
{
    name = "John Doe";
    energy = 5; 
    last_ate = time(0);
}

Child::Child(string _name)
{
    name = _name;
    energy = 5; 
    last_ate = time(0);
}

Child::Child(string _name, int _energy)
{
    name = _name;
    energy = _energy;
    last_ate = time(0);
}

Child::~Child()
{
    cerr << "Good bye cruel world :-(\n";
}

void Child::feed()
{
    if (energy >= max_energy) {
        cout << "Yuck, I'm not hungry!\n";
    } else {
        energy += 1;
        cout << "Thank You.\n";
    }
}

bool Child::updateEnergy()
{
    if (energy <= 0)
        return true; // is dead

    time_t now = time(0);
    time_t d = now - last_ate;
    int n = d / consumption_rate;

    cout << "energy: " << energy << "\n";

    if (n > 0) {
        energy -= n;

        if (n <= 0) {
            return true; // died
        } else {
            //cout << "munch, munch (" << energy << ") " << name << "\n";
            cout << "munch, munch, munch...\n";

            last_ate = now;  // reset
        }
    }

    return false;
}

time_t Child::timeUntilNextEat()
{
    time_t now = time(0);

    if ((now - last_ate) > consumption_rate)
        return 0; // can eat immediately

    return (last_ate + consumption_rate) - now;
}