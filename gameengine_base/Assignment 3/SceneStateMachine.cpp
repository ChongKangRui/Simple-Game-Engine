#include "SceneStateMachine.h"
#include <iostream>

void GameEngine::SceneStateMachine::render() {
	currentScene->getWindowSize(WindowWidth, WindowHeight);
	currentScene->render();
}

void GameEngine::SceneStateMachine::update(float deltaTime) {
	currentScene->update(deltaTime);
	
}

void GameEngine::SceneStateMachine::loadScene
(const std::string name) {
	std::unordered_map<std::string, GameEngine::Scene*>::iterator it = scenes.find(name);
	if (it != scenes.end()) {
		if (currentScene != nullptr)
			currentScene->deactivate();

		currentScene = it->second;
		currentScene->activate();
	}
}


void GameEngine::SceneStateMachine::getWindowSize(int width, int height) {
	WindowWidth = width;
	WindowHeight = height;

	currentScene->getWindowSize(WindowWidth, WindowHeight);
}