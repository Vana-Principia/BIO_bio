/*
 * Plant.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "FieldDescription/Plant.h"

Plant::Plant(std::string name) {
	plantName = name;
}

Plant::Plant(std::string name, const Position& position) {
	plantName = name;
	plantPosition = position;
}

Plant::~Plant() {

}
