/*
 * Input.cpp
 *
 *  Created on: 18.08.2017
 *      Author: Robin
 */

#include "Input.h"
#include <GLFW/glfw3.h>
#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

glm::mat4 InputViewMatrix;
glm::mat4 InputProjectionMatrix;

glm::mat4 getViewMatrix(){
	return InputViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return InputProjectionMatrix;
}


// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 0, 15 );

// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;


float FoV = 70.0f;

float speed = 6.0f;
float mouseSpeed = 0.0025f;



void computeMatricesFromInputs(GLFWwindow* window){

	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, 1024/2, 768/2);

	// Compute new orientation
	horizontalAngle += mouseSpeed * float(1024/2 - xpos );
	verticalAngle   += mouseSpeed * float( 768/2 - ypos );

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f),
		0,
		cos(horizontalAngle - 3.14f/2.0f)
	);

	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	//Do something on click
	if (glfwGetMouseButton(window, 0) == GLFW_PRESS){
		speed = 60.0f;
	}


	//Gotta go fast
	if (glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_PRESS){
		speed = 60.0f;
	}
	if (glfwGetKey( window, GLFW_KEY_LEFT_SHIFT ) == GLFW_RELEASE){
		speed = 10.0f;
	}

	// Move forward
	if (glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	// Projection matrix : 45° Field of View, 16:9 ratio, display range : 0.1 unit <-> 200 units
	InputProjectionMatrix = glm::perspective(glm::radians(FoV), 16.0f / 9.0f, 0.1f, 200.0f);
	// Camera matrix
	InputViewMatrix       = glm::lookAt(
								position,           // Camera is here
								position+direction, // and looks here : at the same position, plus "direction"
								up                  // Head is up (set to 0,-1,0 to look upside-down)
						   );

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}
