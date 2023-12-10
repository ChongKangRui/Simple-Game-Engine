#pragma once


// circular dependency!


namespace GameEngine {
	
	
	class SceneStateMachine;

	//! This documentation will briefing the usage of %Scene. %Scene is a base class that can inherited/derived from other class to create a Scene(such as GameScene, LoseScene, SplashScene and etc)
	class Scene
	{
	
	public:
		//! Here is how to create a derive scene
		/*!
		* Sample Usage:
		*\code{.h}
		*#include "Scene.h"
		*using namespace GameEngine;
		*
		*class AScene : public Scene{
		* 
		* //You can have the derived function from scene.
		* public:
		* 
		*   // initialize is a function that use to initial the stuff when this class is created.
			void initialize() override;
			void dispose()override;

			void activate()override;
			void deactivate()override;

		* 
		* 
		* }
		*
		
		* \endcode
		*
		*/
		virtual void initialize();


		virtual void dispose();

		//! This function will trigger when the scene is activate. This function can override.
		virtual void activate();

		//! This function will trigger when the scene is deactivate. This function can override.
		virtual void deactivate();

		//! This function will update every frame. Usually put the objectCollection.update here
		virtual void update(float deltaTime);

		//! This function will render every frame. Usually put the objectCollection.render here
		virtual void render();

		//! Use to set the SceneStateMachine
		void setStateMachine(SceneStateMachine* sm);

		//! Get the window size. It already put inside the SceneStateMachine Class
		void getWindowSize(int width, int height);
		//virtual const std::string getName() = 0;
		
	protected:
		//! The width and height of window. Can use both attribute when object will need to get the size of window
		int WindowWidth, WindowHeight;

		//! Everytime a scene created, the Scene will store inside the SceneStateMachine. SceneStateMachine also can be used to switch between scene and scene. 
		SceneStateMachine* stateMachine;
	};
};