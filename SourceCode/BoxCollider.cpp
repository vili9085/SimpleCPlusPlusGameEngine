#include "BoxCollider.h"
#include <iostream>
#include <algorithm>
#include "Physics.h"


namespace preydator{
	
	BoxCollider::BoxCollider(GameObject * parent, int width, int height, bool isStatic) : Collider(parent, "BoxCollider", width, height, isStatic) 
	{
		
	}


	BoxCollider::~BoxCollider()
	{
		
	}

	bool BoxCollider::hasCollided(Collider * other) {

		intersectionRect = getIntersectionRect(this, other);
		if (intersectionRect.w == 0 && intersectionRect.h == 0) {
			return false;
		}
		return true;
	}

	void BoxCollider::performCollision(Collider * other) {
		if (other == this || isStatic) {
			return;
		}

		collisionFlag = true;
		getParent()->setCollisionFlag(true);
		int distanceX = std::min(collider.x + collider.w, other->getCollider().x + other->getCollider().w) - std::max(collider.x, other->getCollider().x);
		int distanceY = std::min(collider.y + collider.h, other->getCollider().y + other->getCollider().h) - std::max(collider.y, other->getCollider().y);
		
		if (distanceX < distanceY) {
			if (getColliderBounds().x > other->getColliderBounds().x) {
				getParent()->position.x += distanceX;
			}
			else {
				getParent()->position.x -= distanceX;
			}
		}
		else {
			if (getColliderBounds().y > other->getColliderBounds().y) {
				getParent()->position.y += distanceY;
			}
			else {
				getParent()->position.y -= distanceY;
			}
		}

	}

	void BoxCollider::tick() {

		if (collisionFlag) {

			boxColor = { 255, 105, 180, 255 };
			
		}
		else {
			boxColor= { 153, 255, 0, 255 };
		}
		
		if(isRectVisible){
		SDL_SetRenderDrawColor(preyDator.getRenderer(), boxColor.r, boxColor.g, boxColor.b, boxColor.a);
		}
		else {
			SDL_SetRenderDrawColor(preyDator.getRenderer(), 0, 0, 0, 0);
		}
		
		collider = getColliderBounds();
		SDL_RenderDrawRect(preyDator.getRenderer(), &collider);
		collisionFlag = false;
		getParent()->setCollisionFlag(collisionFlag);
		

	}

	BoxCollider * BoxCollider::create(GameObject * parent, int width, int height, bool isStatic) {
		return new BoxCollider(parent, width, height, isStatic);
	}

		
}


