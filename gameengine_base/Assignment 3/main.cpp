/*! \page Overview
* Game Engine Overview
* 
* \subsection Student Student Info
* 
* Student Name: Chong Kang Rui
* 
* Student Id: 0128391
* 
* Semester: Jan 2022
* 
* 
*/



#include <iostream>
#include "Application.h"


int main() {
	GameEngine::Application app;
	app.setFrameRate(60);

	
	if (!app.Initialize(800, 600)){
		
		return 0;
	}
	
	app.SetupEventCallbacks();
	app.Run();
	
}