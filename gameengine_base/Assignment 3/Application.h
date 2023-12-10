#pragma once
#include <string>
#include "Window.h"

namespace GameEngine {
	//! This documentation will briefing the usage of %Application. %Application is a class that as a base to support the game engine working
	class Application
	{
	public:
		//! constructor, declare an empty one for now
		Application();
		//! destructor, declare an empty one for now
		~Application();

		//! initializes Window, keeps track of success or failure using isInitialized
		bool Initialize(int width, int height);

		//! if Initialize not called, log to console and return
		/*! otherwise, bind to window events.*/
		void SetupEventCallbacks();

		//! if Initialize not called, log to console and return
		/*! otherwise, enter application loop until window closes.*/
		void Run();

		//! use to set the fps
		/*! A sample code provided here
		* Sample Usage:
		*\code{.cpp}
		*#include "Application.h"
		*#include "InputSystem.h"
		*using namespace GameEngine;
		* 
		*int main(){
		*
		* if(InputSystem::IsKeyDownThisFrame(Q)){
		* setFrameRate(30);
		* }
		* 
		* return 0;
		*
		* }
		* \endcode
		*/
		void setFrameRate(int fr);

		//! deltaTime that support frame rate for game engine.
		float deltaTime;

		//! A static function that use to quit application
		/*! A sample code provided here
		* Sample Usage:
		*\code{.cpp}
		*#include "Application.h"
		*#include "InputSystem.h"
		*using namespace GameEngine;
		*
		*int main(){
		*
		* if(InputSystem::IsKeyDownThisFrame(Q)){
		* Application::Quit();
		* }
		*
		* return 0;
		*}
		* \endcode
		*/
		static void Quit();

	

	private:
		void OnWindowEventFired(std::string& evt);
		// Cache initialize state, so that we can check if application inits or not.
		bool isInitialized = false;

		bool isRunning = false;

		float frameTime = 0;


		// The Window object
		Window window;


	};
};
