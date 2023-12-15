#pragma once
#include "BaseComponent.h"
#include <glad/glad.h>
//#include "angle_util/vector.h"
//#include "angle_util/matrix.h"
//#include <glm/matrix.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


using namespace glm;

namespace GameEngine {
	//! This documentation will briefing the usage of %Transform. %Transform is a derived class that can use to determine the transform and move the object. 
	class Transform : public GameEngine::BaseComponent
	{
	
	public:
		//! The vector3 of position
		vec3 position;

		//! The vector3 of scaling
		vec3 scaling;

		//! The vector3 of rotation
		vec3 rotation;

		//! The rotationAngle of rotation. This attribute will be determined in the SimpleSpriteRenderer
		float rotationAngle;

		
		Transform(GameObject* go);
		//~Transform();

		//! USe this function to move the object
		void translate(float x, float y, float z);

		//! USe this function to rotate the object
		void rotate(float x, float y, float z);

		//! USe this function to scale the object
		void scale(float x, float y, float z);

		


	};
};

