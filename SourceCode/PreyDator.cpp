#include "PreyDator.h"
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>



namespace preydator{

	PreyDator::PreyDator()
	{
		
	}


	PreyDator::~PreyDator()
	{
		SDL_DestroyWindow(mainWindow);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}

	bool PreyDator::initialize(int w, int h){
		width = w;
		height = h;
		

		bool success = true;

		int flags = SDL_Init(SDL_INIT_EVERYTHING);
		if (flags != 0) {
			ErrorLog::printError(SDL_GetError());
			success = false;
			}
	
		else {
			
			mainWindow = SDL_CreateWindow("MainWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		
			if (mainWindow == nullptr) {
				ErrorLog::printError(SDL_GetError());
				success = false;
			}
			else {
				renderer = SDL_CreateRenderer(mainWindow, -1, 0);
				
				if (renderer == nullptr) {
					ErrorLog::printError(SDL_GetError());
					std::cout << "Could not create renderer in Init" << std::endl;
					success = false;
				}
				else {
					int blend = SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
					if (blend != 0) {
						ErrorLog::printError(SDL_GetError());
						success = false;
					}
					else {
						int initFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
						int inittedImgs = IMG_Init(initFlags);
						
						if ((initFlags & inittedImgs) != initFlags) {
							ErrorLog::printError(IMG_GetError());
							
						}
						else {
							int textInit = TTF_Init();
							if (textInit != 0) {
								ErrorLog::printError("Text was not initialized");
							}
						}
					}
				
				}
			}

		}
	
		return success;
	}

	

	SDL_Renderer * PreyDator::getRenderer() {
		return renderer;
	}

	int  PreyDator::getWindowWidth() {
		return width;
	}
	int PreyDator::getWindowHeight() {
		return height;
	}

	PreyDator preyDator;

}
