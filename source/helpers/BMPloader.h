/*
 * BMPloader.h
 *
 *  Created on: 18.08.2017
 *      Author: Robin
 */
#include <GL/glew.h>

#ifndef SOURCE_HELPERS_BMPLOADER_H_
#define SOURCE_HELPERS_BMPLOADER_H_

// Load a .BMP file using our custom loader
GLuint loadBMP(const char * imagepath);

//// Since GLFW 3, glfwLoadTexture2D() has been removed. You have to use another texture loading library,
//// or do it yourself (just like loadBMP_custom and loadDDS)
//// Load a .TGA file using GLFW's own loader
//GLuint loadTGA_glfw(const char * imagepath);

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char * imagepath);


#endif /* SOURCE_HELPERS_BMPLOADER_H_ */
