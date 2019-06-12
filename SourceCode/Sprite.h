#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <string>


#include "ErrorLog.h"
#include "Component.h"
#include "GameObject.h"

namespace preydator{
	

	class Sprite : public Component
	{
		friend class PixelCollider;
	public:
		static Sprite * create(GameObject * parent, std::string path);
		void flip();
		
		virtual void loadSprite(std::string path);
		virtual int getWidth() const;
		virtual int getHeight() const;
		virtual ~Sprite();

	protected:
		Sprite(GameObject * parent, std::string path);
		bool isFlipped = false;
		int width;
		int height;
		void freeTexture();
		SDL_Surface * spriteSurface = nullptr;
		SDL_Texture * spriteTx = nullptr;
		SDL_Rect spriteRect;
		SDL_Surface * getSurface() const;
		SDL_Rect getSpriteBounds() const;
		void tick();

	private:
		
		
		
	};

}
#endif // !SPRITE_H

