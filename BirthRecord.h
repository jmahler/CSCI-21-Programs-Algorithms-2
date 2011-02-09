
#include <string>
#include <time.h>

using namespace std;

/**
 *
 * A BirthRecord is a record of a childs birth.
 * A childs death can is also recorded.
 *
 */
class BirthRecord
{
    int pid;
    string name;
    time_t time_birth;
    time_t time_death;
    
public:
    BirthRecord(int pid, string name);

    int getPid() { return pid; };
    string getName() { return name; };
    time_t timeBirth() { return time_birth; };
    time_t timeDeath() { return time_death; };

    void setTimeDeath() { time_death = time(0); };
    void markDeceased() { time_death = time(0); };

    bool isAlive() { return (! this->isDeceased()); };
    bool isDeceased() { return (0 == time_death) ? false : true; };
};
