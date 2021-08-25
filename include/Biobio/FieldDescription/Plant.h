/*
 * Plant.h
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_PLANT_H_
#define INCLUDE_PLANT_H_

#include <string>
#include <vector>

#include "Position.h"
#include "Resources.h"

class Plant {
public:
	Plant(std::string plantName, Position plantPosition = Position(), Resources plantResources = Resources());
	~Plant();

	void getPlantInformation();
	Resources resourcesProduce();
	void resourcesConsume(Resources);

private:
	std::string m_plantName;
	int m_maximumLifetime;

	Position m_plantPosition;
	Resources m_plantResources; //will evolve through time
};

class Plants {
public:
	Plants();
	~Plants();

	void addPlant(Plant plantToAdd);

private:
	std::vector<Plant> m_plants;
};



#endif /* INCLUDE_PLANT_H_ */
