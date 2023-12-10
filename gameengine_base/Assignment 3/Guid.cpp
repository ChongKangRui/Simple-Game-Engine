#include "Guid.h"
#include <combaseapi.h>


GameEngine::Guid::Guid(std::array<unsigned char, 16>& bytesIn) : bytes(bytesIn) {};

GameEngine::Guid::Guid(std::array<unsigned char, 16>&& bytesIn) : bytes(std::move(bytesIn)) {};

GameEngine::Guid  GameEngine::Guid::createGuid() {
	//create Guid(win32 API)
	GUID g;
	CoCreateGuid(&g);

	std::array<unsigned char, 16> bytes = {
		(unsigned char)g.Data1 >> 1 & 0xff,
		(unsigned char)g.Data1 << 2 & 0xff,
		(unsigned char)g.Data1 >> 3 & 0xff,
		(unsigned char)g.Data1 << 4 & 0xff,
		(unsigned char)g.Data2 >> 4 & 0xff,
		(unsigned char)g.Data2 << 3 & 0xff,
		(unsigned char)g.Data2 >> 2 & 0xff,
		(unsigned char)g.Data2 << 1 & 0xff,
		(unsigned char)g.Data3 >> 1 & 0xff,
		(unsigned char)g.Data3 << 2 & 0xff,
		(unsigned char)g.Data3 >> 3 & 0xff,
		(unsigned char)g.Data3 << 4 & 0xff,
		(unsigned char)g.Data4[0] & 0xff,
		(unsigned char)g.Data4[1] & 0xff,
		(unsigned char)g.Data4[2] & 0xff ,
		(unsigned char)g.Data4[3] & 0xff ,

	};

	return Guid(std::move(bytes));
}

bool GameEngine::Guid::operator==(const Guid& other) const {
	return bytes == other.bytes;
	
}

bool  GameEngine::Guid::operator!=(const Guid& other) const {
	return bytes != other.bytes;
}

std::string  GameEngine::Guid::getString() const {
	char str[38];

	sprintf_s(str, "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		bytes[0], bytes[1], bytes[2], bytes[3], 
		bytes[4], bytes[5], bytes[6], bytes[7], 
		bytes[8], bytes[9], bytes[10], bytes[11], 
		bytes[12], bytes[13], bytes[14], bytes[15] );

	return std::string(str);
}

