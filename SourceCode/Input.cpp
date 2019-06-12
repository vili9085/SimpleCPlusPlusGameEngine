#include "Input.h"
#include <iostream>



namespace preydator{
	Input::Input()
	{
		canPressPublic = true;
		canPressSdl = true;
	}


	Input::~Input()
	{
	}

	void Input::keyDown(const SDL_Event & e){
		//std::cout << e.key.keysym.sym << std::endl;
		unsigned int key = e.key.keysym.sym;
		keys[key] = true;
		
	}

	void Input::keyUp(const SDL_Event & e) {
		canPressPublic = true;
		canPressSdl = true;
		unsigned int key = e.key.keysym.sym;
		keys[key] = false;
	}
	void Input::mouseDown(const SDL_Event & e) {
		unsigned int key = e.button.button;
		keys[key] = true;
	}
	void Input::mouseUp(const SDL_Event & e) {
		canPressPublic = true;
		unsigned int key = e.button.button;
		keys[key] = false;
	}

	int Input::getAxis(std::string axis) {
		//Hur skall denna göras?
		double retval = 0.0;

			
		if (axis == "Horizontal") {
			if (getKey(InputKeys::LEFT)) {
				retval += -1.0;
			}
			if (getKey(InputKeys::RIGHT)) {
				retval += 1.0;
			}

		}
		if (axis == "Vertical") {
			if (getKey(InputKeys::UP)) {
				retval += -1.0;
			}
			if (getKey(InputKeys::DOWN)) {
				retval += 1.0;
			}

		}

		if (axis == "Horizontal_2") {
			if (getKey(InputKeys::A)) {
				retval += -1.0;
			}
			if (getKey(InputKeys::D)) {
				retval += 1.0;
			}

		}
		if (axis == "Vertical_2") {
			if (getKey(InputKeys::W)) {
				retval += -1.0;
			}
			if (getKey(InputKeys::S)) {
				retval += 1.0;
			}

		}
		return retval;
	}

	bool Input::getKey(InputKeys key) {
		
		unsigned int SDLkey = static_cast<unsigned int>(key);
		std::unordered_map <unsigned int, bool>::iterator  it = keys.find(SDLkey);
		if (it != keys.end()) {
			
			return it->second;
			
		}
		return false;
		

	}
	bool Input::getKeyDown(InputKeys key) {

		unsigned int SDLkey = static_cast<unsigned int>(key);
		std::unordered_map <unsigned int, bool>::iterator  it = keys.find(SDLkey);
		if (it != keys.end()) {
			//std::cout << std::boolalpha << it->second << " " << canPress << std::endl;
			if (canPressPublic && it->second) {
				canPressPublic = false;
				return it->second;
			}
			
			
		}
		return false;


	}

	bool Input::getSdlKeyDown(unsigned int key ) {
		

		std::unordered_map <unsigned int, bool>::iterator  it = keys.find(key);
		if (it != keys.end()) {
		
			if (canPressSdl && it->second){
				canPressSdl = false;
			//std::cout << it->second << std::endl;
			return it->second;
			}
			
			
		}
		//std::cout << "could not return second" << std::endl;
		return false;
		

	}
	
	Vector2 Input::getMousePosition() {
		
		return Vector2(mousePosX, mousePosY);

		
		
	}

	void Input::setMouseMotionPosition(int x, int y) {
		
		mousePosX = static_cast<double>(x);
		mousePosY = static_cast<double>(y);
		
	}
	
	Input input;
}




