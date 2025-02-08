#version 330 core
#extension GL_ARB_explicit_uniform_location : enable

  layout (location = 0) in vec3 aPos;
  layout (location = 1) in vec3 normals; // not needed
  layout (location = 2) in vec2 aTexCoord;


  uniform mat4 model;
  uniform mat4 view;
  uniform mat4 projection;

out vec2 TexCoord;


/*float t=1;
  float s = sin(t);
  float c = cos(t);


mat4x4  rot = mat4x4
(c,0,-s,0,
 0,1,0,0,
 -s,0,-c,0,
 0,0,0,1
);
 */


void main()
{

    gl_Position = projection*view*model*vec4(aPos, 1.0);

   //  gl_Position = model*vec4(0.5*aPos, 1.0);
    TexCoord = aTexCoord;
}