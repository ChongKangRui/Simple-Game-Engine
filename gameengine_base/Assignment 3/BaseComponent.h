#pragma once
//GameObject holds components
//Components has gameobject as owner;
//This results in circular dependency
//To solve , we forward declare that game object class exists
#include <string>




namespace GameEngine {
	
	class GameObject;

	//! This documentation will briefing the usage of %BaseComponent. %BaseComponent is a base class that can inherited/derived from other class to create a component(such as ButtonComponent, Transform, SpriteRenderer and etc)
	class BaseComponent {
		
	public:

		//%BaseComponent Constructor will need an object which represent the owner
		/*!
		* Sample Usage:
		*\code{.cpp}
		* //in .h
		* #include "BaseComponent.h"
		* using namespace GameEngine;
		* 
		* //derived class example
		* class ButtonComponent : public GameEngine::BaseComponent{
		* 
		*}
		* 
		* 
		* //in .cpp
		*
		* using namespace GameEngine;
		*
		* ButtonComponent::ButtonComponent(GameObject* go) : BaseComponent(go) {
		*
		*}
		*
		* \endcode
		*
		*/
		BaseComponent(GameObject* go);

		//%BaseComponent Destructor that can be override
		virtual ~BaseComponent();

		//! Awake can be override by the derived class and trigger in GameObject class.
		virtual void awake();

		//! Start can be override by the derived class and trigger in GameObject class.
		virtual void start();

		//! update can be override by the derived class and trigger in GameObject class.
		virtual void update(float deltaTime);

		//! Render can be override by the derived class and trigger in GameObject class.
		virtual void render();

		//! OnEnable can be override by the derived class and trigger in GameObject class.
		virtual void OnEnable();

		//! OnDisable can be override by the derived class and trigger in GameObject class.
		virtual void OnDisable();

	protected:
		GameObject* owner;
	};
};