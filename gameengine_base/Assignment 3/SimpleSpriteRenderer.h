#include "BaseComponent.h"
#include "GameObject.h"
#include "Texture.h"
#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ResourceAllocater.h"

namespace  GameEngine {
	//! This documentation will briefing the usage of %SimpleSpriteRenderer. %SimpleSpriteRenderer is a derived class that can use to create sprite and texture.
	class SimpleSpriteRenderer : public GameEngine::BaseComponent
	{
	
	public:

		SimpleSpriteRenderer(GameEngine::GameObject* go);
		~SimpleSpriteRenderer();

		//! set the color of sprite
		void setColor(float r, float g, float b, float a);

		//! load or create texture from the path
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "GameObject.h"
		*#include "GameObjectCollection.h"
		*#include "SimpleSpriteRenderer.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* //create a game object and give it a name
		* GameObject* obj = new GameObject("OBJ");
		*
		* GameObjectCollection* collection = new GameObjectCollection();
		*
		* 
		* auto sprite = obj->addComponent<SimpleSpriteRenderer>();
		* 
		* sprite->loadTexture("../Asset/Paths.png");
		*
		* collection.add(obj);
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		void loadTexture(const std::string& path);

		//! This override function is used to render the texture
		void render() override;

		//! Get the sprite width
		const float getWidth();

		//! Get the sprite height
		const float getHeight();

		//! Resize the texture width and height
		void setTextureResize(float width, float height);

		//! set sprite pivot
		void setPivot(float x, float y, float z);

		//! Color R
		float r ;
		//! Color G
		float g ;
		//! Color B
		float b ;
		//! Color A
		float a ;



		

	private:

		float width, height;
		GameEngine::Texture* texture;
		Transform* transform;
		vec3 currentRotation = vec3(0,0,0);

		//use this to set the pivot pos from original sprite
		//it will be vec3(0,0,0);
		vec3 pivot;

		//use this to set the actual pivot position 
		vec3 pivotPos;

		//use this to set the actual pivot rotation
		vec3 pivotRotate;

		vec3 rotateDirection = vec3(0, 0, 0);

		float rotateAngle;

		void setRotation(float x, float y, float z);
	};
};

