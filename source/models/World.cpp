/*
 * WorldGenerator.cpp
 *
 *  Created on: 19.08.2017
 *      Author: Robin
 */

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "World.h"
#include "Logic.h"
#include <string.h>

void generateMap(){

	static glm::vec3 BlockData[4096];

	int index = 0;
	for(int i = 0; i < 100; i += 2)
	{
		for(int j = 0; j < 100; j += 2)
		{
			glm::vec3 translation;
			translation.x = j;
			translation.y = 0;
			translation.z = -i;
			BlockData[index++] = translation;
		}

	}

}
