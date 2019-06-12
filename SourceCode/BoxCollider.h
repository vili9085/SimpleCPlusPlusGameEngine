#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include "Component.h"
#include "GameObject.h"
#include "Collider.h"
#include <SDL.h>

namespace preydator{
	class BoxCollider : public Collider
	{
		friend class GameSession;
		friend class Scene;
	public:
		static BoxCollider * create(GameObject * parent, int width, int height, bool isStatic);
		
		~BoxCollider();

	protected:
		BoxCollider(GameObject * parent, int width, int height, bool isStatic);
		void tick();
		void performCollision(Collider * other);
		bool hasCollided(Collider * other);
		

	private:
		
	
					
	};
}
#endif // !BOXCOLLIDER_H

