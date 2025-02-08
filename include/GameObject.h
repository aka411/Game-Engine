#pragma once

#include "mathLib.h"


class GameObject
{
private:

	float invMass;

	vec position = vec(0, 0, 0);

	vec velocity;

	vec forceAccumulator;

private:



public:

	void setMass(float mass);

	void render();

	
	

	void setShader(const char* name);
	void setModel(const char* name);
	




	virtual void moveLeft();
	virtual void moveRight();

	virtual void moveDown();
	virtual void moveUp();

	virtual void rotateLeft();
	virtual void rotateRight();

	virtual void rotateUp();
	virtual void rotateDown();

	//virtual void render(ModelParameters* para);
};

