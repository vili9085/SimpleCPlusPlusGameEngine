#include "Player2.h"
#include <iostream>
#include "Sprite.h"
#include "BoxCollider.h"
#include "PixelCollider.h"
#include "InputKeys.h"
#include <math.h>
#include "SceneManager.h"



	Player2::Player2()
	{


	}


	Player2::~Player2()
	{
		
	}

	void Player2::init() {
		mySprite = getComponent<Sprite>();
		speed = 10;
		myCollider = getComponent <PixelCollider>();
		startvalue = position.x;
	}

	void Player2::update() {

		if (position.x < startvalue) {
			turn = false;
			mySprite->flip();
			
		}
		else if (position.x >= startvalue + 150) {
			turn = true;
			mySprite->flip();
		}

		if (!turn) {
			position.x++;
		}
		else if (turn) {
			position.x--;
		}
		
		
		

	}

	void Player2::onCollision(Collider * other) {
		

	}




