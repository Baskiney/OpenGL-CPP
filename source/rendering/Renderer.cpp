	/*
	 * Renderer.cpp
	 *
	 *  Created on: 12.08.2017
	 *      Author: Robin
	 */

	// Headers for other project files
	#include "Renderer.h"
	#include "BlockRenderer.h"
	#include "Camera.h"

	// C++ native functions
	#include <stdlib.h>
	#include <stdio.h>

	// OpenGL and Helper Libraries
	#include <GL/glew.h>
	#include <GL/glut.h>


	void __renderScene(void) {

		// Clear Color and Depth Buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Reset transformations
		glLoadIdentity();
		// Set the camera
		gluLookAt(	x,    y,  z,
					x+lx, y+ly,  z+lz,
					0.0f, 1.0f,  0.0f);

		// Render here... ------------------------------------------------------


		__renderBlock();



		// Stop rendering here...? ---------------------------------------------

		glutSwapBuffers();
	}

	void __changeSize(int w, int h) {

		// Prevent a divide by zero, when window is too short
		// (you cant make a window of zero width).
		if (h == 0)
			h = 1;

		float ratio =  w * 1.0 / h;

		// Use the Projection Matrix
		glMatrixMode(GL_PROJECTION);

		// Reset Matrix
		glLoadIdentity();

		// Set the viewport to be the entire window
		glViewport(0, 0, w, h);

		// Set the correct perspective.
		gluPerspective(45.0f, ratio, 0.1f, 100.0f);

		// Get Back to the Modelview
		glMatrixMode(GL_MODELVIEW);
	}

	void __initRenderers(){

		__initBlockRenderer();

	}

	void initCallbacks(){
		glutDisplayFunc(__renderScene);
		glutReshapeFunc(__changeSize);
		glutIdleFunc(__renderScene);
		glutSpecialFunc(processSpecialKeys);
		glutMouseFunc(mouseButton);
		glutMotionFunc(mouseMove);
	}



	int __start(int argc, char **argv) {

		// init GLUT and create window
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(1024,768);
		glutCreateWindow("OpenGL");

		// For Wireframe
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//Init glew
	    GLenum res = glewInit();
	    if (res != GLEW_OK) {
	      return 1;
	    }

		// register callbacks
		initCallbacks();

		// Depth
		glEnable(GL_DEPTH_TEST);

		//Init Renderers
		__initRenderers();

		//Blue Skybox
		glClearColor(0.5, 0.7, 1.0, 1.0);

		// enter GLUT event processing cycle
		glutMainLoop();

		return 1;
	}



