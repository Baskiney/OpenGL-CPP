	/*
	 * Renderer.cpp
	 *
	 *  Created on: 12.08.2017
	 *      Author: Robin
	 */

	// Headers for other project files
	#include "Renderer.h"
	#include "BlockRenderer.h"

	// C++ native functions
	#include <stdlib.h>
	#include <stdio.h>

	// OpenGL and Helper Libraries
	#include <GL/glew.h>
	#include <GLFW/glfw3.h>

	GLFWwindow* window;

	void __renderScene(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



			__renderBlock();




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

		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow( 1024, 768, "OpenGL", NULL, NULL);
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

		// Depth
		glEnable(GL_DEPTH_TEST);
		// Accept fragment if it closer to the camera than the former one
		glDepthFunc(GL_LESS);

		//Init Renderers
		__initRenderers();

		//Blue Skybox
		glClearColor(0.5, 0.7, 1.0, 1.0);

		do{
				__renderScene();

		  } // Check if the ESC key was pressed or the window was closed
			while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
				   glfwWindowShouldClose(window) == 0 );

		glfwTerminate();

		return 1;
	}



