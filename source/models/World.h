/*
 * WorldGenerator.h
 *
 *  Created on: 19.08.2017
 *      Author: Robin
 */

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#ifndef SOURCE_MODELS_WORLDGENERATOR_H_
#define SOURCE_MODELS_WORLDGENERATOR_H_

void generateMap();
void generateTree(int x, int z);
void destroyBlock(int id);

extern glm::vec3 BlockData[10000];
extern int BlockType[10000];

#endif /* SOURCE_MODELS_WORLDGENERATOR_H_ */
