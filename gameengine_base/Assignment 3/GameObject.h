#pragma once
#include <string>
#include <vector>
#include "BaseComponent.h"
#include "Transform.h"



namespace GameEngine {
	//! This documentation will briefing the usage of %GameObject. %GameObject is a class that can use to create a game object

	class GameObject {
	public:

		//! name for %GameObject is needed when create a %GameObject
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*using namespace GameEngine;
		*
		* 
		* 
		*int main(){
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
		* return 0;
		* }
		* \endcode
		*
		*/
		GameObject(const std::string& name);


		//! When %GameObject is destruct, this function will be trigger.
		/*! This function is used to delete all componenet that attact to the game object
		*/
		~GameObject();


		//! When %GameObject is enable, this function will be trigger.
		/*! This will trigger the OnEnable function of all component
		* */
		void OnEnable();

		//! Trigger once when object awake
		/*! This will trigger the awake function of all component
		*/
		void awake();

		//! Trigger once after awake
		/*! This will trigger the start function of all component
		*/
		void start();

		//! Update everyframe 
		/*! This will trigger the update function of all component
		*/
		void update(float deltaTime);

		//! Render everyframe 
		/*! This will trigger the render function of all component
		*/
		void render();

		//! When object is disable, this function will be trigger
		/*! This will trigger the OnDisable function of all component
		*/
		void OnDisable();

		//! Get the name of game object
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*using namespace GameEngine;
		*
		*int main(){
		* 
		* GameObject* obj = new GameObject("OBJ");
		* 
		* //console will print OBJ
		* print("%s\n", obj->getName());
		* 
		* 
		* return 0
		* }
		* \endcode
		*/
		const std::string getName();

		//! This function will return true if the object is gonna get destroyed and return false if object still exist
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*using namespace GameEngine;
		*
		*int main(){
		* 
		* GameObject* obj = new GameObject("OBJ");
		* if(!obj.shouldBeRemoved()){
		*   //Game Object still exist
		* }
		* else{
		*  //Game Object gonna removed
		* }
		* 
		* return 0
		* }
		* \endcode
		*/
		bool shouldBeRemoved();

		//! This function can be call to destroy the game object
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*using namespace GameEngine;
		* 
		*int main(){
		*
		* GameObject* obj = new GameObject("OBJ");
		* 
		* GameObjectCollection* collection = new GameObjectCollection();
		* 
		* 
		* //Everytime create an object, it needed to add to the collection in order to manage the obj.
		* //GameObjectCollection also taking the responsibility to make all of the gameobject's update/render working at the same time.
		* collection.add(obj);
		* 
		* //it will remove from collection list.
		* obj.markForRemoval();
		* 
		* return 0;
		* }
		*
		* \endcode
		*/
		void markForRemoval();





		//Template need to define in header file no sourfile.,.
		template<typename T, typename = typename std::enable_if<std::is_base_of<GameEngine::BaseComponent, T>::value>::type>

		//! This function can be use to add component to the game object
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "SimpleSpriteRenderer.h"
		*#include "GameObject.h"
		* 
		*int main(){
		* 
		* GameObject* obj = new GameObject("OBJ");
		* auto spriteComponent = obj->addComponent<SimpleSpriteRenderer>();
		*
		* return 0;
		* }
		* \endcode
		*/
		T* addComponent() {
			//Construct the component that we want
			//pass in this Gamei=object to be owner
			//Add to list of component
			//return the component


			T* newComponent = new T(this);
			components.push_back(newComponent);

			return newComponent;
		}

		template<typename T, typename = typename std::enable_if<std::is_base_of<GameEngine::BaseComponent, T>::value>::type>

		//! This function can be use to get existing component from game object
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "SimpleSpriteRenderer.h"
		*#include "GameObject.h"
		* 
		*int main(){
		* 
		* GameObject* obj = new GameObject("OBJ");
		* auto spriteComponent = obj->getComponent<SimpleSpriteRenderer>();
		*
		* return 0;
		* }
		* \endcode
		*/

		T* getComponent() {
			//iterate the vector to find component that matches the type
			// return the first item found
			for (auto& c : components) {
				//if (typeid(*c) == typeid(T)) {

				auto t = dynamic_cast<T*>(c);
				if (t) {
					return (T*)c;
				}
			}

			return nullptr;
		}




	private:
		bool markedForRemoval = false;
		//Stack and heap memory
		//stack is faster, but writing code
		//to support stack-based memory is a hassle
		//Heap is slower, but allows flexibility
		// object = new SpriteComponent();
		//When not in use anymore, call delete to delete object
		std::vector<GameEngine::BaseComponent*> components;
		std::string name;
		Transform* transform;



	};
};
