#pragma once

#include "ResourceManager.h"//glfw includes opengl header which conflicts with glad as glad already includes it
#include <GLFW/glfw3.h>
#include "math.h"
#include <iostream>

#include "Renderer.h"
#include "Sphere.h"


void runEngine(GLFWwindow* window);
void processInput(GLFWwindow* window);