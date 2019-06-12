#include "PickUp.h"
#include "PixelCollider.h"
#include "Sprite.h"
#include "Physics.h"



PickUp::PickUp()
{
}


PickUp::~PickUp()
{
}

void PickUp::init() {
	myCollider = getComponent<PixelCollider>();
	mySprite = getComponent<Sprite>();
	phys = getComponent<Physics>();
}

void PickUp::update() {

}

void PickUp::onCollision(Collider * other) {
	if (other->getParent()->getName() == "Player1") {
		destroy(this);
	}
}
