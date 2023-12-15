
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include "Application.h"
#include "InputSystem.h"
#include "SceneStateMachine.h"
#include "GameScene.h"
#include "SplashScene.h"
#include "LoseScene.h"
#include <iostream>

int currentWidth = 800;
int currentHeight = 600;

void onWindowResized(GLFWwindow* window, int width, int height)
{
	if (height == 0) height = 1;						// Prevent A Divide By Zero By making Height Equal One
	
	currentWidth = width;
	currentHeight = height;
	
	GameEngine::InputSystem::getWindowSize(currentWidth, currentHeight);

	//std::cout << currentHeight << " " << currentWidth << std::endl;

	glViewport(0, 0, width, height);					// Reset The Current Viewport

	float aspect = (float)width / (float)height;
	float fov = 60.0;
	float zNear = 0.1f;
	float zFar = 100.0f;
	mat4 projection = glm::perspective(fov, aspect, zNear, zFar);
	glMultMatrixf(&projection[0][0]);


	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	
	//avoid stretch
	glScalef(1.3f/aspect, 1, 0);
}

GameEngine::Application::Application() {
	printf("Application Created\n");
	
}
GameEngine::Application::~Application() {
	printf("Application End\n");
}

bool GameEngine::Application::Initialize(int width, int height) {

	std::string title = "Assignment 1";
	if (window.Initialize(width, height, title)) {
		isInitialized = true;
	}
	
	

	return isInitialized;
}



void GameEngine::Application::setFrameRate(int fr)
{
	if (fr > 0)
		frameTime = 1.0 / fr;
	else frameTime = 0;
}



void GameEngine::Application::Run() {
	if (!isInitialized) {
		printf("Call Initialize() first before run \n");
		return;
	}
	isRunning = true;

	glfwSetFramebufferSizeCallback(window.getWindow(), onWindowResized);
	glfwSetWindowSizeCallback(window.getWindow(), onWindowResized);

	glfwMakeContextCurrent(window.getWindow());

	onWindowResized(window.getWindow(), WINDOW_WIDTH, WINDOW_HEIGHT);

	
	
	

	unsigned long frameCount = 0;
	float previousTime = glfwGetTime();


#pragma region Scene Manager Initialization

	SceneStateMachine sceneManager;
	unsigned int splashId = 0;
	unsigned int gameSceneId = 1;
	unsigned int loseSceneId = 2;

	sceneManager.addScene<Showcase::SplashScene>(splashId);
	sceneManager.addScene<Showcase::GameScene>(gameSceneId);
	sceneManager.addScene<Showcase::LoseScene>(loseSceneId);
	sceneManager.loadScene("StartScene");
	//sceneManager.loadScene("LoseScene");
	/*GameScene Scene;
	Scene.activate();*/

#pragma endregion

	//v- sync
	while (isRunning)
	{

		float currentTime = glfwGetTime();

		deltaTime = currentTime - previousTime;
	
		GameEngine::InputSystem::keyProcessInput();
		

		//glfwSetWindowTitle(window, ss.c_str);

		while (deltaTime < frameTime) {
			currentTime = glfwGetTime();
			deltaTime = currentTime - previousTime;


		}


#pragma region Scene Manager Update & Render

		// SceneManager Update
		/*Scene.update(deltaTime);
		Scene.render();*/
		// SceneManager Render
		sceneManager.update(deltaTime);
		sceneManager.getWindowSize(currentWidth, currentHeight);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

		sceneManager.render();

#pragma endregion


		


		
		window.SwapAndPoll(deltaTime);
		
		++frameCount;
		
		//InputSystemSetUp();

		char str[64];
		sprintf_s(str, "Input Demo %f fps, dt: %f", 1.0 / deltaTime, deltaTime);
		glfwSetWindowTitle(window.getWindow(), str);

		window.setCurrentWindowSize(currentWidth, currentHeight);

		//std::cout << window.getWidth() << " " << window.getHeight() << std::endl;
		
		previousTime = currentTime;

		

		

	}




}


void GameEngine::Application::Quit() {
	exit(3);
}

void GameEngine::Application::SetupEventCallbacks() {
	if (!isInitialized) {
		printf("Call Initialize() first before setupeventcallback \n");
		return;
	}

	window.SetWindowEventCallBacks([this](std::string evt) {
		OnWindowEventFired(evt);
		});
	GameEngine::InputSystem::setUp(window.getWindow());
}

void GameEngine::Application::OnWindowEventFired(std::string& evt) {
	printf("%s", evt.c_str());
	if (evt == "close") {
		isRunning = false;
	}
}