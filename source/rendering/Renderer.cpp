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
	#include <iostream>
	#include <stdlib.h>

	// OpenGL and Helper Libraries
	#include <GL/glew.h>
	#include <GL/glut.h>

	void __renderScene(void) {

		// Skybox Color
		// RGBA
		glClearColor(0.5, 0.7, 1.0, 1.0);

		// Clear Color and Depth Buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Reset transformations
		glLoadIdentity();
		// Set the camera
		gluLookAt(	x,    y,  z,
					x+lx, y+ly,  z+lz,
					0.0f, 1.0f,  0.0f);

		// Render here... ------------------------------------------------------


		glPushMatrix();
					__renderBlock();
		glPopMatrix();



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


	int __start(int argc, char **argv) {

		// init GLUT and create window
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(1024,768);
		glutCreateWindow("OpenGL");

		// register callbacks
		glutDisplayFunc(__renderScene);
		glutReshapeFunc(__changeSize);
		glutIdleFunc(__renderScene);
		glutSpecialFunc(processSpecialKeys);
		glutMouseFunc(mouseButton);
		glutMotionFunc(mouseMove);

		// Depth
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		// enter GLUT event processing cycle
		glutMainLoop();

		return 1;
	}

