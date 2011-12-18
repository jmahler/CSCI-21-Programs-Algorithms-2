
#include "UI.h"

// {{{ UI(), ~UI()
UI::UI()
{
    ps1 = "> ";  // first level command prompt
    ps2 = ">> "; // second level command prompt

    cinr = new CinReader();

    pets.push_back(new Pet("Paul"));
    pets.push_back(new Pet("Stuart"));
    pets.push_back(new Pet("Mavis"));  // somebody kick my dog mavis
}

UI::~UI() {
    delete cinr;

    vector<Pet*>::iterator i;
    for (i = pets.begin(); i != pets.end(); i++) {
        delete (*i);
    }
}
// }}}

// {{{ UI::go()
void UI::go()
{
    cout << "\n"
         << "Don't let your pets die of starvation!\n"
         << "\n"
         << "Enter 'h' for the help menu.\n"
         << "Press return to refresh the pets status.\n";

    while (1) {
        string line;
        string cmd;
        string arg;

        refreshPets();

        displayAlivePets();

        cout << ps1;

        line = cinr->readString();
        CommandParser cp(line);

        cmd = cp.getCommand();
        arg = cp.getArgument();

        if (cmd == "f") {
            // feed a pet
            
            if (arg.empty()) {
                cout << "Which child do you want to feed?.\n";
            }  else {
                unsigned int cid;
                stringstream ss(arg);
                ss >> cid;

                if (cid > 0 && cid <= pets.size()) {
                    (pets[cid - 1])->feed();
                } else {
                    cout << "Invalid pet id.\n";
                }
            }
        } else if (cmd == "q") {
            // quit
            break;
        } else if (cmd == "h") {
            // help menu
            cout << "Help Menu:\n"
                 << "\n"
                 << " h          help menu\n"
                 << " f <id>     feed a pet\n"
                 << " <RET>      display status of pets\n"
                 << " q          quit\n";
        }
    }
}
// }}}

// {{{ UI::refreshPets()
void UI::refreshPets()
{
    vector<Pet*>::iterator i;
    time_t now = time(0);

    for (i = pets.begin(); i != pets.end(); i++) {
        Pet *pet = *i;

        if (pet->isAlive()) {
            pet->refresh(now);

            if (pet->isDead()) {
                delete pet;

                cout << "Enter a name for for your new replacement pet\n";
                cout << ps2 ;

                string new_name = cinr->readString();

                (*i) = new Pet(new_name);
            }
        }
    }
    cout << "\n";
}
// }}}

// {{{ UI::displayAlivePets()
void UI::displayAlivePets()
{

    vector<Pet*>::iterator i;
    int n = 1;

    cout << "id: name, last ate (sec)\n";

    for (i = pets.begin(); i != pets.end(); i++) {

        if ((*i)->isAlive()) {
            time_t now = time(0);
            time_t last_ate = (*i)->getTimeLastAte();
            int d = now - last_ate;

            cout << "[" << n << "] " << (*i)->getName() << " ; energy = " << (*i)->getEnergy() << ", last ate (sec) = " << d << "\n";

            n++;
        }
    }
    cout << "\n";

}
// }}}


// vim:foldmethod=marker
