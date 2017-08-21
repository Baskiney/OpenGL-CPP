	/*
	 * Renderer.cpp
	 *
	 *  Created on: 12.08.2017
	 *      Author: Robin
	 */

	// Headers for other project files
	#include "Renderer.h"
	#include "BlockRenderer.h"
	#include "../models/Input.h"
	#include "../models/Logic.h"
	#include "../models/World.h"

	// C++ native functions
	#include <stdlib.h>
	#include <stdio.h>
	#include <iostream>

	// OpenGL and Helper Libraries
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>

	GLFWwindow* window;

	void __renderScene(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//>--Render Inputs
			computeMatricesFromInputs(window);
			ProjectionMatrix = getProjectionMatrix();
			ViewMatrix = getViewMatrix();
			ModelMatrix = glm::mat4( 1.0f );
			MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
			//<--Render Inputs


			__renderBlocks();

			//std::cout << "Test" << std::endl;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	void __initRenderers(){

		__initBlockRenderer();

	}


	int __start(int argc, char **argv) {

		if( !glfwInit() ) {
		    return 1;
		}

		// Anti-Aliasing yay
		glfwWindowHint(GLFW_SAMPLES, 4);

		//Use new OpenGL COntext
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow( 1376, 768, "Robin OpenGL Test", NULL, NULL);
			if( window == NULL ){
				return 1;
			}
		glfwMakeContextCurrent(window);

		//Init glew
		if (glewInit() != GLEW_OK) {
				glfwTerminate();
				return 1;
			}

		// Ensure we can capture the escape key being pressed below
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
		// Hide the mouse and enable unlimited mouvement
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		// Set the mouse at the center of the screen
		glfwPollEvents();
		glfwSetCursorPos(window, 1024/2, 768/2);

		// Depth
		glEnable(GL_DEPTH_TEST);
		// Accept fragment if it closer to the camera than the former one
		glDepthFunc(GL_LESS);
		// Cull Textures not facing camera
		glEnable(GL_CULL_FACE);

		//Creates render/game logic
	    initLogic();

		//Initialises Renderers
		__initRenderers();


		//Blue Skybox
		glClearColor(0.5, 0.7, 1.0, 1.0);


		//Render loop
		do{
				__renderScene();

		  } // Check if the ESC key was pressed or the window was closed
			while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
				   glfwWindowShouldClose(window) == 0 );

		glfwTerminate();

		return 0;
	}



