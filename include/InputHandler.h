#pragma once
#include "GameObject.h"
#include <GLFW/glfw3.h>

class Command {

public :

	virtual void execute(GameObject& actor);



};




class MoveLeftCommand:public Command {


public:
	virtual void execute(GameObject& actor);

};

class MoveRightCommand :public Command {


public:
	virtual void execute(GameObject& actor);

};

class MoveUpCommand :public Command {


public:
	virtual void execute(GameObject& actor);

};

class MoveDownCommand :public Command {


public:
	virtual void execute(GameObject& actor);

};

class RotateLeftCommand :public Command {


public:
	virtual void execute(GameObject& actor);

};

class RotateRightCommand :public Command {


public:
	virtual void execute(GameObject& actor);

};

class RotateUpCommand :public Command {


public:
	virtual void execute(GameObject& actor);

};

class RotateDownCommand :public Command {


public:
	virtual void execute(GameObject& actor);

};


class InputHandler
{

private:
	MoveLeftCommand left;
	MoveRightCommand right;

	RotateLeftCommand rotLeft;
	RotateRightCommand rotRight;


	MoveUpCommand up;
	MoveDownCommand down;


	RotateUpCommand rotUp;
	RotateDownCommand rotDown;

private:
	Command* buttonW_=&up;
	Command* buttonA_=&left;
	Command* buttonS_=&down;
	Command* buttonD_=&right;

	Command* buttonUP_=&rotUp;
	Command* buttonDOWN_=&rotDown;
	Command* buttonRIGHT_;
	Command* buttonLEFT_;

	Command* buttonQ_=&rotLeft;
	Command* buttonE_=&rotRight;

private:
	GLFWwindow* window;
public:
	Command* handleInput();
	void setContext(GLFWwindow* windowContxt);

	
private :
	
	bool isPressed(int key);
	

};

