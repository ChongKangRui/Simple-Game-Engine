#pragma once
#include <array>
#include <string>

namespace GameEngine {
	//! This documentation will briefing the usage of %Guid. %Guid is a class that can use to generate a unique GUID.
	class Guid
	{
	public:
		
		Guid(std::array<unsigned char, 16>& bytes);
		// we want to use std::move to move array
		//contents to a different std::array
		Guid(std::array<unsigned char, 16>&& bytes);

		//! To create the GUID, we will mainly use this static function to create a GUID
		/*!
		* Sample Usage:
		*\code{.cpp}
		*#include "Guid.h"
		*using namespace GameEngine;
		*
		*
		*
		*int main(){
		*
		* auto guid = Guid::createGuid();
		* printf("%s \n", guid.getString());
		*
		* return 0;
		* }
		* \endcode
		*
		*/
		static Guid createGuid();

		bool operator==(const Guid& other) const;
		bool operator!=(const Guid& other) const;

		//! Get the guid as string.
		std::string getString() const;

	private:
		std::array<unsigned char, 16> bytes;
	};
};

