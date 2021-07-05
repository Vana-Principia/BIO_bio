/*
 * Position.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "Position.h"

Position::Position() {
	X = 0;
	Y = 0;
	Z = 0;
}

Position::Position(int coordX, int coordY, int coordZ) {
	X = coordX;
	Y = coordY;
	Z = coordZ;
}

Position::~Position() {

}
