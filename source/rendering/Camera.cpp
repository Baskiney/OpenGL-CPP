/*
 * Camera.cpp
 *
 *  Created on: 13.08.2017
 *      Author: Robin
 */

#include "Camera.h"

#include <cmath>

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GL/glut.h>

// Camera Speed Multiplier
float fraction = 1.0;

// angle of rotation for the camera direction
float angleX=0.0;
float angleY=0.0;

// actual vector representing the view of camera's direction
float lx=0.0f, lz=-1.0f, ly=0.0f;

// XZ position of the physical camera
float x=0.0, z=5.0, y=1.0;

// Default values for Camera
float deltaAngleX = 0.0;
float deltaAngleY = 0.0;
int xOrigin = -1;
int yOrigin = -1;

void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT :
			x += lz;
			z -= lx;
			break;
		case GLUT_KEY_RIGHT :
			x -= lz;
			z += lx;
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			y += ly * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			y -= ly * fraction;
			break;
	}
}

void mouseMove(int x, int y) {

         // this will only be true when the left button is down
         if (xOrigin >= 0 && yOrigin >=0) {

		// update deltaAngle
		deltaAngleX = (x - xOrigin) * 0.003f;
		deltaAngleY = (y - yOrigin) * 0.003f;

		// update camera's direction
		lx = sin(angleX + deltaAngleX);
		ly = -sin(angleY + deltaAngleY);
		lz = -cos(angleX + deltaAngleX);
	}
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_RIGHT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angleX += deltaAngleX;
			angleY += deltaAngleY;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
			yOrigin = y;
		}
	}
	// Mouse wheel up
	if (button == 3){
		processSpecialKeys(GLUT_KEY_UP,0,0);
	}
	// Mouse wheel up
	if (button == 4){
		processSpecialKeys(GLUT_KEY_DOWN,0,0);
	}
}
