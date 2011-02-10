
#include "Parent.h"

#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <sys/wait.h>
#include <sys/types.h>

#include <iostream>
#include <string>

using namespace std;

Parent p;
/* yeah, yeah global variables are evil,
 * but how else can I make it accessable to the
 * interrupt routines?
 */

/**
 * Clear out zero or more dead child processes.
 * Called as a result of a SIGCHLD signal.
 *
 */
static void reaper(int sig, siginfo_t *siginfo, void *context)
{
    pid_t pid;
    BirthRecords *brs = p.getBirthRecords();
    
    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) {
        BirthRecord *br = brs->getBirthRecord(pid);
        if (0 == br) {
            cerr << "WARNING: no record found for pid: " << pid << "\n";
        } else {
            br->markDeceased();
        }
    }
}

int main() {

    struct sigaction sa_reaper;
    sa_reaper.sa_sigaction = &reaper;
    sigemptyset(&sa_reaper.sa_mask);
    sa_reaper.sa_flags = 0;

    sigaction(SIGCHLD, &sa_reaper, NULL);

    p.mainMenu();

    p.displayEndSummary();

    return 0;
}

