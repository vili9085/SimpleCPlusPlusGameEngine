#include "SceneManager.h"

namespace preydator {

	SceneManager::SceneManager()
	{
	}


	SceneManager::~SceneManager()
	{
	}

	void SceneManager::loadScene(int id) {
		sceneToLoad = id;
		std::unordered_map <int, Scene*>::iterator  it = scenes.find(sceneToLoad);
		if (it != scenes.end()) {
			
			currentScene = it->second;
			currentScene->resetScene();
			//currentScene->sortComponents(); // skall detta verkligen vara här?!
			//shouldLoad = false;
		}
		//Throw exception here?
	}

	void SceneManager::engineLoadScene() {
		

	}
	void SceneManager::addScene(Scene * s) {
		scenes[s->getId()] = s;
		s->sortComponents();
		//s->resetScene();
	} 

	Scene * SceneManager::getCurrentScene() const{
		return currentScene;
	}

	SceneManager sceneManager;

}