#pragma once
#include <map>
#include <string>
#include <glad/glad.h>

#include <iostream>

class Shader
{

private:
	std::map<std::string, unsigned int > shaderList;
	



public:
	void addShader(const char* vertexShaderSource, const char* fragmentShaderSource, std::string name);
	unsigned int getShader(std::string name);
	
};

