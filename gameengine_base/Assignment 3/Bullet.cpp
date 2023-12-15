#include "Bullet.h"
#include <iostream>
#include "SimpleSpriteRenderer.h"

#include "Meteorite.h"

using namespace Showcase;
using namespace GameEngine;

Bullet::Bullet(GameObject* go) : BaseComponent(go) {
	transform = owner->getComponent<Transform>();
	auto sprite = owner->addComponent<SimpleSpriteRenderer>();

	sprite->loadTexture("../Asset/BulletSprite.png");

	sprite->setTextureResize(100, 100);


	OriginalPosY = transform->position.y;

}
Bullet::~Bullet(){
	printf("Bullet Die");
}

void Bullet::update(float deltaTime) {
	
	if (transform->position.y < OriginalPosY + 500) {
		transform->translate(transform->position.x, transform->position.y + speed, transform->position.z);
		//transform->rotate(transform->rotation.x, transform->rotation.y, transform->rotation.z + speed);
	}
	else {
		owner->markForRemoval();
		printf("Remove");
	}

	if (!owner->shouldBeRemoved()) {
		
		
			for (auto b : (*Metro)) {
		
					if (b) {
						
						auto bt = b->getComponent<Transform>();
		
						float x = bt->position.x;
						float y = bt->position.y;

					//	std::cout << "Self pos" << transform->position.x << "," << transform->position.y << std::endl;
					//	std::cout << "Hit Min:" << x - 200 << "," << x + 200 << " Max:" << y - 200 << "," << y + 400 << std::endl;
		
						if (transform->position.x >=(x - 200) && transform->position.x <=(x + 200))
						{
							if (transform->position.y>=(y - 200) && transform->position.y <= (y + 400) ) {
								auto mc = b->getComponent<Meteorite>();;
								mc->MinusHP();
		
								owner->markForRemoval();
		
								break;
							}
						}
					}
				}

	}

}

void  Bullet::getCurrentWindowSize(int width, int height) {
	windowWidth = width;
	windowHeight = height;
}



void Bullet::SetMetroRef(std::vector<GameEngine::GameObject*>* metroCollection)
{
	Metro = metroCollection;
}
