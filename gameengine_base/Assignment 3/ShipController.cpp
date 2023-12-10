#include "ShipController.h"
#include <iostream>
#include "SimpleSpriteRenderer.h"


using namespace GameEngine;
using namespace Showcase;


ShipController::ShipController(GameObject* go) : BaseComponent(go) {
 transform = go->getComponent<Transform>();
 transform->translate(400, 100, 0);
 

 auto shipSprite = owner->addComponent<SimpleSpriteRenderer>();
 shipSprite->loadTexture("../Asset/Ship.png");
 shipSprite->setTextureResize(100, 50);

 speed = 5.0f;
};
ShipController::~ShipController() {
	
};

void ShipController::update(float deltaTime) {
	
	if (InputSystem::IsKeyDown(W)) {
		if (transform->position.y < windowHeight) {
			
			transform->translate(transform->position.x, transform->position.y + speed , 0);
		}
	}
	if (InputSystem::IsKeyDown(D)) {
		if (transform->position.x < windowWidth) {
			transform->translate(transform->position.x + speed , transform->position.y, 0);
			
		}
	}
	if (InputSystem::IsKeyDown(S)) {
		if (transform->position.y > 0) {
			transform->translate(transform->position.x , transform->position.y - speed , 0);
		}
	}
	if (InputSystem::IsKeyDown(A)) {
		if (transform->position.x > 0) {
			transform->translate(transform->position.x - speed, transform->position.y, 0);
			
		}
	}
};



void ShipController::getWindowSize(int width, int height) {
	windowWidth = width;
	windowHeight = height;
}
