#include "Transform.h"
#include <glad/glad.h>
#include <iostream>

GameEngine::Transform::Transform(GameObject* go) : GameEngine::BaseComponent(go) {
	
}

void GameEngine::Transform::translate(float x, float y, float z) {
	position.x = x;
	position.y = y;
	position.z = z;
}


void GameEngine::Transform::rotate(float x, float y, float z) {
	//rotationAngle = angle;
	rotation = vec3(x,y,z);
	//rotation = glm::rotate
}

void GameEngine::Transform::scale(float x, float y, float z) {
	scaling.x = x;
	scaling.y = y;
	scaling.z = z;
}

