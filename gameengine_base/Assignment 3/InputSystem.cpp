#include "InputSystem.h"
#include <iostream>

int windowHeight = 600;
int windowWidth = 800;

std::map<KeyCode, bool> GameEngine::currentStates = {
		{A, false},
		{B, false},
		{C, false},
		{D, false},
		{E, false},
		{F, false},
		{G, false},
		{H, false},
		{I, false},
		{J, false},
		{K, false},
		{L, false},
		{M, false},
		{N, false},
		{O, false},
		{P, false},
		{Q, false},
		{R, false},
		{S, false},
		{T, false},
		{U, false},
		{V, false},
		{W, false},
		{X, false},
		{Y, false},
		{Z, false},

		{NUMBER0, false},
		{NUMBER1, false},
		{NUMBER2, false},
		{NUMBER3, false},
		{NUMBER4, false},
		{NUMBER5, false},
		{ NUMBER6, false },
		{ NUMBER7, false },
		{ NUMBER8, false },
		{ NUMBER9, false },

		{ LCTRL, false },
		{ RCTRL, false },


		{ UPARROW, false },
		{ DOWNARROW, false },
		{ RIGHTARROW, false },
		{ LEFTARROW, false },

		{ LALT, false },
		{ RALT, false },

		{ SPACE, false },

		{ LSHIFT, false },
		{ RSHIFT, false },



};


std::map<KeyCode, bool> GameEngine::prevStates = {
		{A, false},
		{B, false},
		{C, false},
		{D, false},
		{E, false},
		{F, false},
		{G, false},
		{H, false},
		{I, false},
		{J, false},
		{K, false},
		{L, false},
		{M, false},
		{N, false},
		{O, false},
		{P, false},
		{Q, false},
		{R, false},
		{S, false},
		{T, false},
		{U, false},
		{V, false},
		{W, false},
		{X, false},
		{Y, false},
		{Z, false},

		{NUMBER0, false},
		{NUMBER1, false},
		{NUMBER2, false},
		{NUMBER3, false},
		{NUMBER4, false},
		{NUMBER5, false},
		{NUMBER6, false},
		{NUMBER7, false},
		{NUMBER8, false},
		{NUMBER9, false},

		{LCTRL, false},
		{RCTRL, false},


		{UPARROW, false},
		{DOWNARROW, false},
		{RIGHTARROW, false},
		{LEFTARROW, false},

		{LALT, false},
		{RALT, false},

		{SPACE, false},

		{LSHIFT, false},
		{RSHIFT, false},



};


std::map<MouseButton, bool> GameEngine::mouseCurStates = {
		{LEFTMOUSE, false},
		{RIGHTMOUSE, false},

};

std::map<MouseButton, bool> GameEngine::mousePrevStates = {
		{LEFTMOUSE, false},
		{RIGHTMOUSE, false},

};

GameEngine::InputSystem GameEngine::InputSystem::inputInstance;

GameEngine::InputSystem::InputSystem() {

	inputInstance.windowRef = NULL;
	
}



void GameEngine::InputSystem::setUp(GLFWwindow* window) {
	inputInstance.windowRef = window;
}


void GameEngine::InputSystem::keyProcessInput() {
	std::map<KeyCode, bool>::iterator it;

	std::map<MouseButton, bool>::iterator mouseit;

	// array/list is ordered
	// map/dictionary is unordered

	// Copy values from CurrentStates to PrevStates
	for (it = GameEngine::prevStates.begin(); it != GameEngine::prevStates.end(); it++) {
		// Set the value of prevStates' item as the
		// value of currentStates' item
		it->second = GameEngine::currentStates[it->first];
	}

	// Then, poll glfwGetKey for all keys to get new CurrentState
	for (it = GameEngine::currentStates.begin(); it != GameEngine::currentStates.end(); it++) {
		// Get the state from GLFW for this key
		// and then set the value to this item
		it->second = glfwGetKey(inputInstance.windowRef, it->first);
	}

	
	
	

	// Copy values from CurrentStates to PrevStates
	for (mouseit = GameEngine::mousePrevStates.begin(); mouseit != GameEngine::mousePrevStates.end(); mouseit++) {
		// Set the value of prevStates' item as the
		// value of currentStates' item
		mouseit->second = GameEngine::mouseCurStates[mouseit->first];
	}

	// Then, poll glfwGetKey for all keys to get new CurrentState
	for (mouseit = GameEngine::mouseCurStates.begin(); mouseit != GameEngine::mouseCurStates.end(); mouseit++) {
		// Get the state from GLFW for this key
		// and then set the value to this item
		mouseit->second = glfwGetMouseButton(inputInstance.windowRef, mouseit->first);
	}

	
}

