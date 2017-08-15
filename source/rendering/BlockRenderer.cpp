/*
 * BlockRenderer.cpp
 *
 *  Created on: 13.08.2017
 *      Author: Robin
 */

#include "BlockRenderer.h"

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GL/glut.h>
#include "../external/math_3d.h"

GLuint VBO;

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
	// Maybe draws too many, optimize later
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*12*9, &vertex[0], GL_STATIC_DRAW);
}

void __renderBlock(){

	glColor3f(0,0.4,0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	// Maybe draws too many, optimize later
	glDrawArrays(GL_TRIANGLES, 0, 12*9);
	glDisableClientState(GL_VERTEX_ARRAY);

}
