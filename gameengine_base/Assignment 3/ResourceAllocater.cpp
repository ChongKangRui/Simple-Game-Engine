#include "ResourceAllocater.h"


using namespace GameEngine;

std::map<std::string, Texture*> GameEngine::ResourceAllocater::resourceMap = {};

Texture* GameEngine::ResourceAllocater::LoadTexture(const std::string& path) {

	if (resourceMap.empty()) {

		Texture* texture = Texture::createTexture(path);
		

		resourceMap.insert(std::pair<std::string, Texture*>(path, texture));
		std::cout << "Resource Creared! " << std::endl;

		texture->refCount += 1;
		return texture;

	}
	else {
		std::map<std::string, Texture*>::iterator it = resourceMap.find(path);

		if (it == resourceMap.end()) {

			Texture* texture = Texture::createTexture(path);

			resourceMap.insert(std::pair<std::string, Texture*>(path, texture));

			texture->refCount += 1;

			std::cout << "Resource Creared! " << std::endl;

			return texture;
		}
		else {
			it->second->refCount += 1;

			std::cout << "Return Existing Resource: " << it->second->refCount << std::endl;
			return it->second;
		}
	}
}


void GameEngine::ResourceAllocater::decreaseRefCount(Texture* texture) {
	if (!resourceMap.empty()) {
		std::map<std::string, Texture*>::iterator it;

		
			for (it = resourceMap.begin(); it != resourceMap.end(); it++) {

				if (it->second == texture) {
					if (it->second->refCount != 0)
					{
						it->second->refCount -= 1;
						std::cout << "Reference Count Decreased: " << it->second->refCount << std::endl;
					}
					
					if (it->second->refCount == 0) {
						resourceMap.erase(it);
						std::cout << "Destroying the unused reference." << std::endl;

						break;
					}
					
				}
				
			}


	}
}