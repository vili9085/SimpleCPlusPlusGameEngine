#ifndef PICKUP_H
#define PICKUP_H
#include "GameObject.h"


using namespace preydator;
	class PickUp : public GameObject
	{
		using GameObject::GameObject;
	public:
		void init();
		void update();
		void onCollision(Collider * other);
		PickUp();
		~PickUp();

	private:
		Sprite * mySprite;
		PixelCollider * myCollider;
		Physics * phys;
	};
#endif // !PICKUP_H

