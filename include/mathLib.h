#pragma once
#include <math.h>

/*

struct vec2i {

	int x;
	int y;

};






struct vec3i {

	int x;
	int y;
	int z;

};


*/


struct veci {

	int x;
	int y;
	int z;


	



	veci();

	veci(int a, int b, int c);

};

struct vec {

	float x;
	float y;
	float z;

	
	vec();

	vec(float a, float b, float c);

	void normalize();

	float sqrMag();

};

vec operator+(const vec& a, const vec& b);
vec operator-(const vec& a, const vec& b);
vec operator*(const float& a, const vec& b);
vec operator*(const vec& a, const vec& b);
vec operator*(const vec& b, const float& a);
vec operator+=( vec& a, const vec& b);

struct vec2 {

	float x;
	float y;


	vec2();

	vec2(float a, float b);
};



float dot(vec& a, vec& b);



struct quaternion {

	float s, x, y, z;


	

	void normalize();

	quaternion(float angle, vec axis);

	quaternion();
	quaternion(float s, float x, float y, float z);


}
;
quaternion operator*(const quaternion& a, const quaternion& b);


struct mat4 {



	float m[4][4];

	mat4();

	void setRow(const float in[4], int i);

	void transpose();


    mat4(const quaternion& q);
	mat4(const quaternion& q, vec& translate);

	
	mat4(const quaternion& q, float& scale);
	mat4(const quaternion& q, float& scale, vec& translate);

	float& operator()(int i,int j) {

		return m[i][j];
}


};
