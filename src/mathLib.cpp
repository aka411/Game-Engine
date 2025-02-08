#include "mathLib.h"




#pragma once









vec::vec() {

	x = 0;
	y = 0;
	z = 0;


}

vec::vec(float a, float b, float c) {

	x = a;
	y = b;
	z = c;

}





     vec operator+(const vec& a, const vec& b) {

		return vec(a.x + b.x, a.y + b.y, a.z + b.z);
	}



	vec operator-(const vec& a, const vec& b) {

		return vec(a.x - b.x, a.y - b.y, a.z - b.z);

	}

    vec operator*(const float& a, const vec& b) {

		return vec(a * b.x, a * b.y, a * b.z);

	}


	vec operator*(const vec& b, const float& a) {

		return vec(a * b.x, a * b.y, a * b.z);

	}

	vec operator*(const vec& a, const vec& b) {

		return vec(a.y * b.z - +a.z * b.y, a.x * b.z - a.z * b.x, a.x * b.y - a.y * b.x);

	}


	vec operator+=( vec& a, const vec& b) {


		a.x = a.x+b.x;
		a.y = a.y + b.y;
		a.z = a.z + b.z;

	}

float dot(vec& a, vec& b) {

	return a.x * b.x + a.y * b.y + a.z * b.z;

}

void vec::normalize() {

	const float rootmag = sqrt(x*x+y*y+z*z);
	x = x / rootmag;
	y = y / rootmag;
	z = z / rootmag;
}



float vec::sqrMag() {


	return x*x+y*y+z*z;

}



veci::veci() {

	x = 0;
	y = 0;
	z = 0;


}

veci::veci(int a, int b, int c) {

	x = a;
	y = b;
	z = c;

}

vec2::vec2()
{


}

vec2::vec2(float a, float b)
{
	x = a;
	y = b;

}

void quaternion::normalize() {

	const float mag = sqrt(s * s+x*x+y*y+z*z);

	s = s / mag;
	x = x / mag;
	y = y / mag;
	z = z / mag;


}

quaternion::quaternion(float angle,vec axis) {

	const float sinHalf=sin(angle/2.0), cosHalf = cos(angle/2.0);
	axis.normalize();
	s = cosHalf;
	x = sinHalf * axis.x;
	y = sinHalf * axis.y;
	z = sinHalf * axis.z;
}

quaternion::quaternion()
{
	s = 0;
	x = 0;
	y = 0;
	z = 0;

}

quaternion::quaternion(float scalar, float i, float j, float k)
{

	s = scalar;
	x = i;
	y = j;
	z = k;

}

quaternion operator+(const quaternion& a, const quaternion& b) {

	return quaternion(a.s+b.s,a.x + b.x, a.y + b.y, a.z + b.z);
}


quaternion operator-(const quaternion& a, const quaternion& b) {

	return quaternion(a.s - b.s, a.x - b.x, a.y - b.y, a.z - b.z);
}


 quaternion operator*(const quaternion& a, const quaternion& b) {





	const float scalar =(a.s*b.s)-(a.x*b.x)-(a.y*b.y)-(a.z*b.z) ;
	const float i = (a.s*b.x)+(a.x*b.s)+(a.y*b.z)-(a.z*b.y);
	const float j =(a.s*b.y) -(a.x*b.z)+(a.y*b.s)+(a.z*b.x);
	const float k = (a.s*b.z)+(a.x*b.y)-(a.y*b.x)+(a.z*b.s);

	return quaternion(scalar,i,j,k);
}

quaternion operator*(const float& scalar, const quaternion& a)
{

	return quaternion(scalar * a.s, scalar * a.x, scalar * a.y, scalar * a.z);


}

mat4::mat4()
{
	for (int i = 0; i <4 ; i++) {
	
		for (int j = 0; j < 4; j++) {

			m[i][j] = 0;
		}

	}
	m[3][3] = 1;
}


void mat4::setRow(const float in[4], int i) {

	m[i][0] = in[0];
	m[i][1] = in[1];
	m[i][2] = in[2];
	m[i][3] = in[3];
}





