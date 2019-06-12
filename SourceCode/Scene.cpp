#include "Scene.h"
#include "BoxCollider.h"
#include "PixelCollider.h"
#include "Text.h"
#include "Physics.h"
#include "Sprite.h"
#include <iostream>

namespace preydator{


	Scene::Scene(int id) : id(id)
	{
	}


	Scene::~Scene()
	{
	}

	Scene * Scene::createScene(int id) {
		return new Scene(id);
	}

	int Scene::getId() {
		return id;
	}
	void Scene::resetScene() {
		for (std::pair<GameObject *, Vector2> p : scenePositioning) {
			p.first->position = p.second;
			
		}

	}

	void Scene::addGameObject(GameObject * object, Vector2 pos) {

		objectsToUpdate.push_back(object);
		scenePositioning.push_back(std::make_pair(object, pos));
		
		
	}


	void Scene::sortComponents() {
		for (GameObject * g : objectsToUpdate) {
			std::vector<Component *> tmp = g->getVectorOfComponents();
			for (Component *c : tmp) {
				
				if (Collider * col = dynamic_cast<Collider *> (c)) {
					collisionComponents.push_back(col);
				}
				else if (Physics * p = dynamic_cast<Physics *>(c)) {
					physicsComponents.push_back(p);
				}
				else if (Text * t = dynamic_cast<Text *> (c)) {
					textComponents.push_back(t);
				}

				else if (Sprite * s = dynamic_cast<Sprite *>(c)) {
					spriteComponents.push_back(s);
				}

			}
		}
	}

	void Scene::sceneUpdate() {
		for (GameObject * g : objectsToUpdate) {
			g->update();
		}
	}

	void Scene::sceneCollision() {
		std::vector < std::pair<Collider *, Collider *>> tmp;
		for (int i = 0; i < collisionComponents.size(); i++) {
			Collider * a = collisionComponents[i];
			for (int j = i + 1; j < collisionComponents.size(); j++) {
				Collider * b = collisionComponents[j];
				//bool collision = a->hasCollided(b);
				if (a->hasCollided(b) && b->hasCollided(a)) {
					tmp.push_back(std::make_pair(a, b));
				}
			}
		

		}

		for (std::pair<Collider*, Collider *> p : tmp) {

			p.first->performCollision(p.second);
			p.second->performCollision(p.first);
			p.first->getParent()->onCollision(p.second);
			p.second->getParent()->onCollision(p.first);
		}

	}

	void Scene::updatePhysics() {


		for (Physics * p : physicsComponents) {
			bool b = p->rayCast(collisionComponents);
			p->setGrounded(b);
		}
	}



	void Scene::sceneTick() {
		for (Component * c : spriteComponents) {

			c->tick();

		}
		for (Component * c : physicsComponents) {
			c->tick();
		}

		for (Component * c : collisionComponents) {
			c->tick();
		}

		for (Component * c : textComponents) {
			c->tick();
		}


	}

	void Scene::deleteTypedComponents(GameObject * parent) {

		for (auto sit = spriteComponents.begin(); sit != spriteComponents.end(); ) {
			if (parent == (*sit)->getParent()) {
				sit = spriteComponents.erase(sit);

			}
			else {
				sit++;
			}
		}


		for (auto pit = physicsComponents.begin(); pit != physicsComponents.end(); ) {
			if (parent == (*pit)->getParent()) {
				pit = physicsComponents.erase(pit);

			}
			else {
				pit++;
			}
		}

		for (auto tit = textComponents.begin(); tit != textComponents.end(); ) {
			if (parent == (*tit)->getParent()) {
				tit = textComponents.erase(tit);

			}
			else {
				tit++;
			}
		}

		for (auto cit = collisionComponents.begin(); cit != collisionComponents.end(); ) {
			if (parent == (*cit)->getParent()) {
				cit = collisionComponents.erase(cit);

			}
			else {
				cit++;
			}
		}



	}

	void Scene::sceneDelete() {
		for (std::vector<GameObject*>::iterator iter = objectsToUpdate.begin(); iter != objectsToUpdate.end(); ) {
			if ((*iter)->getDestructionFlag()) {

				deleteTypedComponents(*iter);
				delete *iter;
				iter = objectsToUpdate.erase(iter);
			}
			else {
				iter++;
			}
		}
	}

	void Scene::recieveTextInput(SDL_Event & evnt) {
		
		for (Text * t : textComponents) {
			if (t->getEditable()) {
				t->recieveInput(evnt);
			}
		}
	}

	void Scene::update() {
		SDL_SetRenderDrawColor(preyDator.getRenderer(), 140, 0, 0, 255);

		SDL_RenderClear(preyDator.getRenderer());
		sceneUpdate();
		sceneCollision();
		sceneTick();
		sceneDelete();

	}

}
