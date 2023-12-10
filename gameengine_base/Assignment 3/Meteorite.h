#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Transform.h"

namespace Showcase {
	//! This documentation won't showcase the usage since this class purpose is for the showcase.
	//! %Meteorite is a class that derived from BaseComponent. Therefore, thw upadte function that %Meteorite is using are mostly override function.
	class Meteorite : public GameEngine::BaseComponent
	{
	public:
		Meteorite(GameEngine::GameObject* go);
		~Meteorite();

		void update(float deltaTime) override;

		void getCurrentWindowSize(int width, int height);
		void getPlayer(GameEngine::GameObject* player);

		

	private:
		GameEngine::Transform* transform;
		GameEngine::GameObject* playerobj;

		

		int windowWidth;
		int windowHeight;



		float speed;
	};
}

