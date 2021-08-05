/*
 * Plant.h
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_PLANT_H_
#define INCLUDE_PLANT_H_

#include <string>

#include "Position.h"
#include "Resources.h"

class Plant {
public:
	Plant(std::string plantName);
	Plant(std::string plantName, const Position& plantPosition);
	~Plant();

	Resources resourcesProduce();
	void resourcesConsume(Resources);

private:
	std::string plantName;
	Position plantPosition;

	Resources plantResources; //will evolve through time
};



#endif /* INCLUDE_PLANT_H_ */
