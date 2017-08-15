/*
 * Camera.h
 *
 *  Created on: 13.08.2017
 *      Author: Robin
 */

#ifndef SOURCE_RENDERING_CAMERA_H_
#define SOURCE_RENDERING_CAMERA_H_

extern float fraction, angleY, angleX, lx, lz, x, z, y, ly;
extern int xOrigin;

void processSpecialKeys(int key, int xx, int yy);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);

#endif /* SOURCE_RENDERING_CAMERA_H_ */
