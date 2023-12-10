#pragma once
#include "Scene.h"
#include <unordered_map>
// include unordered map

namespace GameEngine {
	//! This documentation will briefing the usage of %GameObject. %GameObject is a class that can use to create a game object
	class SceneStateMachine
	{
		
	public:
		// addScene

		template<typename T>

		//SFINAE
		//Subsititution failure is not an error
		typename std::enable_if<std::is_base_of<GameEngine::Scene, T>::value>::type

		//! This function is use to add scene to the list.
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "SceneStateMachine.h"
		* //one of the ShowCase classes
		*#include "GameScene.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* SceneStateMachine sceneManager;
		*
		* unsigned int gameSceneId = 0;
		
		
		* sceneManager.addScene<Showcase::GameScene>(gameSceneId);
 

		*
		* return 0;
		* }
		* \endcode
		*
		*/
			addScene(unsigned int& out) {
			T* newScene = new T();

			auto pair = scenes.insert(
				std::make_pair(newScene->getName(), newScene)
			);

			//pair has:
			//first : pair containing key(string ) and value(scene*)
			//second : boolean(success adding to map or fail

			if (pair.second == true) {

				pair.first->second->setStateMachine(this);
				pair.first->second->initialize();

				//1
				out = sceneIdCounter;
				sceneIdCounter++;


			}
			else {
				delete newScene;
			}
		}

		//! This function is use to load scene from list.
	/*!
	* Sample Usage:
	*\code{.cpp}
	*#include "SceneStateMachine.h"
	* //one of the ShowCase classes
	*#include "GameScene.h"
	*using namespace GameEngine;
	*
	*
	*
	*int main(){
	*
	* SceneStateMachine sceneManager;
	*
	* unsigned int gameSceneId = 0;


	* sceneManager.addScene<Showcase::GameScene>(gameSceneId);
	* 
	* //SceemManager load scene according to the name of scene.
	* //Therefore, derived scene will needed to return a name string.
	* sceneManager.loadScene("GameScene");
	*
	* return 0;
	* }
	* \endcode
	*
	*/
		void loadScene(const std::string scene);


		//! This function will update all of the scene's update function. It had been put in the application run function
		// update
		void update(float deltaTime);

		//! This function will render all of the scene's render function. It had been put in the application run function
		// render
		void render();

		//! get the window size
		void getWindowSize(int width, int height);

	private:
		// sceneMap
		std::unordered_map<std::string, GameEngine::Scene*> scenes;

		// currentScene
		GameEngine::Scene* currentScene;

		int WindowWidth, WindowHeight;

		// sceneIdCounter
		unsigned int sceneIdCounter;
	};
};
