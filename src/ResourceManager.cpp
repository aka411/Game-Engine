#include "ResourceManager.h"
#include "stb_image.h"




/***************************************
OS specific Resource Loading and Managing
*****************************************/


/*

void ResourceManager::loadShaderFromFile(const char* vertexPath, const char* fragmentPath, std::string name) {

    // Open the input file named
    std::ifstream vertexShaderFile(vertexPath);
    std::ifstream fragmentShaderFile(fragmentPath);

    // Check if the file is successfully opened 
    if (!vertexShaderFile.is_open() || !fragmentShaderFile.is_open()) {
        std::cout << "Error opening the file , check  file path of shaders!\n";

    }

    std::stringstream vertBuffer;
    std::stringstream fragBuffer;

    vertBuffer << vertexShaderFile.rdbuf();
    fragBuffer << fragmentShaderFile.rdbuf();

    std::string vertexString = vertBuffer.str();
    std::string fragmentString = fragBuffer.str();


    const char* vertexShaderSource = vertexString.c_str();
    const char* fragmentShaderSource = fragmentString.c_str();

    /*
    getFileString(vertexPath, vertexShaderSource);
    getFileString(fragmentPath, fragmentShaderSource);
    //


    shader.addShader(vertexShaderSource, fragmentShaderSource, name);

   

}
*/
/*void ResourceManager::loadTextureFromFile(const char* imagePath, const char* name)
{

    int width, height, nrChannels;
    unsigned char* data = stbi_load(imagePath, &width, &height, &nrChannels, 0);

    if (data)
    {
        texture.addTexture(data, width, height, nrChannels,name);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    

}*/




void ResourceManager::loadTextFromFile(const char* FilePath, std::string name) {




    // Open the input file named
    std::ifstream textFile(FilePath);
    

    // Check if the file is successfully opened 
    if (!textFile.is_open() ) {
        std::cout << "Error opening the file , check  file path of shaders!\n";

    }
    
    std::stringstream textBuffer;
    

    textBuffer << textFile.rdbuf();
    

    std::string textString = textBuffer.str();
   


    const char* textChar = textString.c_str();
    
    textResourceList[name] = textChar;

}

/*

void ResourceManager::loadModel(const char* modelPath,const char* name)
{

    ModelHelper modelHelper;

    Model model;

    modelHelper.LoadModel(modelPath);
    model.gammaCorrection = modelHelper.gammaCorrection;
    model.meshes = modelHelper.meshes;

    ModelList[name] = model;




}
*/

/*
unsigned int ResourceManager::getShader(std::string name)
{
    return shader.getShader(name);
}
*/

/*unsigned int ResourceManager::getTexture(const char* name) {


    return texture.getTexture(name);

}*/
/*
void ResourceManager::getModel(std::string name, Model*& ModelPointer)
{

    ModelPointer = &ModelList[name];

}
*/



void ResourceManager::loadTextureFromFile(const char* FilePath, std::string name) {
    




    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(1);
    unsigned char* data = stbi_load(FilePath, &width, &height, &nrComponents, 0);
    if (data)
    {
        Image image;
        image.width = width;
        image.height = height;
        image.nrComponents = nrComponents;
        image.imageData = data;
        imageResourceList[name] = image;

    }
    else {


        std::cout << "\n IMAGE LOADING ERROR AT :: " << name << "\n";
    }

}


/*!!!!!!!!!!!!!!!!!!!!!!!!!*
          TEMPORARY
 *!!!!!!!!!!!!!!!!!!!!!!!!!*/


void ResourceManager::addIndexedMesh(std::vector<float> vertices,std::vector<unsigned int>indices,std::string name) {


    Mesh mesh;

    mesh.vertices = vertices;
    mesh.indices = indices;

    meshList[name] = mesh;






}



 /*!!!!!!!!!!!!!!!!!!!!!!!!!*
           TEMPORARY
  *!!!!!!!!!!!!!!!!!!!!!!!!!*/