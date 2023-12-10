#pragma once
#include "BaseComponent.h"
#include "InputSystem.h"
#include "GameObject.h"
#include "Transform.h"

namespace Showcase {
	//! This documentation won't showcase the usage since this class purpose is for the showcase.
	//! %ShipController is a class that derived from BaseComponent. Therefore, the update function that %BaseComponent is using are mostly override function.
	class ShipController : public GameEngine::BaseComponent
	{
		
	public:

		ShipController(GameEngine::GameObject* go);
		~ShipController();

		void getWindowSize(int width, int height);

		void update(float deltaTime) override;
		float speed;


	private:

		int windowWidth;
		int windowHeight;



		GameEngine::Transform* transform;
	};
}

