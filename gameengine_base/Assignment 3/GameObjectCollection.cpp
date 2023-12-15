#include "GameObjectCollection.h"

void GameEngine::GameObjectCollection::add(GameEngine::GameObject* go) {
	toBeAddedGameObjects.push_back(go);
}

void GameEngine::GameObjectCollection::update(float deltaTime) {

	processRemovals();
	processNewGameObjects();

	for (auto& go : gameObject) {
		go->update(deltaTime);
	}
}
void GameEngine::GameObjectCollection::render() {
	for (auto& go : gameObject) {
		go->render();
	}
}

int GameEngine::GameObjectCollection::getCount() {
	return gameObject.size();
}
void GameEngine::GameObjectCollection::clearAllObject() {
	for ( auto obj : gameObject)
	{
		obj->markForRemoval();
	}
}

void GameEngine::GameObjectCollection::processNewGameObjects() {
	//only do process if tobeaddedgameobjects size > 0
	if (toBeAddedGameObjects.size() > 0) {
		//Call awake and start for all game object
		for (auto& go : toBeAddedGameObjects)
		{
			go->OnEnable();
		}

		for (auto& go : toBeAddedGameObjects)
		{
			go->awake();
		}

		for (auto& go : toBeAddedGameObjects)
		{
			go->start();
		}

		//add to gameobject list
		gameObject.insert(gameObject.end(), toBeAddedGameObjects.begin(), toBeAddedGameObjects.end());

		//clean up tobeaddedgameobject
		toBeAddedGameObjects.clear();
	}


}
//free function
bool CheckIFGameObjectShouldBeRemove(GameEngine::GameObject* go) {
	bool shouldBeRemoved = go->shouldBeRemoved();
	if (shouldBeRemoved){

		go->OnDisable();
		delete go;
}
	return shouldBeRemoved;
}


void GameEngine::GameObjectCollection::processRemovals() {
	//find all game object that is removal
	auto it = std::remove_if(gameObject.begin(), gameObject.end(), CheckIFGameObjectShouldBeRemove);
	
	gameObject.erase(it, gameObject.end());
}
