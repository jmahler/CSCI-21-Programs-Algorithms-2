
#include "BirthRecord.h"

#include <string>
#include <list>

using namespace std;

/**
 *
 * The Records class is used to keep track of births and deaths.
 * And then statistics can be generated summarizing them.
 *
 */
class BirthRecords {
    list<BirthRecord*> records;

public:
    BirthRecords() {};
    ~BirthRecords();

    void addBirth(int pid, string name);

    BirthRecord* getBirthRecord(const int pid);
    BirthRecord* getBirthRecord(string name);

    list<BirthRecord*> getAllLiving();
    list<BirthRecord*> getAllDeceased();

    void displaySummary();
};

