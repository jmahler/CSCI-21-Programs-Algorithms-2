
#include "BirthRecords.h"

BirthRecords::~BirthRecords()
{
    // delete all the alocated memory
    list<BirthRecord*>::iterator i = records.begin();
    for ( ; i != records.end(); i++) {
        delete *i;
    }
}

void BirthRecords::addBirth(int pid, string name)
{
    BirthRecord* br;

    br = new BirthRecord(pid, name);

    records.push_front(br);
}

BirthRecord* BirthRecords::getBirthRecord(const int pid)
{
    list<BirthRecord*>::iterator i = records.begin();
    for ( ; i != records.end(); i++) {
        if (pid == (*i)->getPid())
            return *i;
    }

    return 0; // record not found
}

BirthRecord* BirthRecords::getBirthRecord(string name)
{
    list<BirthRecord*>::iterator i = records.begin();
    for ( ; i != records.end(); i++) {
        if (name == (*i)->getName())
            return *i;
    }

    return 0; // record not found
}

list<BirthRecord*> BirthRecords::getAllLiving()
{
    list<BirthRecord*> res;

    list<BirthRecord*>::iterator i = records.begin();
    for ( ; i != records.end(); i++) {
        if ((*i)->isAlive()) {
            res.push_front(*i);
        }
    }

    return res;
}

list<BirthRecord*> BirthRecords::getAllDeceased()
{
    list<BirthRecord*> res;

    list<BirthRecord*>::iterator i = records.begin();
    for ( ; i != records.end(); i++) {
        if ((*i)->isDeceased()) {
            res.push_front(*i);
        }
    }

    return res;
}
