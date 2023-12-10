#pragma once
#include "GameObject.h"
#include <vector>


namespace GameEngine {
	//! This documentation will briefing the usage of %GameObjectCollection. %GameObjectCollection is a class that will use to store all the game object
	class GameObjectCollection
	{
	public:
		//! Add function can be used to add the created game object. This is necessary to added in order to make the created game object component and render work!
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		*
		*
		*start(){
		*
		* //create a game object and give it a name
		* GameObject* obj = new GameObject("OBJ");
		*
		* GameObjectCollection* collection = new GameObjectCollection();
		*
		*
		* //Everytime create an object, it needed to add to the collection in order to manage the obj.
		* //GameObjectCollection also taking the responsibility to make all of the gameobject's update/render working at the same time.
		* collection.add(obj);
		*
		* 
		* }
		* \endcode
		*
		*/
		void add(GameEngine::GameObject* go);

		//! Update function will update all of the GameObject( and their components) update function that store in the list.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		*
		*
		*void Scene::start(){
		*
		* //create a game object and give it a name
		* GameObject* obj = new GameObject("OBJ");
		*
		* GameObjectCollection* collection = new GameObjectCollection();
		*
		*
		* //Everytime create an object, it needed to add to the collection in order to manage the obj.
		* //GameObjectCollection also taking the responsibility to make all of the gameobject's update/render working at the same time.
		* collection.add(obj);
		*
		*
		* }
		*
		* void Scene::update(float deltaTime){
		*
		* //This will update all of the game object component update function.
		* collection.updatr(deltaTime);
		*
		* }
		*
		*
		* \endcode
		*
		*/
		void update(float deltaTime);

		//! Render function will update all of the GameObject( and their components) render function( such as SimpleSpriteRenderer ) that store in the list.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		*
		*
		*void Scene::sstart(){
		*
		* //create a game object and give it a name
		* GameObject* obj = new GameObject("OBJ");
		*
		* GameObjectCollection* collection = new GameObjectCollection();
		*
		*
		* //Everytime create an object, it needed to add to the collection in order to manage the obj.
		* //GameObjectCollection also taking the responsibility to make all of the gameobject's update/render working at the same time.
		* collection.add(obj);
		*
		*
		* }
		*
		* void Scene::render(){
		*
		* //This will update all of the game object component update function.
		* collection.render();
		*
		* }
		*
		*
		* \endcode
		*
		*/
		void render();

		//! Get the size of the list.
		int getCount();

		//! Clear all game object that store in the list.
		void clearAllObject();

	private:
		//process all new gameobjects
		//call awake and start on them
		// then add to gameobject list
		void processNewGameObjects();

		//check if any game object flagged for deletion
		//call delete on them
		void processRemovals();

		std::vector<GameEngine::GameObject*> gameObject;
		std::vector<GameEngine::GameObject*> toBeAddedGameObjects;
	};
};

