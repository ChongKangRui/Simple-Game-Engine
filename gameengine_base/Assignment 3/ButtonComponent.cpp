#include "ButtonComponent.h"
#include <iostream>
#include "Application.h"
#include "SimpleSpriteRenderer.h"

GameEngine::ButtonComponent::ButtonComponent(GameObject* go) : GameEngine::BaseComponent(go) {

}

GameEngine::ButtonComponent::~ButtonComponent() {

};


void GameEngine::ButtonComponent::dropListener(int id) {
	signal.disconnect(id);
}

void GameEngine::ButtonComponent::dropAllListener() {
	signal.disconnect_all();
}

void GameEngine::ButtonComponent::OnClick() {
	signal.emit();

}


void GameEngine::ButtonComponent::update(float deltaTime) {


	
	double mouseX = InputSystem::GetMousePosX();
	double mouseY = InputSystem::GetMousePosY();

	auto sprite = owner->getComponent<SimpleSpriteRenderer>();
	auto transform = owner->getComponent<Transform>();

	double width = sprite->getWidth();
	double height = sprite->getHeight();

	double objX = transform->position.x;
	double objY = transform->position.y;

	
	if (mouseX >= (objX - width / 2) && mouseX <= (objX + width / 2))
	{
		if (mouseY >= (objY - height / 2) && mouseY <= (objY + height / 2)) {

			sprite->setColor(sprite->r, sprite->g, sprite->b, 0.7f);

			if (InputSystem::IsMouseDownThisFrame(LEFTMOUSE)) {
				OnClick();
			}
		}
	}
	else {
		sprite->setColor(1.0f, 1.0f,1.0f, 1.0f);
	}



}