#include "StarBoy.h"
#include "BoxCollider.h"
#include "AnimatedSprite.h"
#include "Physics.h"
#include "SceneManager.h"
#include <iostream>
#include "Time.h"
#include "Text.h"



StarBoy::StarBoy()
{
}


StarBoy::~StarBoy()
{
}

void StarBoy::init() {
	starBoySprite = getComponent<AnimatedSprite>();
	collider = getComponent<BoxCollider>();
	physics = getComponent <Physics>();

}

void StarBoy::update() {

	if (startCountDown) {
		countDown += time.deltaTime;
		if (countDown >= countDownTime) {
			sceneManager.loadScene(3);
			destroy(this);
		}
	}

}

void StarBoy::onCollision(Collider * other) {
	if (other->getParent()->getName() == "Home") {
		
		startCountDown = true;
		
		
	}

}
