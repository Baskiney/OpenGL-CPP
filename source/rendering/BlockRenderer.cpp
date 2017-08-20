/*
 * BlockRenderer.cpp
 *
 *  Created on: 13.08.2017
 *      Author: Robin
 */

#include "BlockRenderer.h"
#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <iostream>
#include "../helpers/BMPloader.h"
#include "../models/World.h"
#include "../models/Logic.h"
#include "shaders/Shader.h"



GLuint VBO;
GLuint UVB;
GLuint programID;
GLuint Texture1;
GLuint Texture2;
GLuint TextureID;



void __initBlockRenderer(){

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	programID = LoadShaders();

	// Load the texture using any two methods
	Texture1 = loadBMP("R:\\Dienste\\Eclipse Workspace\\OpenGL\\source\\textures\\grassblock\\main.bmp");
	Texture2 = loadBMP("R:\\Dienste\\Eclipse Workspace\\OpenGL\\source\\textures\\tree\\bark.bmp");
	//GLuint Texture = loadDDS("uvtemplate.DDS");

	// Get a handle for our "myTextureSampler" uniform
	TextureID  = glGetUniformLocation(programID, "myTextureSampler");

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

	static const GLfloat uv[] = {

			0.000059f, 1.0f-0.000004f,
			0.000103f, 1.0f-0.336048f,
			0.335973f, 1.0f-0.335903f,
			1.000023f, 1.0f-0.000013f,
			0.667979f, 1.0f-0.335851f,
			0.999958f, 1.0f-0.336064f,
			0.667979f, 1.0f-0.335851f,
			0.336024f, 1.0f-0.671877f,
			0.667969f, 1.0f-0.671889f,
			1.000023f, 1.0f-0.000013f,
			0.668104f, 1.0f-0.000013f,
			0.667979f, 1.0f-0.335851f,
			0.000059f, 1.0f-0.000004f,
			0.335973f, 1.0f-0.335903f,
			0.336098f, 1.0f-0.000071f,
			0.667979f, 1.0f-0.335851f,
			0.335973f, 1.0f-0.335903f,
			0.336024f, 1.0f-0.671877f,
			1.000004f, 1.0f-0.671847f,
			0.999958f, 1.0f-0.336064f,
			0.667979f, 1.0f-0.335851f,
			0.668104f, 1.0f-0.000013f,
			0.335973f, 1.0f-0.335903f,
			0.667979f, 1.0f-0.335851f,
			0.335973f, 1.0f-0.335903f,
			0.668104f, 1.0f-0.000013f,
			0.336098f, 1.0f-0.000071f,
			0.000103f, 1.0f-0.336048f,
			0.000004f, 1.0f-0.671870f,
			0.336024f, 1.0f-0.671877f,
			0.000103f, 1.0f-0.336048f,
			0.336024f, 1.0f-0.671877f,
			0.335973f, 1.0f-0.335903f,
			0.667969f, 1.0f-0.671889f,
			1.000004f, 1.0f-0.671847f,
			0.667979f, 1.0f-0.335851f

	};



	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	glGenBuffers(1, &UVB);
	glBindBuffer(GL_ARRAY_BUFFER, UVB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_STATIC_DRAW);



	//Uses Block Data from Logic/World
	unsigned int instanceVBO;
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(BlockData), &BlockData[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	//3d Attribute Pointer
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glVertexAttribDivisor(2, 1);

	// End Instanced Rendering


}

void __renderBlocks(){

		glUseProgram(programID);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture1);
		// Set our "myTextureSampler" sampler to use Texture Unit 0
		glUniform1i(TextureID, 0);

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

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, UVB);
		glVertexAttribPointer(
		    1,                           // attribute. No particular reason for 1, but must match the layout in the shader.
		    2,                           // size = U+V
		    GL_FLOAT,                    // type
		    GL_FALSE,                    // normalized?
		    0,                           // stride
		    (void*)0                     // array buffer offset
		);


		// Instances
		glDrawArraysInstanced(GL_TRIANGLES, 0, 12*3, Blocksize);

		// End-Instances

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);


}
