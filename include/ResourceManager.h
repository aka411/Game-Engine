#pragma once


#include <string>
#include <fstream> 
#include <sstream>
#include <vector>

#include <iostream>
#include <map>








struct Image {

	int width, height, nrComponents;

	unsigned char* imageData;



};

struct Mesh {

	std::vector<float> vertices;
	std::vector<unsigned int> indices;

};



class ResourceManager
{

public:

	std::map<std::string, Mesh> meshList;
	std::map<std::string, const char*> textResourceList;
	std::map<std::string,Image > imageResourceList;
private:
	
	//ImageLoader* imageLoader;


public:
	

	


	void loadTextFromFile(const char* vertexPath, std::string name);

	void loadTextureFromFile(const char* FilePath, std::string name);

	void addIndexedMesh(std::vector<float> vertices, std::vector<unsigned int> indices, std::string name);

	

};

