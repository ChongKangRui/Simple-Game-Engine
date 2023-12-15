#include "GameScene.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

#include "Bullet.h"
#include "Meteorite.h"
#include "ButtonComponent.h"
#include "SimpleSpriteRenderer.h"



using namespace GameEngine;
using namespace Showcase;

void GameScene::initialize() {
	//initialize the duration
	switchSceneDuration = 0;

	//Initialize game object
	BG = new GameObject("BackGround");
	Ship = new GameObject("Ship");

	//get background image component
	auto sprite = BG->addComponent<SimpleSpriteRenderer>();
	auto BGTransform = BG->getComponent<Transform>();

	//get ship component
	//note that sprite and translate had handle in shipcontroller
	shipController = Ship->addComponent<ShipController>();
	shipController->SetOC(objectCollection);

	//set background position
	BGTransform->translate(400, 300, 0);


	//set background size and texture
	sprite->loadTexture("../Asset/BG.png");
	sprite->setTextureResize(800, 800);

	objectCollection.add(BG);
	objectCollection.add(Ship);

	meteoriteCollector = new std::vector<GameEngine::GameObject*>();

};

void  GameScene::dispose() {}

void  GameScene::activate() {
	printf("GameScene activated\n");
	initialize();

};
void  GameScene::deactivate() {
	printf("GameScene deactivated\n");
}

const std::string  GameScene::getName() {
	return "GameScene";
}

void GameScene::update(float deltaTime) {

	

	

	if (spawnDuration >= 1.5f) {
		//printf("Metreo coming!!\n");
		GameObject* Metreo = new GameObject("Meteorite");

		auto mComponent = Metreo->addComponent<Meteorite>();
		auto transform = Metreo->getComponent<Transform>();

		int randomXPos = 50 + (rand() % WindowWidth - 50);

		transform->translate(randomXPos, WindowHeight, 0);

		mComponent->getPlayer(Ship);

		mComponent->SetMetroRef(meteoriteCollector);

		meteoriteCollector->push_back(Metreo);
		objectCollection.add(Metreo);

		spawnDuration = 0;
	}
	else {
		spawnDuration += deltaTime;
		
	}


	if (!Ship->shouldBeRemoved()) {
		Ship->getComponent<ShipController>()->getWindowSize(WindowWidth, WindowHeight);

		if (!CanShoot) {
			currentShootCD -= deltaTime;

			if (currentShootCD <= 0)
				CanShoot = true;
		}


		/////////////// do this in level cause of stable referencing for objectCollection
		if (InputSystem::IsKeyDown(SPACE)) {

			

			if (CanShoot) {
				CanShoot = false;

				currentShootCD = bulletShootCD;

				GameObject* b = new GameObject("Bullet");

				auto bComponent = b->addComponent<Bullet>();
				auto btransform = b->getComponent<Transform>();
				auto trans = Ship->getComponent<Transform>();

				bComponent->SetMetroRef(meteoriteCollector);

				//bComponent->SetMetroRef();
				btransform->translate(trans->position.x, trans->position.y, trans->position.z + 1.0f);

				
				objectCollection.add(b);
			}

		}

	}

	if (Ship->shouldBeRemoved()) {
		switchSceneDuration += deltaTime;
		if (switchSceneDuration >= 1.0f) {
			stateMachine->loadScene("LoseScene");
		}
	}

	if (!BG->shouldBeRemoved()) {
		BG->getComponent<SimpleSpriteRenderer>()->setTextureResize(WindowWidth + 200, WindowHeight + 200);
	}
	




	
	objectCollection.update(deltaTime);
	



}

void  GameScene::render() {
	objectCollection.render();
}


