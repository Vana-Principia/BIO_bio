/*
 * Plant.cpp
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#include "Biobio/FieldDescription/Plant.h"

Plant::	Plant(std::string name, Position position, Resources resources) {
	m_plantName = name;
	m_plantPosition = position;
	m_plantResources = resources;
	m_maximumLifetime = 0;
}

Plant::~Plant() {

}

Resources Plant::resourcesProduce() {
	return m_plantResources;
}

void Plant::resourcesConsume(Resources resources) {
	m_plantResources = resources;
}


Plants::Plants() {

}

Plants::~Plants() {

}

void Plants::addPlant(Plant plantToAdd) {
	m_plants.push_back(plantToAdd);
}
