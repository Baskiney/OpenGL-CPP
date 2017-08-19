/*
 * Logic.h
 *
 *  Created on: 18.08.2017
 *      Author: Robin
 */
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <GL/glew.h>

#ifndef SOURCE_MODELS_LOGIC_H_
#define SOURCE_MODELS_LOGIC_H_

//View Logic -------------
static GLuint MatrixID;
static glm::mat4 ProjectionMatrix;
static glm::mat4 ViewMatrix;
static glm::mat4 ModelMatrix;
static glm::mat4 MVP;


//World MAP
static int Blocksize = 60;

#endif /* SOURCE_MODELS_LOGIC_H_ */
