/*
 * Input.h
 *
 *  Created on: 18.08.2017
 *      Author: Robin
 */
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


#ifndef SOURCE_MODELS_INPUT_H_
#define SOURCE_MODELS_INPUT_H_


void computeMatricesFromInputs(GLFWwindow* window);
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif /* SOURCE_MODELS_INPUT_H_ */
