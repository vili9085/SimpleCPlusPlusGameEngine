#include "Collider.h"
#include "GameObject.h"
#include <iostream>
#include <algorithm>


namespace preydator{
	Collider::Collider(GameObject * parent, std::string name, int width, int height, bool isStatic) : Component(parent, "Collider"), isStatic(isStatic)
	{
		collider.x = parent->getPosition().x;
		collider.y = parent->getPosition().y;
		collider.w = width;
		collider.h = height;
		
	}


	Collider::~Collider()
	{
		
	}

	int Collider::getWidth() const {
		return collider.w;
	}

	int Collider::getHeight() const {
		return collider.h;
	}

	void Collider::setWidth(const int width) {
		collider.w = width;
		
	}
	void Collider::setHeight(const int height) {
		collider.h = height;
	}
	void Collider::setColliderDimensions(const int width, const int height) {
		collider.w = width;
		collider.h = height;
	}
	SDL_Rect Collider::getIntersectionRect(Collider * a, Collider * b) const {

		SDL_Rect intersection;

		int x1 = std::max(a->getColliderBounds().x, b->getColliderBounds().x);
		int x2 = std::min(a->getColliderBounds().x + a->getColliderBounds().w, b->getColliderBounds().x + b->getColliderBounds().w);
		int y1 = std::max(a->getColliderBounds().y, b->getColliderBounds().y);
		int y2 = std::min(a->getColliderBounds().y + a->getColliderBounds().h, b->getColliderBounds().y + b->getColliderBounds().h);

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

	SDL_Rect Collider::getColliderBounds() {

		SDL_Rect bounds;
		bounds.x = getParent()->position.x - collider.w/2;
		bounds.y = getParent()->position.y - collider.h/2;
		bounds.w = collider.w;
		bounds.h = collider.h;

		return bounds;
	}
	 const SDL_Rect & Collider::getCollider() const {
		return collider;
	}

	 void Collider::setCollisionRectVisible(const bool b) {
		 isRectVisible = b;
	 }
}
