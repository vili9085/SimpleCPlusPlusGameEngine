#ifndef INPUTKEYS_H
#define INPUTKEYS_H


#include <SDL.h>

namespace preydator{

	enum class InputKeys : unsigned int {
		DOWN = SDLK_DOWN,
		UP = SDLK_UP,
		LEFT = SDLK_LEFT,
		RIGHT = SDLK_RIGHT,
		JUMP = SDLK_SPACE,
		MOUSE_LEFT = SDL_BUTTON_LEFT,
		MOUSE_RIGHT = SDL_BUTTON_RIGHT,
		W = SDLK_w,
		A = SDLK_a,
		S = SDLK_s,
		D = SDLK_d,
		BACKSPACE = SDLK_KP_BACKSPACE,
		ENTER = SDLK_RETURN
	};
}

#endif // !INPUTKEYS_H
