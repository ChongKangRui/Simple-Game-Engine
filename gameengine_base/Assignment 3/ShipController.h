#pragma once
#include "BaseComponent.h"
#include "InputSystem.h"
#include "GameObject.h"
#include "Transform.h"
#include <vector>
#include "Bullet.h"

#include "GameObjectCollection.h"

class Meteorite;

namespace Showcase {
	//! This documentation won't showcase the usage since this class purpose is for the showcase.
	//! %ShipController is a class that derived from BaseComponent. Therefore, the update function that %BaseComponent is using are mostly override function.
	class ShipController : public GameEngine::BaseComponent
	{
		
	public:

		ShipController(GameEngine::GameObject* go);
		~ShipController();

		void SetOC(GameEngine::GameObjectCollection objc);

		void getWindowSize(int width, int height);

		void update(float deltaTime) override;
		float speed;

		void AddMetro(GameEngine::GameObject* m);

		
		GameEngine::GameObject* SpawnBullet();

	private:

		int windowWidth;
		int windowHeight;

		GameEngine::GameObjectCollection objectCollection;
		GameEngine::Transform* transform;

		float shootspeed = 1;
		float shootduration = 0;

		bool CanSpawnBullet = true;


	};
}

