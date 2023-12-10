#include <glad/glad.h>
#include "Transform.h"
#include "SimpleSpriteRenderer.h"

#define pi 3.14159265359

GameEngine::SimpleSpriteRenderer::SimpleSpriteRenderer(GameObject* go) : GameEngine::BaseComponent(go) {
	setColor(1.0, 1.0, 1.0, 1.0);

	transform = go->getComponent<Transform>();
	

	pivot = vec3(0,0,0);
	pivotRotate = vec3(0, 0, 0);

};
GameEngine::SimpleSpriteRenderer::~SimpleSpriteRenderer() {
		ResourceAllocater::decreaseRefCount(texture);
};

const float GameEngine::SimpleSpriteRenderer::getHeight() {
	return height;
}

const float GameEngine::SimpleSpriteRenderer::getWidth() {
	return width;
}

void GameEngine::SimpleSpriteRenderer::loadTexture(const std::string& path) {
	//texture = Texture::createTexture(path);
	texture = ResourceAllocater::LoadTexture(path);

	width = texture->width;
	height = texture->height;
}

void GameEngine::SimpleSpriteRenderer::setTextureResize(float width, float height) {
	if (texture) {
		this->width = width;
		this->height = height;

	}


}


void GameEngine::SimpleSpriteRenderer::setColor(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
	
	//render();
}

void  GameEngine::SimpleSpriteRenderer::setPivot(float x, float y, float z) {
	pivot = vec3(x, y, z);
}

void GameEngine::SimpleSpriteRenderer::setRotation(float x, float y, float z) {
	
	if (pivotPos == transform->position) {
		rotateDirection = vec3(0, 0, 0);
		if (currentRotation.x != x) {

			rotateAngle = x;
			currentRotation.x = x;
			rotateDirection.x = 1;
		}
		if (currentRotation.y != y) {

			rotateAngle = y;
			currentRotation.y = y;
			rotateDirection.y = 1;
		}
		if (currentRotation.z != z) {
			rotateAngle = z;
			currentRotation.z = z;
			rotateDirection.z = 1;
		}

		pivotRotate = vec3(0, 0, 0);

		
	}
	else {

		float angle = 360 * (pi / 180) + z;
		
		//float angleZ = 360 * (pi / 180) + z;


		pivotRotate.x = (pivotPos.x) * cosf(angle);
		pivotRotate.y = (pivotPos.y) * sinf(angle); 

		rotateDirection = vec3(0, 0, 0);
		if (currentRotation.z != z + (pivotPos.x)) {
		
			currentRotation.z = z;
			rotateAngle = z ;
			rotateDirection.z = 1;
		}
		

		//std::cout << rotateAngle <<" " << angle << std::endl;
	}

}



void GameEngine::SimpleSpriteRenderer::render() {
	if (texture) {
		glPushMatrix();

		pivotPos = transform->position + pivot;


		//std::cout << pivotPos.x << " " << transform->position.x << std::endl;

		setRotation(transform->rotation.x, transform->rotation.y, transform->rotation.z);
		
		glTranslatef(transform->position.x + pivotRotate.x, transform->position.y + pivotRotate.y, transform->position.z + pivotRotate.z);
		glRotatef(rotateAngle, rotateDirection.x, rotateDirection.y, rotateDirection.z);
		glScalef(transform->scaling.x, transform->scaling.y, transform->scaling.z);
		//we want to support transparency

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture->textureId);
		glColor4f(r, g, b, a);
		
		float halfw = width / 2.0f;
		float halfh = height / 2.0f;

		glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex2f(-halfw,halfh);
		glTexCoord2f(0, 0); glVertex2f(-halfw, -halfh);
		glTexCoord2f(1, 0); glVertex2f(halfw, -halfh);
		glTexCoord2f(1, 1); glVertex2f(halfw, halfh);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, 0);

		

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);

		glPopMatrix();
	}
}