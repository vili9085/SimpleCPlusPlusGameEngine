#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"



	using namespace preydator;
	class Player : public GameObject
	{
	public:
		using GameObject::GameObject;
		Player();
		//Player(std::string name, Vector2 startPos);

		void init();
		void update();
		void onCollision(Collider * other);
		void printName();
		Vector2 startPosition;
	
		~Player();

	protected:
		


	private:
		Sprite * mySprite;
		BoxCollider * myCollider;
		Physics * phys;
		int speed;
		int jumpForce;
		bool isFacingRight;
		void flip(float dir);
		Text * myText;
		bool editText;

	};


#endif // !PLAYER_H

