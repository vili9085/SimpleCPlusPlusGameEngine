#ifndef SCENE_H
#define SCENE_H

#include "GameObject.h"
//#include "Component.h"
//#include <vector>

namespace preydator {
	
	class Scene
	{
		friend class GameSession;
		friend class SceneManager;
	public:
		static Scene * createScene(int id);
		~Scene();
		int getId();
		void addGameObject(GameObject * object, Vector2 pos);
		
		

	private:
		void resetScene();
		void sortComponents();
		void sceneUpdate();
		void update();
		Scene(int id);
		int id;
		std::vector <GameObject *> objectsToUpdate;
		std::vector <Component *> spriteComponents;
		std::vector <Collider *> collisionComponents;
		std::vector <Text *> textComponents;
		std::vector <Physics *> physicsComponents;
		std::vector < std::pair<GameObject *, Vector2>> scenePositioning;
		void recieveTextInput(SDL_Event & evnt);
		
		
		void sceneCollision();
		void updatePhysics();
		void sceneTick();
		void sceneDelete();
		void deleteTypedComponents(GameObject * parent);
	};

}

#endif