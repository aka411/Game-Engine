#pragma once
#include "mathLib.h"
#include "GameObject.h"

class Camera:public GameObject
{

public :
	//vec position;
	quaternion orientation;
	mat4 projectionMatrix;
	mat4 viewMatrix;
	float orientAngle = 1.0472;
	float upDownAngle = 0;

	//void generateCamera(float angle,float farPlane);

	//void generateCamera(float angle, float nearPlane, float farPlane);

	void generateCamera(float angle, float nearPlane, float farPlane, float aspectRatio);

	void update();

	void moveLeft();
	void moveRight();

	void rotateLeft();

	void rotateRight();

	void rotateUp();
	void rotateDown();


	void moveUp();

	void moveDown();

};

