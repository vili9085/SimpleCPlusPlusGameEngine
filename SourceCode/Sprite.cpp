#include "Sprite.h"
#include "Vector2.h"
#include <iostream>
#include <SDL_image.h>


namespace preydator{
	Sprite::Sprite(GameObject * g, std::string path) : Component(g, "Sprite")
	{
		loadSprite(path);
	}


	Sprite::~Sprite()
	{
		SDL_FreeSurface(spriteSurface);
		SDL_DestroyTexture(spriteTx);
		
	}

	void Sprite::loadSprite(std::string path) {
		freeTexture();
		spriteSurface = IMG_Load(path.c_str());
		if (spriteSurface == nullptr) {
			ErrorLog::printError(SDL_GetError() + getName());
			return;
		}
		else {
			
			spriteTx = SDL_CreateTextureFromSurface(preyDator.getRenderer(), spriteSurface);
			if (spriteTx == nullptr) {
				ErrorLog::printError(SDL_GetError());
				return;
			}
			else {
			
				width = spriteSurface->w;
				height = spriteSurface->h;

				spriteRect = { 0, 0, width, height };
 
			}

		}
	
	}

	void Sprite::freeTexture() {

		if (spriteTx != nullptr) {
			
			SDL_FreeSurface(spriteSurface);
			SDL_DestroyTexture(spriteTx);
			spriteTx = nullptr;
			spriteRect = { 0,0,0,0 };
			width = 0;
			height = 0;
		}
	}

	void Sprite::flip() {

		isFlipped = !isFlipped;
		
	}

	int Sprite::getWidth() const{
		return width;
	}

	int Sprite::getHeight() const {
		return height;
	}

	void Sprite::tick() {
		
		spriteRect = getSpriteBounds();
		SDL_RenderCopy(preyDator.getRenderer(), spriteTx, nullptr, &spriteRect);
		
	}

	SDL_Surface * Sprite::getSurface() const {

		return spriteSurface;
	}

	SDL_Rect Sprite::getSpriteBounds() const {
		SDL_Rect bounds;
		
		bounds.x = getParent()->position.x - spriteRect.w / 2;
		bounds.y = getParent()->position.y - spriteRect.h /2;
		bounds.w = spriteRect.w;
		bounds.h = spriteRect.h;

		return bounds;
	}

	Sprite * Sprite::create(GameObject * parent, std::string path) {
		return new Sprite(parent, path);
	}
	
}


