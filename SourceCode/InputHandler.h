#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H


#include <unordered_map>
#include "InputKeys.h"
#include <string>
#include "Vector2.h"

namespace preydator{
	class InputHandler
	{
	public:
		InputHandler();
		~InputHandler();

		void keyDown(const SDL_Event & e);
		void keyUp(const SDL_Event & e);
		void mouseDown(const SDL_Event & e);
		void mouseUp(const SDL_Event & e);
		void setMouseMotionPosition(int x, int y);
		Vector2 getMousePosition();
		bool isKeyPressed(InputKeys key);
		int getMouseX();
		int getMouseY();
		

	private:
		std::unordered_map <unsigned int, bool> keys;
		double mousePosX;
		double mousePosY;
		
	};
}
#endif // !INPUTHANDLER_H

