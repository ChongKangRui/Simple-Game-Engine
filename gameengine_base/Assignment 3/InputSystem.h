#pragma once
#include <glfw/glfw3.h>;
#include <map>;



enum KeyCode
{
	A = GLFW_KEY_A,
	B = GLFW_KEY_B,
	C = GLFW_KEY_C,
	D = GLFW_KEY_D,
	E = GLFW_KEY_E,
	F = GLFW_KEY_F,
	G = GLFW_KEY_G,
	H = GLFW_KEY_H,
	I = GLFW_KEY_I,
	J = GLFW_KEY_J,
	K = GLFW_KEY_K,
	L = GLFW_KEY_L,
	M = GLFW_KEY_M,
	N = GLFW_KEY_N,
	O = GLFW_KEY_O,
	P = GLFW_KEY_P,
	Q = GLFW_KEY_Q,
	R = GLFW_KEY_R,
	S = GLFW_KEY_S,
	T = GLFW_KEY_T,
	U = GLFW_KEY_U,
	V = GLFW_KEY_V,
	W = GLFW_KEY_W,
	X = GLFW_KEY_X,
	Y = GLFW_KEY_Y,
	Z = GLFW_KEY_Z,

	NUMBER0 = GLFW_KEY_0,
	NUMBER1 = GLFW_KEY_1,
	NUMBER2 = GLFW_KEY_2,
	NUMBER3 = GLFW_KEY_3,
	NUMBER4 = GLFW_KEY_4,
	NUMBER5 = GLFW_KEY_5,
	NUMBER6 = GLFW_KEY_6,
	NUMBER7 = GLFW_KEY_7,
	NUMBER8 = GLFW_KEY_8,
	NUMBER9 = GLFW_KEY_9,

	LCTRL = GLFW_KEY_LEFT_CONTROL,
	RCTRL = GLFW_KEY_RIGHT_CONTROL,

	UPARROW = GLFW_KEY_UP,
	DOWNARROW = GLFW_KEY_DOWN,
	RIGHTARROW = GLFW_KEY_RIGHT,
	LEFTARROW = GLFW_KEY_LEFT,

	LALT = GLFW_KEY_LEFT_ALT,
	RALT = GLFW_KEY_RIGHT_ALT,

	SPACE = GLFW_KEY_SPACE,

	LSHIFT = GLFW_KEY_LEFT_SHIFT,
	RSHIFT = GLFW_KEY_RIGHT_SHIFT,

	/*LEFTMOUSE = GLFW_MOUSE_BUTTON_LEFT,
	RIGHTMOUSE = GLFW_MOUSE_BUTTON_RIGHT,*/
};

enum MouseButton
{
	LEFTMOUSE = GLFW_MOUSE_BUTTON_LEFT,
	RIGHTMOUSE = GLFW_MOUSE_BUTTON_RIGHT,
};


namespace GameEngine {
	
	extern std::map<KeyCode, bool> currentStates;

	extern std::map<KeyCode, bool> prevStates;

	extern std::map<MouseButton, bool> mouseCurStates;

	extern std::map<MouseButton, bool> mousePrevStates;

	
	
	
	//! This documentation will briefing the usage of %InputSystem. %InputSystem is a class that can use to create an Input System for the player
	//! %InputSystem has contain 26 letter alphabet, 0-9 number, LCTRL/RCTRL, LALT/RALT, SPACE, LSHIFT/RSHIFT and LEFtMOUSE/RIGHTMOUSE. 
	class InputSystem {
		
	public:
		
		//! This function is set in the application.cpp.
		//! This function is use to detect the user input
		static void keyProcessInput();

		//! This function is use to detect the user had press once or not
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "InputSystem.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* if(IsKeyDownThisFrame(A)){
		* //Will printf this string once
		*	printf("User had pressed A this frame \n");
		* }
		* 
		* 
		* return 0;
		* }
		* \endcode
		*
		*/
		static bool IsKeyDownThisFrame(KeyCode key);

		//! This function will keep detect the user is pressing or not
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "InputSystem.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* if(IsKeyDown(A)){
		*	//Will printf this string every frame
		*	printf("User is pressing A \n");
		* }
		*
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		static bool IsKeyDown(KeyCode key);

		//! This function will detect the user up or not after they pressed
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "InputSystem.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* if(IsKeyUpThisFrame(A)){
		*	//Will printf this string once
		*	printf("User is Up A this frame\n");
		* }
		*
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		static bool IsKeyUpThisFrame(KeyCode key);

		//! This function will use to get the window reference.
		//! It is also set in the application.cpp
		static void setUp(GLFWwindow* window);

		//! This function is use to detect the user had press mouse once or not
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "InputSystem.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* if(IsMouseDownThisFrame(LEFTMOUSE)){
		* //Will printf this string once
		*	printf("User had click left mouse this frame \n");
		* }
		*
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		static bool IsMouseDownThisFrame(MouseButton key);

		//! This function is use to detect the user had press mouse once or not
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "InputSystem.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* if(IsMouseDown(LEFTMOUSE)){
		* //Will printf this string every frame
		*	printf("User is clicking left mouse this frame \n");
		* }
		*
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		static bool IsMouseDown(MouseButton key);

		//! This function is use to detect the user had press mouse once or not
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "InputSystem.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* if(IsMouseUpThisFrame(LEFTMOUSE)){
		* //Will printf this string once
		*	printf("User is up left mouse this frame \n");
		* }
		*
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		static bool IsMouseUpThisFrame(MouseButton key);

		//! This function is use to get the mouse position x
		static const double GetMousePosX();
		//! This function is use to get the mouse position Y
		static const double GetMousePosY();

		//! This function is use to get the window size
		static void getWindowSize(int width, int height);

	private: 
		static InputSystem inputInstance;

		GLFWwindow* windowRef;
		InputSystem();
		
	};
};




