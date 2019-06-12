#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <vector>
#include "GameState.h"
#include "GameObject.h"
#include "PreyDator.h"



namespace preydator{
	class Input;
	class GameSession
	{
	public:
		//GameSession();
		GameSession(const int fps = 60);
		~GameSession();
		const int fps;
		void setUpInput();
		void runLoop();
		void addGameObject(GameObject * object);

	private:
		
		GameState gameState;
		std::vector <GameObject *> objectsToUpdate;
		//std::vector <Component *> allComponents;
		//std::vector <BoxCollider *> collisionComponents; // innan Collider
		std::vector <Collider *> collisionComponents;
		std::vector <Text *> textComponents;
		std::vector <Physics *> physicsComponents;
		std::vector <Sprite *> spriteComponents;
		void sortComponents();
		int tickInterval;
		void sessionUpdate();
		void sessionCollision();
		void updatePhysics();
		void sessionTick();
		void sessionDelete();
		void deleteTypedComponents(GameObject * parent);
		
		
	};
}
#endif // ! GAMESESSION_H

