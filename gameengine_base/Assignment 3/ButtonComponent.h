#include"BaseComponent.h"
#include "GameObject.h"
#include <stdio.h>
#include"InputSystem.h"
#include "Signal.h"
#include "Transform.h"
#include "Window.h"



namespace GameEngine {
	//! This documentation will briefing the usage of %ButtonComponent. %ButtonComponent is a class that provided to the engine user and can be use to make a button object
	class ButtonComponent : public GameEngine::BaseComponent
	{
	public:
		
		//! The constructor of %ButtonComponent
		ButtonComponent(GameObject* go);
		//! The Destructor of %ButtonComponent
		~ButtonComponent();
		
		//! This function can be used to drop the single Listener by using the id. The first Listener that added will be id = 0.
		/*!
		* Sample Usage:
		*\code{.cpp}
		* #include "GameObject.h"
		* #include "ButtonComponent.h"
		* using namespace GameEngine;
		*
		* //How the Test function should be
		* 
		* void Test(){
		  printf("Test \n");
		  }
		* 
		* int main(){
		* 
		* GameObject* obj = new GameObject("OBJ");
		* 
		* auto button = obj->addComponent<ButtonComponent>();
		* 
		* //Lets assume that have a Test function inside the button component class.
		* button->addListener(obj, &ButtonComponent::Test);
		* button->addListener(obj, &ButtonComponent::Test2);
		* 
		* //This will drop the Test function
		* button->dropListener(0);
		* 
		* //This will drop the Test2 function
		* button->dropListener(1);
		* 
		* return 0;
		* }
		* \endcode
		*
		*/
		void dropListener(int id);

		//! This function can be used to drop all the listener that had added.
		/*!
		* Sample Usage:
		*\code{.cpp}
		* #include "GameObject.h"
		* #include "ButtonComponent.h"
		* using namespace GameEngine;
		* 
		* //How the Test function should be
		* void Test(){
		  printf("Test \n");
		  }

		  void Test2(){
		  printf("Test2 \n");
		  }
		*
		* int main(){
		*
		* GameObject* obj = new GameObject("OBJ");
		*
		* auto button = obj->addComponent<ButtonComponent>();
		*
		* //Lets assume that have a Test function inside the button component class.
		* button->addListener(obj, &ButtonComponent::Test);
		* button->addListener(obj, &ButtonComponent::Test2);
		*
		* //drop all listener that attach to button component
		* button->dropAllListener();
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void dropAllListener();


		template <typename T, typename...Arg>

		//! This function can be used to add the Listener. The function can be added is a void function with 0 argument.
		/*!
		* Sample Usage:
		*\code{.cpp}
		* #include "GameObject.h"
		* #include "ButtonComponent.h"
		* using namespace GameEngine;
		* 
		* //How the Test function should be
		* void Test(){
		  printf("Test \n");
		  }

		* int main(){
		*
		* 
		* GameObject* obj = new GameObject("OBJ");
		* 
		* auto button = obj->addComponent<ButtonComponent>();
		* 
		* //Lets assume that have a Test function inside the button component class.
		* button->addListener(obj, &ButtonComponent::Test);
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void addListener(T* go, void(T::* func)(Arg...)) {
			signal.connect_member(go, func);

		};

		
		//! This update function is used to check the mouse input position and also the clicked behaviour every frame.
		void update(float deltaTime) override;
		
	private:
		void OnClick();
		GameEngine::Signal<> signal;
		

		
	};
}