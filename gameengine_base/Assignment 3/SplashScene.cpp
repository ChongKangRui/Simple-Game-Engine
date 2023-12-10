#include "SplashScene.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>



using namespace GameEngine;
using namespace Showcase;

void SplashScene::initialize() {
	//Initialize game object
	BG = new GameObject("BackGround");
	StartButton = new GameObject("Button");
	Title = new GameObject("Title");
	Quit = new GameObject("Quit");

	//set switch scene to false
	switchScene = false;

	//get background image component
	auto sprite = BG->addComponent<SimpleSpriteRenderer>();
	auto BGTransform = BG->getComponent<Transform>();

	//get start button component
	auto BTSprite = StartButton->addComponent<SimpleSpriteRenderer>();
	auto BTTransform = StartButton->getComponent<Transform>();
	auto startButton = StartButton->addComponent<ButtonComponent>();

	//get title component
	auto titleSprite = Title->addComponent<SimpleSpriteRenderer>();
	auto titleTransform = Title->getComponent<Transform>();

	auto QuitSprite = Quit->addComponent<SimpleSpriteRenderer>();
	auto QuitTransform = Quit->getComponent<Transform>();
	auto QuitButton = Quit->addComponent<ButtonComponent>();

	//load each game object sprite
	BTSprite->loadTexture("../Asset/StartButton.png");
	sprite->loadTexture("../Asset/BG.png");
	titleSprite->loadTexture("../Asset/title.png");
	QuitSprite->loadTexture("../Asset/Quit.png");

	//set the size of each game object's sprite
	BTSprite->setTextureResize(200, 100);
	sprite->setTextureResize(800, 800);
	QuitSprite->setTextureResize(200, 100);

	//set the position of each game object
	BGTransform->translate(400, 300, 0);
	titleTransform->translate(400, 400, 0);
	BTTransform->translate(400, 200,0);
	QuitTransform->translate(400, 100, 0);
	
	//add listener to the button
	startButton->addListener(this, &SplashScene::nextScene);
	QuitButton->addListener(this, &SplashScene::QuitGame);

	objectCollection.add(BG);
	objectCollection.add(StartButton);
	objectCollection.add(Title);
	objectCollection.add(Quit);
}
void  SplashScene::dispose() {
	
}

void  SplashScene::activate() {
	printf("Start Scene activated\n");
	//glClearColor(100 / 255.f, 149 / 255.f, 237 / 255.f, 1.0f);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 800, 0, 600, -0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
}
void  SplashScene::deactivate() {
	printf("StartScene deactivated\n");
}

const std::string  SplashScene::getName() {
	return "StartScene";
}

void SplashScene::nextScene() {	
	switchScene = true;
}

void  SplashScene::update(float deltaTime)  {

	objectCollection.update(deltaTime);
	if (switchScene) {
		if (objectCollection.getCount() != 0) {
			objectCollection.clearAllObject();
		}
		else {
			stateMachine->loadScene("GameScene");
		}
	}
	if (!BG->shouldBeRemoved()) {
		BG->getComponent<SimpleSpriteRenderer>()->setTextureResize(WindowWidth + 200, WindowHeight + 200);
	}


}

void SplashScene::render() {
	objectCollection.render();
}

void  SplashScene::QuitGame() {
	Application::Quit();
}