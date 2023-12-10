#pragma once
#include <string>

namespace GameEngine {
	//! This documentation will briefing the usage of %Texture. %Texture is a class that can use to create and load texture.
	
	class Texture
	{
	public:

		//! The width and height can get from SimpleSpriteRenderer function.
		int width, height;

		//! Use to load texture
		unsigned int textureId;

		//! The reference of object that are using this texture
		//! If reference count is 0, this texture will be remove to save source
		unsigned int refCount;

		//! This function is used to create texture. It have been put inside the ResourceAllocater LoadTexture function. Therefore, dont use this one to create texture because it will waster the resource.
		static Texture* createTexture(const std::string& path);

		//! decrease the reference count of current texture.
		void decreasedRefCount();


	};
}


