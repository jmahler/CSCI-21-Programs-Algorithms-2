
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
    /**
     * Create a new BirthRecords object.
     */
    BirthRecords() {};
    ~BirthRecords();

    /**
     * Record of a new birth.
     */
    void addBirth(int pid, string name);

    BirthRecord* getBirthRecord(const int pid);
    BirthRecord* getBirthRecord(string name);

    /**
     * Get ALL birth records.
     *
     */
    list<BirthRecord*> getAll() { return records; };

    /**
     * Get all birth records for LIVING children.
     *
     * @returns NULL pointer if record not found
     */
    list<BirthRecord*> getAllLiving();
    /**
     * Get all birth records of DECEASED children.
     *
     * @returns NULL pointer if record not found
     */
    list<BirthRecord*> getAllDeceased();
};

