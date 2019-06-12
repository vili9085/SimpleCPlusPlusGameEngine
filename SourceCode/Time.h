#ifndef TIME_H
#define TIME_H

namespace preydator{
	class Time
	{
	public:
		Time();
		~Time();
		float deltaTime = 0;
		float previousTime = 0;
		float newTime = 0;
		void updateDeltaTime(float currentTime);
		float time = 0;
		void updateTime(float currentTime);
	};

	extern Time time;
	
}

#endif // !TIME_H

