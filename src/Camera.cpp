#include "Camera.h"
#include <iostream>

void Camera::generateCamera(float angle,float nearPlane ,float farPlane,float aspectRatio)
{

	const float tanHalf = tan(angle/2);
	const float t = nearPlane * tanHalf;
	const float r = t * aspectRatio;

	

	const float B = -(2 * nearPlane * farPlane) / (farPlane - nearPlane);
	
	const float A = -(farPlane + nearPlane) / (farPlane - nearPlane);

	projectionMatrix(0, 0) = (nearPlane / r);


	projectionMatrix(1, 1) = (nearPlane / t);

	projectionMatrix(2, 2) = A;

	projectionMatrix(2, 3) = B;

	projectionMatrix(3, 2) = -1;

	projectionMatrix(3, 3) = 0;



}


void Camera::update()
{
	

	const quaternion qy=quaternion(orientAngle,vec(0,1,0));
	const quaternion qx= quaternion(upDownAngle, vec(1, 0, 0));
	  quaternion q = qy * qx;
	  q.normalize();
	viewMatrix = mat4(q);

	
	viewMatrix.transpose();
	mat4 m = viewMatrix;


   
	float x = -position.x, y = -position.y, z =- position.z;
	

	viewMatrix(0, 3) = m(0, 0) * x+m(0,1)*y+m(0,2)*z;

	viewMatrix(1, 3) = m(1, 0) * x + m(1, 1) * y + m(1, 2) * z;
 
	viewMatrix(2, 3)  = m(2, 0) * x + m(2, 1) * y + m(2, 2) * z;
		
	viewMatrix(3, 3) = 1;





	
}

void Camera::moveLeft()
{
	position = position - vec(0.1, 0, 0);
	update();

}

void Camera::moveRight()
{
	position = position + vec(0.1, 0, 0);
	update();
}

void Camera::rotateLeft()
{
	orientAngle += 0.05;
	update();
}

void Camera::rotateRight()
{
	orientAngle -= 0.05;
	update();
}

void Camera::rotateUp()
{
	upDownAngle += 0.05;
	update();
}

void Camera::rotateDown()
{
	upDownAngle -= 0.05;
	update();
}

void Camera::moveUp()
{
	position = position + vec(0, 0.1, 0);
	update();

}

void Camera::moveDown()
{
	position = position - vec(0, 0.1, 0);
	update();

}