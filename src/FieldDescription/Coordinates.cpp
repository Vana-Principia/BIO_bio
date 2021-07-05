/*
 * Coordinates.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "Coordinates.h"

Coordinates::Coordinates() {
	coordinatesAsString = "NO COORDINATES";
}

Coordinates::Coordinates(std::string coordinates) {
	coordinatesAsString = coordinates;
}

Coordinates::~Coordinates() {
}
