/*
 * Field.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "Biobio/FieldDescription/Field.h"

Field::Field(std::string ID, const Coordinates& coordinates, int numberOfExistingPlants) {
	m_fieldCoordinates = coordinates;
	m_fieldID = ID;
	m_fieldNumberOfExistingPlants = numberOfExistingPlants;
}

Field::~Field() {

}

std::string Field::getID() {
	return m_fieldID;
}

const Coordinates& Field::getCoordinates() {
	return m_fieldCoordinates;
}


