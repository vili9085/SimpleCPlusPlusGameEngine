#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>

#include "Input.h"
#include "Component.h"
#include "Vector2.h"








namespace preydator{
	class Sprite;
	class AnimatedSprite;
	class Collider;
	class BoxCollider;
	class PixelCollider;
	class Text;
	class Physics;

	class GameObject
	{
		friend class BoxCollider;
		friend class PixelCollider;
		friend class GameSession;
		friend class Scene;
	public:
		
		GameObject();
		GameObject(Vector2 startPos);
		GameObject(std::string name);
		GameObject(std::string name, Vector2 startPos);
		virtual ~GameObject();
		void addComponent(Component * component);
		std::string getName();
		bool getCollisionFlag(); 
		bool verticalCollision;
		Vector2 & getPosition();
		Vector2 position = Vector2(0, 0);
		
		template <class T>
		T* getComponent() {
			for (Component * c : components) {
				if (T* t = dynamic_cast<T*> (c)) {
					return t;
				}
			}
				return nullptr;
		}

	protected:
		void destroy(GameObject * gameObject);
		virtual void update() = 0;
		virtual void init() = 0;
		virtual void onCollision(Collider * other);
		GameObject(const GameObject & other) = delete;
		const GameObject & operator=(const GameObject & other) = delete;
	
	private:
		void setCollisionFlag(bool b);
		std::vector <Component *> & getVectorOfComponents();
		bool getDestructionFlag();
		std::vector <Component *> components;
		void setDestructionFlag(bool b);
		bool destructionFlag = false;
		bool collisionFlag;
		std::string name = "No_Name";
	
		
	};

	
}
#endif // !GAMEOBJECT_H

