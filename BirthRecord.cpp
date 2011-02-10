
#include "BirthRecord.h"

BirthRecord::BirthRecord(int _pid, string _name)
{
    pid        = _pid;
    name       = _name;
    time_birth = time(0);
    time_death = 0;        // not dead yet
    time_last_ate = time_birth;
}

