#include "Meteorite.h"
#include <iostream>
#include "SimpleSpriteRenderer.h"

using namespace Showcase;
using namespace GameEngine;

Meteorite::Meteorite(GameObject* go) : BaseComponent(go) {
	transform = owner->getComponent<Transform>();
	auto sprite = owner->addComponent<SimpleSpriteRenderer>();

	sprite->loadTexture("../Asset/Metreo.png");

	sprite->setTextureResize(200, 200);

	speed = 2;

}
Meteorite::~Meteorite(){
	//Metro->erase(std::remove(Metro->begin(), Metro->end(), owner), Metro->end());
}

void Meteorite::update(float deltaTime) {
	
	if (transform->position.y > 50) {
		transform->translate(transform->position.x, transform->position.y - speed, transform->position.z);
		transform->rotate(transform->rotation.x, transform->rotation.y, transform->rotation.z + speed);
	}
	else {
		RemoveFromMetroList();
		owner->markForRemoval();
	}


	if (hp <= 0) {
		RemoveFromMetroList();
		owner->markForRemoval();
	}
	


	if (!playerobj->shouldBeRemoved()) {

		
		auto sprite = owner->getComponent<SimpleSpriteRenderer>();

		auto playersprite = playerobj->getComponent<SimpleSpriteRenderer>();
		auto playertransform = playerobj->getComponent<Transform>();

		double width = playersprite->getWidth();
		double height = playersprite->getHeight();

		double objX = playertransform->position.x;
		double objY = playertransform->position.y;

		double selfWidth = sprite->getWidth();
		double selfHeight = sprite->getHeight();


	
		if ( (objX - width / 2) >= (transform->position.x - selfWidth / 2) && (objX + width / 2) <= (transform->position.x + selfWidth / 2))
		{
			if ((objY - height / 2) >= (transform->position.y - selfHeight / 2) && (objY + height / 2) <= (transform->position.y + selfHeight / 2)) {
				playerobj->markForRemoval();
			}
		}

		

	}



}

void  Meteorite::getCurrentWindowSize(int width, int height) {
	windowWidth = width;
	windowHeight = height;
}

void  Meteorite::getPlayer(GameObject* player) {
	playerobj = player;
}

void Showcase::Meteorite::MinusHP()
{
	hp--;
}


void Meteorite::SetMetroRef(std::vector<GameEngine::GameObject*>* metroCollection)
{
	Metro = metroCollection;
}

void Showcase::Meteorite::RemoveFromMetroList()
{


	auto itToRemove = std::find(Metro->begin(), Metro->end(), owner);

	if (itToRemove != Metro->end()) {

		Metro->erase(itToRemove, Metro->end());
	}


}
