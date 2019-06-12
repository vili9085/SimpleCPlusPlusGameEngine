#ifndef COLLIDER_H
#define COLLIDER_H
#include "Component.h"


namespace preydator{
	class Collider : public Component
	{
		friend class GameSession;
		friend class Scene;
		friend class BoxCollider;
		friend class PixelCollider;
		friend class Physics;
	public:
		SDL_Rect getColliderBounds();
		void setColliderDimensions(const int w, const int h);
		void setWidth(const int w);
		void setHeight(const int h);
		int getWidth() const;
		int getHeight() const;
				
		virtual ~Collider();

	protected:
		
		const SDL_Rect & getCollider() const;
		virtual void performCollision(Collider * other) = 0;
		virtual bool hasCollided(Collider * other) = 0;
		Collider(GameObject * parent, std::string name, int width, int height, bool isStatic);
		void setCollisionRectVisible(const bool b);
		SDL_Rect getIntersectionRect(Collider * a, Collider * b) const;
		SDL_Rect collider;
		bool isStatic;
		bool horizontalCollisionFlag;
		bool verticalCollisionFlag;
		bool isRectVisible = false;
		SDL_Rect intersectionRect;
		SDL_Color boxColor = { 153, 255, 0, 255 };
		bool collisionFlag = false;

	private:
		
		

	
		
	};
}
#endif // !COLLIDER_H

