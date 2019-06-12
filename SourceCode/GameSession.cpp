#include "GameSession.h"
#include <SDL.h>
#include <iostream>
#include "Input.h"
#include "BoxCollider.h"
#include "Sprite.h"
#include "SceneManager.h"
#include "KeyBindManager.h"
#include "Time.h"
#include "Text.h"
#include "Physics.h"

#define MS_PER_SECOND 1000



namespace preydator{
	/*GameSession::GameSession() : gameState( GameState::RUN )
	{
	}
	*/
	GameSession::GameSession(const int fps) : gameState(GameState::RUN), fps(fps)
	{
		tickInterval = MS_PER_SECOND / fps;
		
		
	}


	GameSession::~GameSession()
	{
	}

	void GameSession::runLoop() {

		sortComponents();
		
		Uint32 nextTick;
		int delay;
		SDL_Event evnt;
		SDL_Keycode currentPress = 0;
		
		while (gameState != GameState::EXIT) {
			nextTick = SDL_GetTicks() + tickInterval;
			time.updateDeltaTime((float)SDL_GetTicks() / 1000);
			time.updateTime((float)SDL_GetTicks() / 1000);
			
			while (SDL_PollEvent(&evnt)) {

				switch (evnt.type) {
				case SDL_KEYDOWN:
					
					input.keyDown(evnt);
					currentPress = evnt.key.keysym.sym;
					
					break;

				case SDL_KEYUP:

					input.keyUp(evnt);
										
					break;

				case SDL_MOUSEBUTTONDOWN:
					
					input.mouseDown(evnt);
										
					break;
				
				case SDL_MOUSEBUTTONUP:
					
					input.mouseUp(evnt);
					
					break;

				case SDL_MOUSEMOTION:
					
					input.setMouseMotionPosition(evnt.motion.x, evnt.motion.y);
					
					
					break;
				case SDL_QUIT:
					gameState = GameState::EXIT;
					break;
				case SDL_TEXTINPUT:

					if (sceneManager.getCurrentScene()) {
						sceneManager.getCurrentScene()->recieveTextInput(evnt);
					}
					else {

						for (Text * t : textComponents) {
							if (t->getEditable()) {
								t->recieveInput(evnt);
							}
						}
					}
					
					break;
				} // switch
				
				

			} // Inner while

			
			
		
			if (input.getSdlKeyDown(currentPress) && keyBindManager.getKeyBind(currentPress)) {
				
				keyBindManager.getKeyBind(currentPress)->perform();
			}

			

			if (sceneManager.getCurrentScene()){
				sceneManager.getCurrentScene()->update();
			}else{
				SDL_SetRenderDrawColor(preyDator.getRenderer(), 0, 0, 0, 255);

				SDL_RenderClear(preyDator.getRenderer());
				
				
				sessionUpdate();
				
				sessionCollision();
				sessionTick();
				
				updatePhysics();
				sessionDelete();
			}

			SDL_RenderPresent(preyDator.getRenderer());
			

			delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}

		} // outer While

		SDL_Quit();


	}

	void GameSession::addGameObject(GameObject * object) {
		objectsToUpdate.push_back(object);
	}

	
	void GameSession::sortComponents() {
		for (GameObject * g : objectsToUpdate) {
			std::vector<Component *> tmp = g->getVectorOfComponents();
			for (Component *c : tmp) {
				//allComponents.push_back(c);
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

	void GameSession::sessionUpdate() {
		for (GameObject * g : objectsToUpdate) {
			g->update();
		}
	}

	void GameSession::sessionCollision() {
		std::vector < std::pair<Collider *, Collider *>> tmp;
		for (int i = 0; i < collisionComponents.size(); i++) {
			Collider * a = collisionComponents[i];
			for (int j = i+1; j < collisionComponents.size(); j++) {

				Collider * b = collisionComponents[j];
				bool collision = a->hasCollided(b);
				if (collision) {
					
					tmp.push_back(std::make_pair (a,b));
				}
			}
		
		}

		for(std::pair<Collider*, Collider *> p : tmp){
		
			p.first->performCollision(p.second);
			p.second->performCollision(p.first);
			p.first->getParent()->onCollision(p.second);
			p.second->getParent()->onCollision(p.first);
		}

	}
	void GameSession::updatePhysics() {

		for (Physics * p : physicsComponents) {
			bool b = p->rayCast(collisionComponents);
			p->setGrounded(b);
		}
	
	}

	void GameSession::sessionTick() {

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

	void GameSession::deleteTypedComponents(GameObject * parent) {

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
				tit =textComponents.erase(tit);
				
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

	void GameSession::sessionDelete() {
		for (std::vector<GameObject*>::iterator iter = objectsToUpdate.begin(); iter != objectsToUpdate.end(); ) {
			if ((*iter)->getDestructionFlag()) {

				/*for (std::vector<Component*>::iterator citer = allComponents.begin(); citer != allComponents.end(); ) {
					if (*iter == (*citer)->getParent()) {
						
						citer = allComponents.erase(citer);

						}
					else {
						citer++;
					}
				}*/
				deleteTypedComponents(*iter);
				delete *iter;
				iter = objectsToUpdate.erase(iter);
			}
			else {
				iter++;
			}
		}
	}
}
