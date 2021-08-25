/*
 * Position.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "Biobio/FieldDescription/Position.h"

Position::Position() {
	m_X = 0;
	m_Y = 0;
	m_Z = 0;
}

Position::Position(int coordX, int coordY, int coordZ) {
	m_X = coordX;
	m_Y = coordY;
	m_Z = coordZ;
}

Position::~Position() {

}
