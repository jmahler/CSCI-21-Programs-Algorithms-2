#pragma once

#include <ctime>

class BTTimer
{
	public:
	
		BTTimer ();
		
		int getMinutesElapsed () const;
		int getSecondsElapsed () const;
		
		void doPause (int seconds);
		
	private:
	
		time_t start;
};
