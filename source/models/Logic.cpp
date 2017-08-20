/*
 * Logic.cpp
 *
 *  Created on: 18.08.2017
 *      Author: Robin
 */

#include "Logic.h"
#include "World.h"

//View Logic
GLuint MatrixID;
glm::mat4 ProjectionMatrix;
glm::mat4 ViewMatrix;
glm::mat4 ModelMatrix;
glm::mat4 MVP;

//Map Logic
int Blocksize;


void initLogic(){

	//Hardcoded 10000
	Blocksize = 10000;

	generateMap();

}
