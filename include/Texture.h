#pragma once

#include <map>
#include <string>


class Texture
{

private:
	std::map<std::string, unsigned int> textureList;

public:
	void addTexture(unsigned char* data,int width, int height, int nrChannels,const char* name);
	unsigned int getTexture(const char* name);
};

