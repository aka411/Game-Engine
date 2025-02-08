#include "InputHandler.h"
#include <iostream>

Command* InputHandler::handleInput()
{




	if (isPressed(GLFW_KEY_W)) return buttonW_; 
	if (isPressed(GLFW_KEY_A)) return buttonA_;
	if (isPressed(GLFW_KEY_S)) return buttonS_;
	if (isPressed(GLFW_KEY_D)) return buttonD_;


	if (isPressed(GLFW_KEY_Q)) return buttonQ_;
	if (isPressed(GLFW_KEY_E)) return buttonE_;

	if (isPressed(GLFW_KEY_UP)) return buttonUP_;
	if (isPressed(GLFW_KEY_DOWN)) return buttonDOWN_;
	if (isPressed(GLFW_KEY_RIGHT)) return buttonRIGHT_;
	if (isPressed(GLFW_KEY_LEFT)) return buttonLEFT_;




	// Nothing pressed, so do nothing.
	return NULL;



	
}

void InputHandler::setContext(GLFWwindow* windowContxt)
{
	window = windowContxt;

}

bool InputHandler::isPressed(int key)
{

	if (glfwGetKey(window, key) == GLFW_PRESS) {
		
		return true;
	}

	return false;
}

void Command::execute(GameObject& actor)
{

}

void MoveLeftCommand::execute(GameObject& actor)
{
	actor.moveLeft();
}

void MoveRightCommand::execute(GameObject& actor)
{
	actor.moveRight();
}

void MoveUpCommand::execute(GameObject& actor)
{
	actor.moveUp();
}

void MoveDownCommand::execute(GameObject& actor)
{
	actor.moveDown();

}

void RotateLeftCommand::execute(GameObject& actor)
{
	actor.rotateLeft();
}

void RotateRightCommand::execute(GameObject& actor)
{
	actor.rotateRight();

}

void RotateUpCommand::execute(GameObject& actor)
{
	actor.rotateUp();
}

void RotateDownCommand::execute(GameObject& actor)
{
	actor.rotateDown();
}
