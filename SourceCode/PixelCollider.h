#ifndef PIXELCOLLIDER_H
#define PIXELCOLLIDER_H
#include "Collider.h"

namespace preydator{
	class PixelCollider : public Collider
	{
	public:
		static PixelCollider * create(GameObject * parent, int width, int height, bool isStatic);
		
		void tick();
		void performCollision(Collider * other);
		bool hasCollided(Collider * other) ;

		~PixelCollider();

	protected:
		PixelCollider(GameObject * parent, int width, int height, bool isStatic);

	private:
		bool getAlpha(Collider * col, int x, int y);

	};
}

#endif // !PIXELCOLLIDER_H

