#include "LoseScene.h"
#include "ButtonComponent.h"
#include "SimpleSpriteRenderer.h"
#include "Application.h"

using namespace GameEngine;
using namespace Showcase;

void LoseScene::initialize() {
	//Initialize game object
	BG = new GameObject("BackGround");
	QuitButton = new GameObject("Quit");
	RetryButton = new GameObject("Retry");
	Title = new GameObject("Title");

	//get background image component
	auto BGsprite = BG->addComponent<SimpleSpriteRenderer>();
	auto BGTransform = BG->getComponent<Transform>();

	//get title component
	auto titleSprite = Title->addComponent<SimpleSpriteRenderer>();
	auto titleTransform = Title->getComponent<Transform>();

	//get quit component
	auto QuitSprite = QuitButton->addComponent<SimpleSpriteRenderer>();
	auto QuitBT = QuitButton->addComponent<ButtonComponent>();
	auto QuitTransform = QuitButton->getComponent<Transform>();

	//get retry component
	auto RetrySprite = RetryButton->addComponent<SimpleSpriteRenderer>();
	auto RetryBT = RetryButton->addComponent<ButtonComponent>();
	auto RetryTransform = RetryButton->getComponent<Transform>();

	//load each game object sprite
	BGsprite->loadTexture("../Asset/BG.png");
	titleSprite->loadTexture("../Asset/YouDie.png");
	QuitSprite->loadTexture("../Asset/Quit.png");
	RetrySprite->loadTexture("../Asset/retry.png");

	//set the size of each game object's sprite
	BGsprite->setTextureResize(800, 800);
	titleSprite->setTextureResize(600, 300);
	QuitSprite->setTextureResize(200, 100);
	RetrySprite->setTextureResize(200, 100);

	//set the position of each game object
	BGTransform->translate(400, 300, 0);
	titleTransform->translate(400, 400, 0);
	QuitTransform->translate(400, 100, 0);
	RetryTransform->translate(400, 200, 0);

	//Add Listener
	RetryBT->addListener(this, &LoseScene::SwitchToGameScene);
	QuitBT->addListener(this, &LoseScene::QuitGame);

	objectCollection.add(BG);
	objectCollection.add(QuitButton);
	objectCollection.add(RetryButton);
	objectCollection.add(Title);


};

void  LoseScene::dispose() {}

void  LoseScene::activate() {
	printf("LoseScene activated\n");
	/*glMatrixMode(GL_PROJECTION);
	glOrtho(0, 800, 0, 600, -0.1, 1000);
	glMatrixMode(GL_MODELVIEW);*/

};
void  LoseScene::deactivate() {
	printf("LoseScene deactivated\n");
}

const std::string LoseScene::getName() {
	return "LoseScene";
}

void LoseScene::update(float deltaTime) {

	objectCollection.update(deltaTime);
	if (!BG->shouldBeRemoved()) {
		BG->getComponent<SimpleSpriteRenderer>()->setTextureResize(WindowWidth + 200, WindowHeight + 200);
	}

}

void LoseScene::render() {
	objectCollection.render();
}

void LoseScene::QuitGame() {
	Application::Quit();
}

void LoseScene::SwitchToGameScene() {
	stateMachine->loadScene("GameScene");
}