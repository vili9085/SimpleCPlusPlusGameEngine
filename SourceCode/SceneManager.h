#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include <unordered_map>


namespace preydator {
	class SceneManager
	{
		friend class GameSession;
	public:
		SceneManager();
		~SceneManager();

		void loadScene(int id);
		void addScene(Scene * s);

	private:
		Scene * currentScene;
		Scene * getCurrentScene() const;
		std::unordered_map <int, Scene*> scenes;
		int sceneToLoad;
		bool shouldLoad;
		void engineLoadScene();
	};
	extern SceneManager sceneManager;
}
#endif // !SCENEMANAGER_H
