/*
 * Field.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "../include/Field.h"

Field::Field(std::string ID, const Coordinates& coordinates, int numberOfExistingPlants) {
	fieldCoordinates = coordinates;
	fieldID = ID;
	fieldNumberOfExistingPlants = numberOfExistingPlants;
}

Field::~Field() {

}

std::string Field::getID() {
	return fieldID;
}

const Coordinates& Field::getCoordinates() {
	return fieldCoordinates;
}


