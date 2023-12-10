#include "Window.h"
#include <iostream>





GameEngine::Window::~Window() {
    glfwDestroyWindow(window);

    
}
int GameEngine::Window::Initialize(int width, int height, std::string& title) {
    if (!glfwInit())
    {
        return 0;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    data.width = width;
    data.height = height;
    data.title = title;

    if (!window)
    {
        glfwTerminate();

        return 0;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    //Set user pointer aka custom data to be shared around
    glfwSetWindowUserPointer(window,&data);

    glfwSetWindowCloseCallback(window, [](GLFWwindow* w) {

        // Get back user pointer
        WindowData& dat = *(WindowData*)glfwGetWindowUserPointer(w);
        dat.callbackFn("close");
        });

    return 1;
}

void GameEngine::Window::SwapAndPoll(float deltaTime) {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GameEngine::Window::SetWindowEventCallBacks(const SimpleEventCallbackFn& callback) {
    data.callbackFn = callback;
}

void GameEngine::Window::setCurrentWindowSize(int width, int height) {
    data.width = width;
    data.height = height;
   
   
}

int GameEngine::Window::getWidth() {
    return data.width;
}

int GameEngine::Window::getHeight() {
    return data.height;
}