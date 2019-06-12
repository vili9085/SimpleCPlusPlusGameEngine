#ifndef PHYSICS_H
#define PHYSICS_H
#include "Component.h"
#include "Vector2.h"
#include "Collider.h"

namespace preydator{
	class Physics : public Component
	{
		friend class GameSession;
		friend class Scene;
	public:
		static Physics * create(GameObject * parent, float mass, Vector2 bounciness, Vector2 gravity);
		void addForce(Vector2 force);
		Vector2 getPhysForce() const;
		
		~Physics();

	protected:
		Physics(GameObject * parent, float mass, Vector2 bounciness, Vector2 gravity);


	private:
		bool getGrounded() const;
		void setGrounded(const bool b);
		float mass;
		SDL_Rect getIntersectionRect(SDL_Rect a, SDL_Rect b);
		int negate = -1;
		Vector2 physForce;
		Vector2 gravity;
		Vector2 bounciness;
		bool isGrounded = false;
		float maxGravity;
		bool rayCast(std::vector<Collider*> & col);
		void tick();
				
	};
}
#endif // !PHYSICS_H

