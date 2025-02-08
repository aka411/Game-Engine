#pragma once

#include <vector>
#include <string>

#include "mathLib.h"
#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <glad/glad.h>

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"


unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);

class ModelHelper
{

public:
    std::vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    std::vector<Mesh>    meshes;
    std::string directory;
    bool gammaCorrection;



    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    void processNode(aiNode* node, const aiScene* scene);

    void LoadModel(std::string const& path);

    

    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);

};






