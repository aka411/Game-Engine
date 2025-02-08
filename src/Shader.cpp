#include "Shader.h"




void Shader::addShader(const char* vertexShaderSource, const char* fragmentShaderSource, std::string name){


unsigned int vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);

glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
glCompileShader(vertexShader);


int  success;
char infoLog[512];
glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);



if (!success)
{
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
}

unsigned int fragmentShader;
fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(fragmentShader);

int  successf;
char infoLogf[512];
glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &successf);



if (!successf)
{
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLogf);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLogf << std::endl;
}

unsigned int shaderProgram;
shaderProgram = glCreateProgram();



glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);


shaderList[name] = shaderProgram;

}

unsigned int Shader::getShader(std::string name)
{
    return shaderList[name];
}



