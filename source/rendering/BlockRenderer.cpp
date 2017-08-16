/*
 * BlockRenderer.cpp
 *
 *  Created on: 13.08.2017
 *      Author: Robin
 */

#include "BlockRenderer.h"

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GL/glut.h>

GLuint VBO;
GLuint colorbuffer;

void __initBlockRenderer(){

	// Inits vertex Buffer and Polygon Data
	static const GLfloat vertex[] = {
	    -1.0f,-1.0f,-1.0f,
	    -1.0f,-1.0f, 1.0f,
	    -1.0f, 1.0f, 1.0f,
	     1.0f, 1.0f,-1.0f,
	    -1.0f,-1.0f,-1.0f,
	    -1.0f, 1.0f,-1.0f,
	     1.0f,-1.0f, 1.0f,
	    -1.0f,-1.0f,-1.0f,
	     1.0f,-1.0f,-1.0f,
	     1.0f, 1.0f,-1.0f,
	     1.0f,-1.0f,-1.0f,
	    -1.0f,-1.0f,-1.0f,
	    -1.0f,-1.0f,-1.0f,
	    -1.0f, 1.0f, 1.0f,
	    -1.0f, 1.0f,-1.0f,
	     1.0f,-1.0f, 1.0f,
	    -1.0f,-1.0f, 1.0f,
	    -1.0f,-1.0f,-1.0f,
	    -1.0f, 1.0f, 1.0f,
	    -1.0f,-1.0f, 1.0f,
	     1.0f,-1.0f, 1.0f,
	     1.0f, 1.0f, 1.0f,
	     1.0f,-1.0f,-1.0f,
	     1.0f, 1.0f,-1.0f,
	     1.0f,-1.0f,-1.0f,
	     1.0f, 1.0f, 1.0f,
	     1.0f,-1.0f, 1.0f,
	     1.0f, 1.0f, 1.0f,
	     1.0f, 1.0f,-1.0f,
	    -1.0f, 1.0f,-1.0f,
	     1.0f, 1.0f, 1.0f,
	    -1.0f, 1.0f,-1.0f,
	    -1.0f, 1.0f, 1.0f,
	     1.0f, 1.0f, 1.0f,
	    -1.0f, 1.0f, 1.0f,
	     1.0f,-1.0f, 1.0f
	};


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

}

void __renderBlock(){


	glColor3f(0,0.4,0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 6*2*3);
	glDisableClientState(GL_VERTEX_ARRAY);

}
