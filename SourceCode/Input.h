#ifndef INPUT_H
#define INPUT_H
#include <unordered_map>
#include "InputKeys.h"
#include <string>
#include "Vector2.h"

//#include "GameSession.h"

namespace preydator{
	class Input
	{
		friend class GameSession;
	public:
		Input();
		~Input();
		
		
		Vector2 getMousePosition();
		bool getKey(InputKeys key);
		bool getKeyDown(InputKeys key);
		int getAxis(std::string axis);

	private:
		void keyDown(const SDL_Event & e);
		void keyUp(const SDL_Event & e);
		void mouseDown(const SDL_Event & e);
		void mouseUp(const SDL_Event & e);
		void setMouseMotionPosition(int x, int y);
		bool getSdlKeyDown(unsigned int key);
		std::unordered_map <unsigned int, bool> keys;
		double mousePosX;
		double mousePosY;
		bool canPressPublic;
		bool canPressSdl;
		

	};
	extern Input input;
}
#endif // !INPUT_H

