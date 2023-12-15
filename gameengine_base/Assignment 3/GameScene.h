#pragma once
#include "Scene.h";
#include "InputSystem.h";
#include "GameObjectCollection.h"

#include "GameObject.h"


#include "Transform.h"
#include "SceneStateMachine.h"

#include "ShipController.h"

namespace Showcase {
	//! This documentation won't showcase the usage since this class purpose is for the showcase.
	//! %GameScene is a class that derived from Scene. Therefore, those function that %GameScene is using are mostly override function.
	class GameScene : public GameEngine::Scene {
	public:

		void initialize() override;
		void dispose()override;

		void activate()override;
		void deactivate()override;

		const std::string getName();


		void update(float deltaTime) override;

		void render() override;



	private:

		GameEngine::GameObject* BG;
		GameEngine::GameObject* Ship;
		
		float spawnDuration = 2.0f;
		float switchSceneDuration;

		std::vector<GameEngine::GameObject*>* meteoriteCollector;
		

		GameEngine::GameObjectCollection objectCollection;

		Showcase::ShipController* shipController;
		
		float bulletShootCD = 0.2f;
		float currentShootCD = 0.0f;

		bool CanShoot = true;
	};
}
