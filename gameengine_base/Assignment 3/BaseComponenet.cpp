

#include "BaseComponent.h"


GameEngine::BaseComponent::BaseComponent(GameObject* go) : owner(go) {}

GameEngine::BaseComponent::~BaseComponent() {  }
void GameEngine::BaseComponent::awake() {}
void GameEngine::BaseComponent::start() {}
void GameEngine::BaseComponent::update(float deltaTime) {}
void GameEngine::BaseComponent::render() {}
void GameEngine::BaseComponent::OnEnable(){}
void GameEngine::BaseComponent::OnDisable(){ }