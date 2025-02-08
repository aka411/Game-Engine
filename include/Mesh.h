#pragma once
#include <vector>
#include "mathLib.h"
#include <string>



struct Vertex {

	vec Position;
	vec Normal;
	vec Tangent;
	vec Bitangent;
	vec2 TexCoords;
};



struct Texture {

	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh
{
private:
	unsigned int VBO, EBO;

private:


	void setupMesh();

	

public:

	unsigned int VAO;

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	


};

