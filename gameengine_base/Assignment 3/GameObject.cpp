#include "GameObject.h"
#include <iostream>



GameEngine::GameObject::GameObject(const std::string& name) : name(name), markedForRemoval(false) {
	//Constructor will be implemented next week
	//auto transform = this->addComponent<Transform>();
	transform = this->addComponent<Transform>();
	transform->scale(1, 1, 1);
	
}

GameEngine::GameObject::~GameObject() {
	for (auto& c: components)
	{
		delete c;
	}

	components.clear();
}

void GameEngine::GameObject::OnEnable() {
	//printf("OnEnable for %s\n", name.c_str());
	for (auto& c : components) {
		c->OnEnable();
	}
}

void GameEngine::GameObject::OnDisable() {
	//printf("OnDisable for %s\n", name.c_str());
	for (auto& c : components) {
		c->OnDisable();
	}
}

void GameEngine::GameObject::awake(){
	//printf("awake for %s\n", name.c_str());
	for (auto& c : components) {
		c->awake();
	}
}

void GameEngine::GameObject::start() {
	//printf("start for %s\n", name.c_str());
	for (auto& c : components) {
		c->start();
	}
}
void GameEngine::GameObject::update(float deltaTime) {
	//printf("updating gameobject %s\n", name.c_str());

	for (auto& c : components) {
		c->update(deltaTime);
	}
}
void GameEngine::GameObject::render() {
	for (int i = 0; i < components.size(); i++) {
		components[i]->render();
	}
}

const std::string GameEngine::GameObject::getName() {
	return name;
}
bool GameEngine::GameObject::shouldBeRemoved() {
	return markedForRemoval;
}

void GameEngine::GameObject::markForRemoval() {
	markedForRemoval = true;
}