/*
 * TextureLoader.cpp
 *
 *  Created on: 21.08.2017
 *      Author: Robin
 */

#include <GL/glew.h>
#include "TextureLoader.h"
#include "../helpers/BMPloader.h"

GLuint Texture_Grass;
GLuint Texture_Bark;
GLuint Texture_Leaves;
GLuint Texture_Stone;

void __initTextures(){

	//1
	Texture_Grass = loadBMP("source/textures/grassblock/main.bmp");
	//2
	Texture_Bark = loadBMP("source/textures/tree/bark.bmp");
	//3
    Texture_Leaves = loadBMP("source/textures/leaf/main.bmp");
    //4
    Texture_Stone = loadBMP("source/textures/stone/main.bmp");

}

GLuint __loadTexture(int texID){

	if (texID == 1){	glBindTexture(GL_TEXTURE_2D, Texture_Grass); }
	if (texID == 2){	glBindTexture(GL_TEXTURE_2D, Texture_Bark); }
	if (texID == 3){	glBindTexture(GL_TEXTURE_2D, Texture_Leaves); }
	if (texID == 4){	glBindTexture(GL_TEXTURE_2D, Texture_Stone); }

	return 1;

}

