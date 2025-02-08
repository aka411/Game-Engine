#include "Renderer.h"


/*void Renderer::setRenderData()
{

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        &indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

    glBindVertexArray(0);

}
*/






void Renderer::getResource()
{
   
    manager->getModel(para->modelName, model);
    shader= manager->getShader(para->shaderProgram);
    Draw();
}

void Renderer:: Draw()
{





    for(int j=0;j<model->meshes.size();j++){

        const unsigned int VAO = model->meshes[j].VAO;
        std::vector<unsigned int> indices = model->meshes[j].indices;
        std::vector < Texture> textures = model->meshes[j].textures;

    // bind appropriate textures
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    unsigned int normalNr = 1;
    unsigned int heightNr = 1;
    for (unsigned int i = 0; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
        // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = textures[i].type;
        if (name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if (name == "texture_specular")
            number = std::to_string(specularNr++); // transfer unsigned int to string
        else if (name == "texture_normal")
            number = std::to_string(normalNr++); // transfer unsigned int to string
        else if (name == "texture_height")
            number = std::to_string(heightNr++); // transfer unsigned int to string

        // now set the sampler to the correct texture unit
        glUniform1i(glGetUniformLocation(shader, (name + number).c_str()), i);
        // and finally bind the texture
        glBindTexture(GL_TEXTURE_2D, textures[i].id);
    }

    // draw mesh
    glUseProgram(shader);



    unsigned int model =glGetUniformLocation(shader, "model");

    unsigned int view = glGetUniformLocation(shader, "view");
    unsigned int projection = glGetUniformLocation(shader, "projection");

   glUniformMatrix4fv(view,1,true, &camera->viewMatrix.m[0][0]);
   glUniformMatrix4fv(projection, 1, true, &camera->projectionMatrix.m[0][0]);

   const float mod[4][4] = { 1.000000, 0.000000, 0.000000, 0.000000,
0.000000, 1.000000, 0.000000, 0.000000,
0.000000, 0.000000, 1.000000,-30.0,
0.000000, 0.000000, 0.00000, 1.000000


   };

   glUniformMatrix4fv(model, 1, true, &mod[0][0]);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
   // glBindVertexArray(0);

    // always good practice to set everything back to defaults once configured.
    glActiveTexture(GL_TEXTURE0);
    }
}








void Renderer::setResourceManager(ResourceManager* resManager)
{
    manager = resManager;
}

void Renderer::render(GameObject* obj)
{

	obj->render(para);
 
    getResource();
}
