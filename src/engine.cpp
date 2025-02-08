

#include "engine.h"
#include "InputHandler.h"
#include "Camera.h"



 void runEngine(GLFWwindow* window) {




     ResourceManager rm;
     Renderer renderer;
     std::cout << &rm << "\n";
     renderer.setResourceManager(&rm);
     rm.loadShaderFromFile("vertexshader.vert","fragment.frag","default");
     rm.loadShaderFromFile("Grid.vert", "Grid.frag", "grid");

     rm.loadModel("./backpack/backpack.obj", "adam");

     // rm.loadModel("./models/astronautA.obj", "adam");
   
     std::cout << renderer.manager << "\n";

     GameObject adam;

     adam.setModel("adam");
     adam.setShader("default");
     
     InputHandler inputHandler;

     inputHandler.setContext(window);

     Camera cam;
   
     cam.generateCamera(3.14/2,5,100,800/600);

     cam.position = vec(0, 0, 0);
     renderer.camera = &cam;
     
     cam.update();






     /*


     unsigned int fbo;
     glGenFramebuffers(1, &fbo);

     unsigned int texture;
     glGenTextures(1, &texture);
     glBindTexture(GL_TEXTURE_2D, texture);

     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800, 600, 0, GL_RGBA, GL_FLOAT, NULL);

     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 glBindFramebuffer(GL_FRAMEBUFFER, fbo);
     glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

    

     glBindFramebuffer(GL_FRAMEBUFFER, 0);


     float* data = (float*)malloc(12*4 *800 * 600);
     int z = -1;

*/

     // render loop
     // -----------
     while (!glfwWindowShouldClose(window))
     {
        // input
         // -----
         processInput(window);

         Command* command = inputHandler.handleInput();
         
         if (command)
         {
             
             command->execute(cam);
         }




         // render
         // ------
         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
         glClear(GL_COLOR_BUFFER_BIT);

         glClear(GL_DEPTH_BUFFER_BIT);
         glEnable(GL_DEPTH_TEST);

         //float timeValue = glfwGetTime();
         //glUniform1f(1, timeValue / 10.0);

         //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         

;         renderer.render(&adam);


         unsigned int shader = rm.getShader("grid");
 glUseProgram(shader);
         unsigned int view = glGetUniformLocation(shader, "viewin");
         unsigned int projection = glGetUniformLocation(shader, "proj");
         
         glUniformMatrix4fv(view, 1, true, &cam.viewMatrix.m[0][0]);
         glUniformMatrix4fv(projection, 1, true, &cam.projectionMatrix.m[0][0]);

       //  if (z == 0) glBindFramebuffer(GL_FRAMEBUFFER, fbo);

         glDrawArrays(GL_TRIANGLES, 0, 6);

        // if(z==0){ glReadPixels(0, 0, 800, 600, GL_RGBA, GL_FLOAT, data); }
        // if (z == 0) glBindFramebuffer(GL_FRAMEBUFFER, 0);
         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
         // -------------------------------------------------------------------------------
         glfwSwapBuffers(window);
         glfwPollEvents();


        // if (z == 0) { std::cout <<"\n" << *data; }

         
     }

     // glfw: terminate, clearing all previously allocated GLFW resources.
     // ------------------------------------------------------------------
     glfwTerminate();
    
 }

 // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
 // ---------------------------------------------------------------------------------------------------------
 void processInput(GLFWwindow* window)
 {
     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
         glfwSetWindowShouldClose(window, true);
 }









