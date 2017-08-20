/*
 * WorldGenerator.cpp
 *
 *  Created on: 19.08.2017
 *      Author: Robin
 */

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <cstdlib>
#include "World.h"

glm::vec3 BlockData[10000];
int BlockType[10000];
int index = 0;

//Draws random heightmapt

//void generateMap(){
//
//	int index = 0;
//	for(int z = 0; z < 200; z += 2)
//	{
//		for(int x = 0; x < 200; x += 2)
//		{
//			glm::vec3 block;
//
//				//Calculates positions
//				block.x = x;
//				block.y = rand() % 5;
//				block.z = -z;
//
//
//			BlockData[index++] = block;
//		}
//
//	}
//
//}


void generateMap(){

	index = 0;
	for(int z = 0; z < 150; z += 2)
	{
		for(int x = 0; x < 150; x += 2)
		{
			// Draw Tree randomly
			if(rand() % 200 == 5){
				generateTree(x,-z);
			}else{
				glm::vec3 block;
				block.x = x;
				block.y = 0;
				block.z = -z;
				BlockType[index] = 1; //Grass
				BlockData[index] = block;
				index++;
			}
		}

	}

}

// TODO Y for generator
void generateTree(int x, int z){

	//Draw stem
	for(int i = 0; i < 8; i+=2){
		glm::vec3 block;
		block.x = x;
		block.y = i;
		block.z = z;
		BlockType[index] = 1; //Bark
		BlockData[index] = block;
		index++;
	}

}

void destroyBlock(int id){
	glm::vec3 block;
	block.x = 0;
	block.y = 0;
	block.z = 0;
	BlockData[id] = block;
}






