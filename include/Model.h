#pragma once

#include <vector>
#include "Mesh.h"


class Model
{
public:
    // model data 
    //std::vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    std::vector<Mesh>    meshes;
    //std::string directory;
    bool gammaCorrection;



};

