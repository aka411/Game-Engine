#pragma once
#include "GameObject.h"
#include "ResourceManager.h"
#include "Camera.h"


/*struct RenderData {

	std::vector<vec>* vertex;
	std::vector<veci>* index;
	unsigned int shader;

};*/

class Renderer
{

public :
	ResourceManager* manager;
	//RenderData* renderData;
	ModelParameters *para;

	Model* model;
	unsigned int shader;

private:

	//void setRenderData();
	void getResource();
	void Draw();
	//void renderData();
public:
	Camera* camera;

	void setResourceManager(ResourceManager* resManager);
	
	void render(GameObject* obj);


};

