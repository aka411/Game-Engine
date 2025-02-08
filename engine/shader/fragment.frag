#version 330 core
out vec4 FragColor;
  
//in vec3 ourColor;
 in vec2 TexCoord;

uniform sampler2D texture_diffuse1;

//ourTexture
void main()
{
    
     FragColor= texture(texture_diffuse1,TexCoord);
    //FragColor = vec4(0.0,0.70196078431372549019607843137255,0.52549019607843137254901960784314,1.0);
}