#include "Player.h"
#include <iostream>
#include "Sprite.h"
#include "BoxCollider.h"
#include "InputKeys.h"
#include <math.h>
#include "SceneManager.h"
#include "Time.h"
#include "PixelCollider.h"
#include "Text.h"
#include "Physics.h"



//namespace preydator{
	Player::Player()
	{
	

	}
	
	Player::~Player()
	{
		
		
	}

	void Player::init() {
		
		mySprite = getComponent<Sprite>();
		speed = 10;
		jumpForce = -12;
		isFacingRight = true;
		myCollider = getComponent <BoxCollider>();
		myText = getComponent <Text>();
		phys = getComponent<Physics>();
		startPosition = position;
		editText = false;

	}

	void Player::update() {
		

		double x = input.getAxis("Horizontal");
		//double y = input.getAxis("Vertical");
		position += Vector2(x, 0).normalized() * speed;
		
		flip(x);

		//phys->addForce(Vector2(x, y));
		
		if (input.getKeyDown(InputKeys::JUMP)) {
			phys->addForce(Vector2(0, jumpForce));
			
		}
		
				
	}

	void Player::flip(float dir) {
		

		if (dir < 0 && isFacingRight || dir > 0 && !isFacingRight) {
			isFacingRight = !isFacingRight;
			mySprite->flip();
		}
		
		
		

	}

	void Player::printName() {
		std::cout << getName() << std::endl;
	}

	void Player::onCollision(Collider * other) {
		if (other->getParent()->getName() == "Enemy") {
				
			position = startPosition;
			
		}
		
	}
	

	



