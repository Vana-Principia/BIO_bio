/*
 * Field.h
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_FIELD_H_
#define INCLUDE_FIELD_H_

#include <string>
#include "Plant.h"
#include "Coordinates.h"

class Field {
public:
	Field(std::string ID, const Coordinates& coordinates, int numberOfExistingPlants = 0);
	~Field();

	std::string getID();
	const Coordinates& getCoordinates();

private:
	Coordinates fieldCoordinates;
	std::string fieldID;
	int fieldNumberOfExistingPlants;
};

#endif /* INCLUDE_FIELD_H_ */
