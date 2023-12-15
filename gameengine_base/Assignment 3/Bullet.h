#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include <vector>

namespace Showcase {
	//! This documentation won't showcase the usage since this class purpose is for the showcase.
	//! %Bullet is a class that derived from BaseComponent. Therefore, thw upadte function that %Bullet is using are mostly override function.
	class Bullet : public GameEngine::BaseComponent
	{
	public:
		Bullet(GameEngine::GameObject* go);
		~Bullet();

		void update(float deltaTime) override;

		void getCurrentWindowSize(int width, int height);
		
		void SetMetroRef(std::vector<GameEngine::GameObject*>* metroCollection);

	private:
		GameEngine::Transform* transform;
		float OriginalPosY;
		

		int windowWidth;
		int windowHeight;

		std::vector<GameEngine::GameObject*>* Metro;



		float speed = 10.0f;
	};
}

