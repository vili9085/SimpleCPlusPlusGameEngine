#include "Time.h"
#include <SDL.h>


namespace preydator{
	Time::Time()
	{
	}


	Time::~Time()
	{
	}

	void Time::updateDeltaTime(float currentTime) {
		previousTime = newTime;
		newTime = currentTime;
		deltaTime = newTime - previousTime;
		
	}

	void Time::updateTime(float currentTime) {
		time = currentTime;
	}

	 
	Time time;
}



