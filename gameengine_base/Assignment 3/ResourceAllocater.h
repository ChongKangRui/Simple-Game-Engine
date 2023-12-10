#pragma once
#include <iostream>
#include <map>
#include "Texture.h"
#include <string>
#include <stb_image/stb_image.h>
#include <glad/glad.h>


namespace GameEngine {
	
	//! This documentation will briefing the usage of %ResourceAllocater. %ResourceAllocater is a class that manage the resource such as Texture.
	class ResourceAllocater
	{
	public:
		//! This function is used to load or create texture
		//! This function is already included in the SimpleSpriteRenderer loadTexture function. Therefore, use the loadTexture from SimpleSpriteRenderer to create texture.
		static Texture* LoadTexture(const std::string& path);

		//! This function is use to decrease the reference count of texture. If texture reference count equal zero, the resource will be remove.
		static void decreaseRefCount(Texture* texture);
		
	private:
		
		static std::map<std::string, Texture*> resourceMap;
	


	};
};

