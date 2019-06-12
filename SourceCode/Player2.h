#ifndef PLAYER2_H
#define PLAYER2_H
#include "GameObject.h"



	using namespace preydator;
	class Player2 : public GameObject
	{
	public:
		using GameObject::GameObject;
		Player2();

		void init();
		void update();
		void onCollision(Collider * other);

		~Player2();

	private:
		Sprite * mySprite;
		PixelCollider * myCollider;
		int speed;
		int startvalue;
		bool turn = false;
	};


#endif // !PLAYER_H