bool GameEngine::InputSystem::IsKeyDownThisFrame(KeyCode key) {
	bool prevValue = false;
	bool currentValue = false;

	std::map<KeyCode, bool>::iterator it = GameEngine::prevStates.find(key);
	if (it != GameEngine::prevStates.end()) {
		prevValue = GameEngine::prevStates[key];
	}
	it = GameEngine::currentStates.find(key);
	if (it != GameEngine::currentStates.end()) {
		currentValue = GameEngine::currentStates[key];
	}

	return !prevValue && currentValue;
};
bool GameEngine::InputSystem::IsKeyDown(KeyCode key) {
	//We did not check if we support the keycode
	bool result = false;
	//Safely check if we have the key supported
	std::map<KeyCode, bool>::iterator it = GameEngine::currentStates.find(key);

	//if not equal to the end mean that it have find the key
	if (it != GameEngine::currentStates.end()) {
		//result = it->second;
		result = GameEngine::currentStates[key];
	}

	return result;
}

bool GameEngine::InputSystem::IsKeyUpThisFrame(KeyCode key) {
	bool prevValue = false;
	bool currentValue = false;

	std::map<KeyCode, bool>::iterator it = GameEngine::prevStates.find(key);
	if (it != GameEngine::prevStates.end()) {
		prevValue = GameEngine::prevStates[key];
	}
	it = GameEngine::currentStates.find(key);
	if (it != GameEngine::currentStates.end()) {
		currentValue = GameEngine::currentStates[key];
	}

	return prevValue && !currentValue;
}


bool GameEngine::InputSystem::IsMouseDownThisFrame(MouseButton key) {
	bool prevValue = false;
	bool currentValue = false;

	std::map<MouseButton, bool>::iterator it = GameEngine::mousePrevStates.find(key);
	if (it != GameEngine::mousePrevStates.end()) {
		prevValue = GameEngine::mousePrevStates[key];
	}
	it = GameEngine::mouseCurStates.find(key);
	if (it != GameEngine::mouseCurStates.end()) {
		currentValue = GameEngine::mouseCurStates[key];
	}

	return !prevValue && currentValue;
}
bool GameEngine::InputSystem::IsMouseDown(MouseButton key) {
	//We did not check if we support the keycode
	bool result = false;
	//Safely check if we have the key supported
	std::map<MouseButton, bool>::iterator it = GameEngine::mouseCurStates.find(key);

	//if not equal to the end mean that it have find the key
	if (it != GameEngine::mouseCurStates.end()) {
		//result = it->second;
		result = GameEngine::mouseCurStates[key];
	}

	return result;
}
bool GameEngine::InputSystem::IsMouseUpThisFrame(MouseButton key) {
	bool prevValue = false;
	bool currentValue = false;

	std::map<MouseButton, bool>::iterator it = GameEngine::mousePrevStates.find(key);
	if (it != GameEngine::mousePrevStates.end()) {
		prevValue = GameEngine::mousePrevStates[key];
	}
	it = GameEngine::mouseCurStates.find(key);
	if (it != GameEngine::mouseCurStates.end()) {
		currentValue = GameEngine::mouseCurStates[key];
	}

	return prevValue && !currentValue;
}

void  GameEngine::InputSystem::getWindowSize(int width, int height) {
	windowHeight = height;
	windowWidth = width;
}

const double GameEngine::InputSystem::GetMousePosX() {
	double x,y;
	glfwGetCursorPos(inputInstance.windowRef, &x, &y);
	return x;
}

const double GameEngine::InputSystem::GetMousePosY() {
	double x, y;
	glfwGetCursorPos(inputInstance.windowRef, &x, &y);
	return windowHeight - y;
}



