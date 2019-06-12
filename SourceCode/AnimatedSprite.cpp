#include "AnimatedSprite.h"
#include <iostream>
#include <SDL_image.h>


namespace preydator{
	AnimatedSprite::AnimatedSprite(GameObject * parent, std::string path, int horizontalPics, int verticalPics) : Sprite (parent, path), horizontalPics(horizontalPics), verticalPics(verticalPics)
	{
		if (horizontalPics == 0) {
			this->horizontalPics = 1;
		}
		if (verticalPics == 0) {
			this->verticalPics = 1;
		}
		noOfClips = this->horizontalPics * this->verticalPics;

		loadSprite(path);
		setRects();
	
	}

	AnimatedSprite::~AnimatedSprite()
	{
		
	}

	void AnimatedSprite::setRects() {

		for (int i = 0; i < verticalPics; i++) {

			for (int j = 0; j < horizontalPics; j++) {
				SDL_Rect rect{ (width / horizontalPics) * j, (height / verticalPics) * i , width / horizontalPics, height / verticalPics };
				animClips.push_back(rect);
			}
		}

	}

	void AnimatedSprite::tick() {

		spriteRect = getSpriteBounds();
		if (isFlipped) {
			SDL_RenderCopyEx(preyDator.getRenderer(), spriteTx, &animClips[frame / 6], &spriteRect, 0, nullptr, SDL_FLIP_HORIZONTAL);
		}else{
			SDL_RenderCopy(preyDator.getRenderer(), spriteTx, &animClips[frame/6], &spriteRect);
		}
		
		frame++;
		if (frame/6 >= noOfClips) {
			frame = 0;
		}

	}

	void AnimatedSprite::loadSprite(std::string path) {
		freeTexture();
		SDL_Surface * tempSurface = IMG_Load(path.c_str());

		if (tempSurface == nullptr) {
			ErrorLog::printError(SDL_GetError() + getName());
			return;
		}
		else {

			spriteTx = SDL_CreateTextureFromSurface(preyDator.getRenderer(), tempSurface);
			if (spriteTx == nullptr) {
				ErrorLog::printError(SDL_GetError());
				return;
			}
			else {
				width = tempSurface->w;
				height = tempSurface->h;

				spriteRect = { 0, 0, width/horizontalPics, height/verticalPics };
				
			}

		}
	}

	
	int AnimatedSprite::getWidth() const {
		return width / horizontalPics;
	}

	int AnimatedSprite::getHeight() const {
		return height / verticalPics;
	}

	AnimatedSprite * AnimatedSprite::create(GameObject * parent, std::string path, int horizontalPics, int verticalPics) {
		return new AnimatedSprite(parent, path, horizontalPics, verticalPics);
	}

}
