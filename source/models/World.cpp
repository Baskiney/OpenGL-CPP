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




void generateMap(){
	glm::vec3 block;
	index = 0;
	for(int z = 0; z < 100; z += 2)
	{
		for(int x = 0; x < 100; x += 2)
		{
			// Draw Tree randomly
			if(rand() % 200 == 5){
				// TODO set Y
				generateTree(x,-z,0);
			}else{
				block.x = x;
				block.y = 0;
				block.z = -z;
				BlockType[index] = 1; //Grass
				BlockData[index] = block;
				index++;
			}

			for(int s = 0; s < 4; s += 2){
				block.x = x;
				block.y = -s;
				block.z = -z;
				BlockType[index] = 4; //Stone
				BlockData[index] = block;
				index++;
			}
		}

	}

}

void generateTree(int x, int z, int y){

	glm::vec3 block;

	//Draw stem
	for(int ty = y; ty < y+10; ty+=2){
		block.x = x;
		block.y = ty;
		block.z = z;
		BlockType[index] = 2; //Bark
		BlockData[index] = block;
		index++;
	}

	//Leaves
	for(int ty = y+8; ty < y+12 ; ty+=2)
	{
		for(int tz = 0; tz < 6; tz += 2)
			{
				for(int tx = 0; tx < 6; tx += 2)
				{

					block.x = x+tx-2;
					block.y = ty;
					block.z = z+tz-2;

					BlockType[index] = 3; //Leaf
					BlockData[index] = block;
					index++;
				}

			}

	}

	block.x = x;
	block.y = y+12;
	block.z = z;
	BlockType[index] = 3; //Leaf
	BlockData[index] = block;
	index++;

}






