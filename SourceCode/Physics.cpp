#include "Physics.h"
#include "GameObject.h"
#include "Time.h"
#include <iostream>
#include <algorithm>



namespace preydator{
	Physics::Physics(GameObject * parent, float mass, Vector2 bounciness, Vector2 gravity) : Component(parent, "Physics"), mass(mass), bounciness(bounciness), gravity(gravity)
	{
		
		maxGravity = mass * gravity.y * 1000 ;
	}


	Physics::~Physics()
	{
		
	}

	void Physics::tick() {

		if(!isGrounded){
		addForce(gravity);

			if (physForce.y >= maxGravity) {
				physForce.y = maxGravity;
			}
			if (getParent()->getCollisionFlag()) {
				addForce(physForce *= (bounciness * negate));
			}
					
		}

		getParent()->position += physForce;
		
	}

	bool Physics::rayCast(std::vector<Collider *> & col) {
		
		Collider * tmp = getParent()->getComponent<Collider>();
		SDL_Rect ray = tmp->getColliderBounds();
		ray.h += 10;
		
		for (Collider * c : col) {
			if(c != tmp){
				SDL_Rect intersection = getIntersectionRect(ray, c->getColliderBounds());
				if (intersection.h > 0 && std::abs(physForce.y) < 1) {
					return true;
				}
			}
		}
		return false;

	}

	SDL_Rect Physics::getIntersectionRect(SDL_Rect a, SDL_Rect  b) {

		SDL_Rect intersection;

		int x1 = std::max(a.x, b.x);
		int x2 = std::min(a.x + a.w, b.x + b.w);
		int y1 = std::max(a.y, b.y);
		int y2 = std::min(a.y + a.h, b.y + b.h);

		int width = x2 - x1;
		int height = y2 - y1;

		if (width > 0 && height > 0) {
			intersection = { x1, y1, width, height };
			return intersection;
		}
		else {
			intersection = { 0,0,0,0 };
			return intersection;
		}
	}

	void Physics::addForce(Vector2 force) {
		
		physForce += force;
		
	}
		
	Vector2 Physics::getPhysForce() const {
		return physForce;
	}
		
	bool Physics::getGrounded() const {
		return isGrounded;
	}

	void Physics::setGrounded(const bool b) {
		isGrounded = b;
	}

	Physics * Physics::create(GameObject * parent, float mass, Vector2 bounciness, Vector2 gravity) {
		return new Physics(parent, mass, bounciness, gravity);
	}
}
