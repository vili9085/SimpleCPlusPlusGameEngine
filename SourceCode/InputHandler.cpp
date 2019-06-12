#include "InputHandler.h"

namespace preydator{

InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

	void InputHandler::keyDown(const SDL_Event & e) {
		unsigned int key = e.key.keysym.sym;
		keys[key] = true;
	}

	void InputHandler::keyUp(const SDL_Event & e) {
		unsigned int key = e.key.keysym.sym;
		keys[key] = false;
	}
	void InputHandler::mouseDown(const SDL_Event & e) {
		unsigned int key = e.button.button;
		keys[key] = true;
	}
	void InputHandler::mouseUp(const SDL_Event & e) {
		unsigned int key = e.button.button;
		keys[key] = false;
	}


	bool InputHandler::isKeyPressed(InputKeys key) {

		unsigned int SDLkey = static_cast<unsigned int>(key);
		std::unordered_map <unsigned int, bool>::iterator  it = keys.find(SDLkey);
		if (it != keys.end()) {
			return it->second;
		}
		return false;

	}
	Vector2 InputHandler::getMousePosition() {

		return Vector2(mousePosX, mousePosY);


	}
	int InputHandler::getMouseX() {
		return mousePosX;
	}
	int InputHandler::getMouseY() {
		return mousePosY;
	}

	void InputHandler::setMouseMotionPosition(int x, int y) {

		mousePosX = static_cast<double>(x);
		mousePosY = static_cast<double>(y);

	}

}
