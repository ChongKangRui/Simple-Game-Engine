#pragma once
#include "Scene.h";
#include "SceneStateMachine.h"
#include "InputSystem.h"
#include "GameObject.h"
#include "SimpleSpriteRenderer.h"

#include "ButtonComponent.h"
#include "GameObjectCollection.h"
#include "Transform.h"
#include "Application.h"


namespace Showcase {
	//! This documentation won't showcase the usage since this class purpose is for the showcase.
	//! %SplashScene is a class that derived from Scene. Therefore, those function that %SplashScene is using are mostly override function.
	class SplashScene : public GameEngine::Scene {
	public:
		void initialize() override;
		void dispose()override;

		void activate()override;
		void deactivate()override;

		const std::string getName();

		void nextScene();

		void update(float deltaTime) override;

		void render() override;

		void QuitGame();
	private:
		float durationInScene = 0.0f;
		bool switchScene;

		GameEngine::GameObject* BG;
		GameEngine::GameObject* Title;
		GameEngine::GameObject* StartButton;
		GameEngine::GameObject* Quit;
		GameEngine::GameObjectCollection objectCollection;


	};
}