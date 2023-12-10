#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <string>
#include <functional>



	typedef std::function<void(std::string)> SimpleEventCallbackFn;
namespace GameEngine {
	//! This documentation will briefing the usage of %Window. %Window is a class that use to create the window. Most of the window function will be put in the application run function
	class Window
	{

	public:
		// cleanup
		~Window();

		//! creates GLFWwindow and declare GLFWwindow event callback behaviours
		int Initialize(int width, int height, std::string& title);

		//! last thing to do in application loop
		void SwapAndPoll(float deltaTime);

		//! This function will returns window
		GLFWwindow* getWindow() const {
			return window;
		}

		//! Set the window event call backs
		void SetWindowEventCallBacks(const SimpleEventCallbackFn& callback);

		//! Get width of window.
		int getWidth();

		//! Get width of window.
		int getHeight();

		//! Set current window size and store the data
		void setCurrentWindowSize(int width, int height);



	private:

		struct WindowData {
			int width, height;
			std::string title;

			SimpleEventCallbackFn callbackFn;
		};

		WindowData data;

		GLFWwindow* window;
	};
};
