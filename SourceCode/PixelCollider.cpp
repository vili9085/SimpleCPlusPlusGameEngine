#include "PixelCollider.h"
#include <iostream>
#include <algorithm>
#include "GameObject.h"
#include "Sprite.h"


namespace preydator{
	PixelCollider::PixelCollider(GameObject * parent, int width, int height, bool isStatic) : Collider(parent, "PixelCollider", width, height, isStatic)
	{
	
	}

	
	PixelCollider::~PixelCollider()
	{
		
	}
	
	bool PixelCollider::hasCollided(Collider * other) {
		/*Vi lyckades inte lösa förskjutningen så pixelcollision är enbart fungerande om en pixelcollider 
		kolliderar med en annan collider underifrån eller ifrån Höger*/

		SDL_Rect collisionRect = getIntersectionRect(this, other);
		intersectionRect = collisionRect;
		

		if (collisionRect.w == 0 && collisionRect.h == 0) {
			return false;
		}
		int height = 0;
		
				
		for (int y = 0; y < collisionRect.h; y++) {
			for (int x = 0; x < collisionRect.w; x++) {
				if (getAlpha(this, x, y)) {
				
				
					return true;
				}
			}
		}
		return false;
	}

	void PixelCollider::performCollision(Collider * other) {

		getParent()->setCollisionFlag(true);
	}

	void PixelCollider::tick() {
		

		if (collisionFlag) {

			boxColor = { 255, 105, 180, 255 };

		}
		else {
			boxColor = { 153, 255, 0, 255 };
		}

		if (isRectVisible) {
			SDL_SetRenderDrawColor(preyDator.getRenderer(), boxColor.r, boxColor.g, boxColor.b, boxColor.a);
		}
		else {

			SDL_SetRenderDrawColor(preyDator.getRenderer(), 0, 0, 0, 0);
		}

		
		
		collider = getColliderBounds();
		SDL_RenderDrawRect(preyDator.getRenderer(), &collider);
		/*SDL_SetRenderDrawColor(preyDator.getRenderer(), 255, 0, 0, 255);
		SDL_RenderFillRect(preyDator.getRenderer(), &intersectionRect);*/
		collisionFlag = false;
		getParent()->setCollisionFlag(false);

	}
		
	bool PixelCollider::getAlpha(Collider * col, int x, int y) {
		Sprite * s = col->getParent()->getComponent<Sprite>();
		SDL_LockSurface(s->getSurface());
		int bpp = s->getSurface()->format->BytesPerPixel;
		char* p = (char*)s->getSurface()->pixels + y * s->getSurface()->pitch + x * bpp;
		Uint32 pixelColor;

		switch (bpp) {
		case 1:
			pixelColor = *p;
			break;

		case 2:
			pixelColor = *(Uint16*)p;
			break;

		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN){
				pixelColor = p[0] << 16 | p[1] << 8 | p[2];
			}
			else{
				pixelColor = p[0] | p[1] << 8 | p[2] << 16;
			}
			break;

		case 4:
			pixelColor = *(Uint32*)p;
			break;
		default:
			break;
		}
		

			Uint8 red, green, blue, alpha;
			SDL_GetRGBA(pixelColor, s->getSurface()->format, &red, &green, &blue, &alpha);
			SDL_UnlockSurface(s->getSurface());
			
			return alpha > 0;

	}

	PixelCollider * PixelCollider::create(GameObject * parent, int width, int height, bool isStatic) {
		return new PixelCollider(parent, width, height, isStatic);
	}

}
