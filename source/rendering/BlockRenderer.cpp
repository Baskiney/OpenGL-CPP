/*
 * BlockRenderer.cpp
 *
 *  Created on: 13.08.2017
 *      Author: Robin
 */

#include "BlockRenderer.h"
#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GL/glut.h>

#include <iostream>
#include "shaders/shader.h"


GLuint VBO;
GLuint CBO;
GLuint programID;

void __initBlockRenderer(){

	programID = LoadShaders();

	// Inits vertex Buffer and Polygon Data
	static const GLfloat vertex[] = {
			  -1.0f, -1.0f, 0.0f,
			   1.0f, -1.0f, 0.0f,
			   0.0f,  1.0f, 0.0f,
	};



	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

}

void __renderBlock(){

		glUseProgram(programID);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(
					0,                  		// attribute. No particular reason for 0, but must match the layout in the shader.
					3,                  		// size
					GL_FLOAT,           		// type
					GL_FALSE,           		// normalized?
					0,                  		// stride
					(void*)0            		// array buffer offset
				);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);

}
