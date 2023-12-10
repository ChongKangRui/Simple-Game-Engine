#include "Scene.h"

void GameEngine::Scene::initialize() {};
void GameEngine::Scene::dispose() {};
 void GameEngine::Scene::activate() {};
 void GameEngine::Scene::deactivate() {};
 void GameEngine::Scene::update(float deltaTime) {};
 void GameEngine::Scene::render() {};
 void GameEngine::Scene::getWindowSize(int width, int height) {
	 WindowWidth = width;
	 WindowHeight = height;

	 
 };


 void GameEngine::Scene::setStateMachine(SceneStateMachine* sm) {
	stateMachine = sm;
}