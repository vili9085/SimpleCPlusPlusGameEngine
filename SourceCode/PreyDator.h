#ifndef PREYDATOR_H
#define PREYDATOR_H
#include <SDL.h>
#include <vector>

#include "ErrorLog.h"




namespace preydator{
	class PreyDator
	{
	public:
		PreyDator();
		bool initialize(int width = 1024, int height = 768);
		int getWindowWidth();
		int getWindowHeight();
		SDL_Renderer * getRenderer();

		~PreyDator();

	private:
		SDL_Window * mainWindow;
		SDL_Renderer * renderer;
		int width;
		int height;
		
		
	};
	extern PreyDator preyDator;
}

#endif