void mat4::transpose()
{mat4 n;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			//const float temp = m[i][j];
			

			//m[i][j] = m[j][i];

			//m[j][i] = temp;

			n.m[j][i] = m[i][j];


		}


	}


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			//const float temp = m[i][j];


			//m[i][j] = m[j][i];

			//m[j][i] = temp;

			m[i][j] = n.m[i][j];


		}
	}

	
}

mat4::mat4(const quaternion& q)
{

	const float s = q.s, x = q.x, y = q.y, z = q.z;

	/*const float row1[4] = {(1 - 2 * y * y - 2 * z * z), 2 * x * y - 2 * s * z, 2 * x * z + 2 * s * y,0};
	const float row2[4] = { 2 * x * y + 2 * s * z ,  (1 - 2 * x * x - 2 * z * z), 2 * y * z - 2 * s * x , 0 };
	const float row3[4] = { 2 * x * z - 2 * s * y, 2 * y * z + 2 * s * x, (1 - 2 * x * x - 2 * y * y), 0 };
	const float row4[4] = { 0, 0 ,0  ,1 };*/




	const float row1[4] = { (1 - 2 * y * y - 2 * z * z), 2 * x * y - 2 * s * z, 2 * x * z + 2 * s * y,0 };
	const float row2[4] = { 2 * x * y + 2 * s * z ,  (1 - 2 * x * x - 2 * z * z), 2 * y * z - 2 * s * x , 0 };
	const float row3[4] = { 2 * x * z - 2 * s * y, 2 * y * z + 2 * s * x, (1 - 2 * x * x - 2 * y * y), 0 };
	const float row4[4] = { 0, 0 ,0  ,1 };


	setRow(row1, 0);
	setRow(row2, 1);
	setRow(row3, 2);
	setRow(row4, 3);

}

mat4::mat4(const quaternion& q, vec& translate)
{
	const float s = q.s, x = q.x, y = q.y, z = q.z;

	const float row1[4] = {  (1 - 2 * y * y - 2 * z * z), 2 * x * y - 2 * s * z, 2 * x * z + 2 * s * y,translate.x };
	const float row2[4] = { 2 * x * y + 2 * s * z , (1 - 2 * x * x - 2 * z * z), 2 * y * z - 2 * s * x , translate.y };
	const float row3[4] = { 2 * x * z - 2 * s * y, 2 * y * z + 2 * s * x,(1 - 2 * x * x - 2 * y * y), translate.z };
	const float row4[4] = { 0, 0 ,0  ,1 };


	setRow(row1, 0);
	setRow(row2, 1);
	setRow(row3, 2);
	setRow(row4, 3);


}

mat4::mat4(const quaternion& q, float& scale)
{
	const float s = q.s, x = q.x, y = q.y, z = q.z;

	const float row1[4] = { scale * (1-2*y*y-2*z*z), 2*x*y - 2*s*z, 2*x*z + 2*s*y,0 };
	const float row2[4] = { 2*x*y + 2*s*z , scale * (1 - 2*x*x - 2*z*z), 2*y*z - 2*s*x , 0};
	const float row3[4] = { 2*x*z - 2*s*y, 2*y*z + 2*s*x,scale* (1 - 2*x*x - 2*y*y), 0};
	const float row4[4] = {0, 0 ,0  ,1};
	

	setRow(row1, 0 );
	setRow(row2, 1);
	setRow(row3, 2);
	setRow(row4, 3);
}

mat4::mat4(const quaternion& q, float& scale, vec& translate)
{

	const float s = q.s, x = q.x, y = q.y, z = q.z;

	const float row1[4] = { scale * (1 - 2 * y * y - 2 * z * z), 2 * x * y - 2 * s * z, 2 * x * z + 2 * s * y,translate.x };
	const float row2[4] = { 2 * x * y + 2 * s * z , scale * (1 - 2 * x * x - 2 * z * z), 2 * y * z - 2 * s * x , translate.y };
	const float row3[4] = { 2 * x * z - 2 * s * y, 2 * y * z + 2 * s * x,scale * (1 - 2 * x * x - 2 * y * y), translate.z };
	const float row4[4] = { 0, 0 ,0  ,1 };


	setRow(row1, 0);
	setRow(row2, 1);
	setRow(row3, 2);
	setRow(row4, 3);

}

