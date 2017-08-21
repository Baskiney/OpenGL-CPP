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
extern GLuint MatrixID;
extern glm::mat4 ProjectionMatrix;
extern glm::mat4 ViewMatrix;
extern glm::mat4 ModelMatrix;
extern glm::mat4 MVP;


//World MAP
extern int chunkSize;

void initLogic();

#endif /* SOURCE_MODELS_LOGIC_H_ */
