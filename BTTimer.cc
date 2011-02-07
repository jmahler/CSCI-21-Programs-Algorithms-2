#include "BTTimer.h"

BTTimer::BTTimer ()
{
	start = time(0);
}

int BTTimer::getMinutesElapsed () const
{
	time_t now = time(0);
	return ((now - start) / 60);
}

int BTTimer::getSecondsElapsed () const
{
	time_t now = time(0);
	return (now - start);
}

void BTTimer::doPause (int seconds)
{
	clock_t endwait = clock() + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
}
