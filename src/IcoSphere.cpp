#include "IcoSphere.h"
#include <map>
#include <iostream>


/*
vertex[0] = { -1, t, 0 };
vertex[1] = { 1, t, 0 };
vertex[2] = { -1, -t, 0 };
vertex[3] = { 1, -t, 0 };

vertex[4] = { 0, -1, t };
vertex[5] = { 0, 1, t };
vertex[6] = { 0, -1, -t };
vertex[7] = { 0, 1, -t };

vertex[8] = { t, 0, -1 };
vertex[9] = { t, 0, 1 };
vertex[10] = { -t, 0, -1 };
vertex[11] = { -t, 0, 1 };




indices[0] = { 0, 11, 5 };
indices[1] = { 0, 5, 1 };
indices[2] = { 0, 1, 7 };
indices[3] = { 0, 7, 10 };
indices[4] = { 0, 10, 11 };

// 5 adjacent faces
indices[5] = { 1, 5, 9 };
indices[6] = { 5, 11, 4 };
indices[7] = { 11, 10, 2 };
indices[8] = { 10, 7, 6 };
indices[9] = { 7, 1, 8 };

// 5 faces around point 3
indices[10] = { 3, 9, 4 };
indices[11] = { 3, 4, 2 };
indices[12] = { 3, 2, 6 };
indices[13] = { 3, 6, 8 };
indices[14] = { 3, 8, 9 };

// 5 adjacent faces
indices[15] = { 4, 9, 5 };
indices[16] = { 2, 4, 11 };
indices[17] = { 6, 2, 10 };
indices[18] = { 8, 6, 7 };
indices[19] = { 9, 8, 1 };


*/


void IcoSphere::generate(float radius,int recursionLevel,MeshData* data ) {


	std::vector<vec> vertex;
	std::vector<veci> indices;

	float t = (1.0 + std::sqrt(5.0)) / 2.0;


	vertex.push_back(vec(-1, t, 0));

	vertex.push_back(vec(1, t, 0));
	vertex.push_back(vec(-1, -t, 0));
	vertex.push_back(vec(1, -t, 0));

	vertex.push_back(vec(0, -1, t));
	vertex.push_back(vec(0, 1, t));
	vertex.push_back(vec(0, -1, -t));
	vertex.push_back(vec(0, 1, -t));

	vertex.push_back(vec(t, 0, -1));
	vertex.push_back(vec(t, 0, 1));
	vertex.push_back(vec(-t, 0, -1));
	vertex.push_back(vec(-t, 0, 1));




	indices.push_back(veci(0, 11, 5));
	indices.push_back(veci(0, 5, 1));
	indices.push_back(veci(0, 1, 7));
	indices.push_back(veci(0, 7, 10));
	indices.push_back(veci(0, 10, 11));

	// 5 adjacent faces
	indices.push_back(veci(1, 5, 9));
	indices.push_back(veci(5, 11, 4));
	indices.push_back(veci(11, 10, 2));
	indices.push_back(veci(10, 7, 6));
	indices.push_back(veci(7, 1, 8));

	// 5 faces around point 3
	indices.push_back(veci(3, 9, 4));
	indices.push_back(veci(3, 4, 2));
	indices.push_back(veci(3, 2, 6));
	indices.push_back(veci(3, 6, 8));
	indices.push_back(veci(3, 8, 9));

	// 5 adjacent faces
	indices.push_back(veci(4, 9, 5));
	indices.push_back(veci(2, 4, 11));
	indices.push_back(veci(6, 2, 10));
	indices.push_back(veci(8, 6, 7));
	indices.push_back(veci(9, 8, 1));
























	for (int i = 0; i < recursionLevel;i++){

	std::map<long long int, int> dict;

	//1)Take a triangle (indice vector) T 
	//2)Find midpoints of 3 edges of triangle T,let it be a ,b ,c
	//3)create new triangle using 1 vertex of triangle T and two midpoints from a,b,c
	//4)Repeat step 3 for all vertices of triangle T


	const int total_tri_count= indices.size();
	
	for (int tri_count = 0; tri_count < total_tri_count; tri_count++) {

		const int I1 = indices[tri_count].x;
		const int I2 = indices[tri_count].y;
		const int I3 = indices[tri_count].z;
		
		
		auto midPoint = [&vertex,&dict,i,radius](const int iA,const int iB) {
			




			vec P1 = vertex[iA];
			vec P2 = vertex[iB];
			 
			if (i == 0) {


				float lenP1=sqrt(dot(P1, P1));
				float lenP2=sqrt(dot(P2, P2));

				P1 = (1.0f / lenP1) * P1;
			    P2 = (1.0f / lenP2) * P2;
				vertex[iA] =radius* P1;
				vertex[iB] = radius*P2;
			}
			
			int verticePrevSize = vertex.size();

			long long int bignum = (iA < iB) ? iB : iA;
			long long int smallnum = (iA < iB) ? iA : iB;

			long long int key = (smallnum << sizeof(int) * 8 )+ bignum;

			if (dict.count(key)==0) {

				vec mid_point_vector = (0.5f * (P2 - P1)) + P1;
				const float length = sqrt(dot(mid_point_vector, mid_point_vector));

				const vec unit_mid_point_vector = (1.0f / length) * (mid_point_vector);


				
				dict[key] = verticePrevSize;
				vertex.push_back(radius*unit_mid_point_vector);

				return verticePrevSize;
			}
			else {


				return dict[key];

			}

		};
		

		
		int Ia = midPoint(I1,I2);
		
		int Ib = midPoint(I2,I3);

		int Ic = midPoint(I3,I1);

		


		
		const veci T1 = { I1,Ia,Ic };
		const veci T2 = { Ia,I2,Ib };
		const veci T3 = { Ib,I3,Ic };
		const veci T4= { Ia,Ib,Ic };


		indices[tri_count] = T1;
		indices.push_back(T2);
		indices.push_back(T3);
		indices.push_back(T4);





	}

	std::vector<float> ver;

	data->vertices = vertex;
	data->indices = indices;

	

}
}
