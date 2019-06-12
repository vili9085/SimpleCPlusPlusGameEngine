#include <SDL.h>
#include <iostream>
#include "InputKeys.h"
#include "Input.h"
#include "GameObject.h"
#include "Component.h"
#include "PreyDator.h"
#include "Player.h"
#include "Player2.h"
#include "Sprite.h"
#include "GameSession.h"
#include "BoxCollider.h"
#include "AnimatedSprite.h"
#include "Scene.h"
#include "SceneManager.h"
#include "KeyBindManager.h"
#include "KeyBind.h"
#include "MemKeyBind.h"
#include "PixelCollider.h"
#include "Floor.h"
#include "Text.h"
#include "Physics.h"
#include "StarBoy.h"
#include "StarBoyHome.h"
#include "StartText.h"
#include "StartText2.h"
#include "PickUp.h"


using namespace preydator;


void printTime() {
	std::cout << "Passed time in seconds: " << SDL_GetTicks() / 1000 << std::endl;
}


int main(int argc, char** argv) {

	if (preyDator.initialize()){
		
		//GameSession can be initialized with maxFPS, default is 60.
		GameSession gameSession;
		
		Scene * scene1 = Scene::createScene(1);
		Scene * scene2 = Scene::createScene(2);
		Scene * scene3 = Scene::createScene(3);

		//GameObjects in the Game
		StartText * title = new StartText("Title", Vector2(500, 500));
		Text * titleText = Text::create(title, 50, 255, 255, 255, 255, "STARBOY - and the infinite sadness", "Assets/BROADW.TTF");
		title->addComponent(titleText);
		title->init();
		scene2->addGameObject(title, Vector2(preyDator.getWindowWidth() / 2, (preyDator.getWindowHeight() / 2) - 200));
	
		StartText * startText = new StartText("StartText", Vector2(500, 500));
		Text * sStartText = Text::create(startText, 30, 255, 255, 255, 255, "Please, write your name: (press return when done)", "Assets/BROADW.TTF");
		startText->addComponent(sStartText);
		startText->init();
		scene2->addGameObject(startText, Vector2(preyDator.getWindowWidth()/2, preyDator.getWindowHeight() / 2));

		StartText2 * startText2 = new StartText2("StartText2", Vector2(500, 700));
		Text * sStartText2 = Text::create(startText2, 50, 255, 255, 255, 255,"", "Assets/BROADW.TTF");
		startText2->addComponent(sStartText2);
		startText2->init();
		scene2->addGameObject(startText2, Vector2(preyDator.getWindowWidth() / 2, 600));
		
		StartText * winText = new StartText("WinText", Vector2(500, 500));
		Text * wWinText = Text::create(winText, 30, 255, 255, 255, 255, "Congratulations, you saved starboy from infinite sadness", "Assets/BROADW.TTF");
		winText->addComponent(wWinText);
		winText->init();
		scene3->addGameObject(winText, Vector2(preyDator.getWindowWidth() / 2, preyDator.getWindowHeight() / 2));

		PickUp * pickUp = new PickUp("Pickup");
		Sprite * pickupSprite = Sprite::create(pickUp, "Assets/sun.png");
		PixelCollider * pickupCollider = PixelCollider::create(pickUp, pickupSprite->getWidth(), pickupSprite->getHeight(), false);
		Physics * pickupPhys = Physics::create(pickUp, 0.3, Vector2(0, 0.2), Vector2(0, 0.1));
		pickUp->addComponent(pickupSprite);
		pickUp->addComponent(pickupCollider);
		pickUp->addComponent(pickupPhys);
		scene1->addGameObject(pickUp, Vector2(600, 600));

		Player * g = new Player("Player1", Vector2(100, 650));
		AnimatedSprite * as = AnimatedSprite::create(g, "Assets/ninja.png", 5, 2);
		BoxCollider * col = BoxCollider::create(g, as->getWidth(), as->getHeight(), false);
		Physics * phys = Physics::create(g, 0.6f, { 0, 0.1 }, { 0, 0.3 });

		g->addComponent(as);
		g->addComponent(col);
		g->addComponent(phys);
		g->init();
		scene1->addGameObject(g, Vector2(100, 650));
		
		keyBindManager.bindMemberFunctionToKey(SDLK_r, g, &Player::printName);
		keyBindManager.bindFunctionToKey(SDLK_u, printTime);

		Player2 * g2 = new Player2("Enemy", Vector2(450, 300));
		AnimatedSprite * s2 = AnimatedSprite::create(g2, "Assets/scott_small_oneway.png", 8, 1);
		BoxCollider * col2 = BoxCollider::create(g2, s2->getWidth(), s2->getHeight(), false);
		Physics * physics = Physics::create(g2, 0.3f, { 0, 0.0 }, { 0, 0.5 });
		g2->addComponent(s2);
		g2->addComponent(col2);
		g2->addComponent(physics);
		g2->init();
		scene1->addGameObject(g2, Vector2(450, 300));

		Player2 * g3 = new Player2("Enemy", Vector2(200, 650));
		AnimatedSprite * s10 = AnimatedSprite::create(g3, "Assets/scott_small_oneway.png", 8, 1);
		BoxCollider * col10 = BoxCollider::create(g3, s10->getWidth(), s10->getHeight(), false);
		Physics * physics2 = Physics::create(g3, 0.3f, { 0, 0.0 }, { 0, 0.5 });
		g3->addComponent(s10);
		g3->addComponent(col10);
		g3->addComponent(physics2);
		g3->init();
		scene1->addGameObject(g3, Vector2(100, 550));

		Player2 * g4 = new Player2("Enemy", Vector2(50, 300));
		AnimatedSprite * s11 = AnimatedSprite::create(g4, "Assets/scott_small_oneway.png", 8, 1);
		BoxCollider * col11 = BoxCollider::create(g4, s11->getWidth(), s11->getHeight(), false);
		Physics * physics3 = Physics::create(g4, 0.3f, { 0, 0.0 }, { 0, 0.5 });
		g4->addComponent(s11);
		g4->addComponent(col11);
		g4->addComponent(physics3);
		g4->init();
		scene1->addGameObject(g4, Vector2(50, 300));

		StarBoy * starBoy = new StarBoy("StarBoy");
		AnimatedSprite * starBoySprite = AnimatedSprite::create(starBoy, "Assets/starboy.png", 2, 1);
		BoxCollider * starBoyCol = BoxCollider::create(starBoy, starBoySprite->getWidth(), starBoySprite->getHeight(), false);
		Physics * starBoyPhys = Physics::create(starBoy, 1.0f, Vector2(0, 0.4), Vector2(0, 0.5));
		starBoy->addComponent(starBoySprite);
		starBoy->addComponent(starBoyCol);
		starBoy->addComponent(starBoyPhys);
		starBoy->init();
		scene1->addGameObject(starBoy, Vector2(700, 100));

		StarBoyHome * SBHome = new StarBoyHome("Home");
		AnimatedSprite * homeSprite = AnimatedSprite::create(SBHome, "Assets/starhome.png", 6, 1);
		BoxCollider * homeCollider = BoxCollider::create(SBHome, homeSprite->getWidth(), homeSprite->getHeight(), true);
		SBHome->addComponent(homeSprite);
		SBHome->addComponent(homeCollider);
		SBHome->init();
		scene1->addGameObject(SBHome, Vector2(900, 700));

		

		Floor * floor1 = new Floor("Floor");
		Sprite * s5 = Sprite::create(floor1, "Assets/floor.png");
		BoxCollider * b5 = BoxCollider::create(floor1, s5->getWidth(), s5->getHeight(), true);
		floor1->addComponent(s5);
		floor1->addComponent(b5);
		floor1->init();
		scene1->addGameObject(floor1, Vector2(200, 600));

		Floor * floor2 = new Floor("Floor");
		Sprite * s6 = Sprite::create(floor2, "Assets/floor.png");
		BoxCollider * b6 = BoxCollider::create(floor2, s6->getWidth(), s6->getHeight(), true);
		floor2->addComponent(s6);
		floor2->addComponent(b6);
		floor2->init();
		scene1->addGameObject(floor2, Vector2(600, 400));

		Floor * floor3 = new Floor("Floor");
		Sprite * s7 = Sprite::create(floor3, "Assets/floor.png");
		BoxCollider * b7 = BoxCollider::create(floor3, s7->getWidth(), s7->getHeight(), true);
		floor3->addComponent(s7);
		floor3->addComponent(b7);
		floor3->init();
		scene1->addGameObject(floor3, Vector2(0, 300));

		Floor * floor4 = new Floor("Floor");
		Sprite * s8 = Sprite::create(floor4, "Assets/floor.png");
		BoxCollider * b8 = BoxCollider::create(floor4, s8->getWidth(), s8->getHeight(), true);
		floor4->addComponent(s8);
		floor4->addComponent(b8);
		floor4->init();
		scene1->addGameObject(floor4, Vector2(600, 200));


		for (int i = 0; i < 3; i++) {
			Floor * floor = new Floor("Floor");
			Sprite * s4 = Sprite::create(floor, "Assets/floor.png");
			BoxCollider * b4 = BoxCollider::create(floor, s4->getWidth(), s4->getHeight(), true);

			floor->addComponent(s4);
			floor->addComponent(b4);
			floor->init();
			scene1->addGameObject(floor, Vector2(i * 500, preyDator.getWindowHeight()));
		}

		for (int i = 0; i < 3; i++) {
			Floor * floor = new Floor("Floor");
			Sprite * s4 = Sprite::create(floor, "Assets/floor.png");
			BoxCollider * b4 = BoxCollider::create(floor, s4->getWidth(), s4->getHeight(), true);

			floor->addComponent(s4);
			floor->addComponent(b4);
			floor->init();
			scene1->addGameObject(floor, Vector2(i * 500, 25));
		}

		for (int i = 0; i < 3; i++) {
			Floor * floor = new Floor("Wall");
			Sprite * s4 = Sprite::create(floor, "Assets/wall.png");
			BoxCollider * b4 = BoxCollider::create(floor, s4->getWidth(), s4->getHeight(), true);

			floor->addComponent(s4);
			floor->addComponent(b4);
			floor->init();
			scene1->addGameObject(floor, Vector2(0, i * 500));
		}

		for (int i = 0; i < 3; i++) {
			Floor * floor = new Floor("Wall");
			Sprite * s4 = Sprite::create(floor, "Assets/wall.png");
			BoxCollider * b4 = BoxCollider::create(floor, s4->getWidth(), s4->getHeight(), true);

			floor->addComponent(s4);
			floor->addComponent(b4);
			floor->init();
			scene1->addGameObject(floor, Vector2(preyDator.getWindowWidth(), i * 500));
		}

		
		
		
		//Scenes are added to game
		sceneManager.addScene(scene1);
		sceneManager.addScene(scene2);
		sceneManager.addScene(scene3);
		
		
		
		//Startscene is loaded
		sceneManager.loadScene(2);
		
		//Loop is started
		gameSession.runLoop();
		}
		
	
	
		
	return 0;
}