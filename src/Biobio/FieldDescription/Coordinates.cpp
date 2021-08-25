/*
 * Coordinates.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "Biobio/FieldDescription/Coordinates.h"

Coordinates::Coordinates() {
	m_coordinatesAsString = "NO COORDINATES";
}

Coordinates::Coordinates(std::string coordinates) {
	m_coordinatesAsString = coordinates;
}

Coordinates::~Coordinates() {
}
