/*
 * BIO_bio.cpp
 *
 *  Created on: 16 aout 2021
 *      Author: antony
 */

#include "Biobio/BIO_bio/BIO_bio.h"
#include <iostream>

BIO_bio::BIO_bio(Coordinates coordinates, Surface surface) {
	std::cout << "<<< BIO_bio STARTED >>>" << std::endl;
	m_coordinates = &coordinates;
	m_surface = &surface;
}

BIO_bio::~BIO_bio() {
	std::cout << "<<< BIO_bio STOPED >>>" << std::endl;
}

Coordinates* BIO_bio::generateCoordinates(char*) {
	Coordinates* coordinates = new Coordinates(); //TODO clean all new
	return coordinates;
}

SatelliteData* BIO_bio::collectSatelliteData(Coordinates*, std::string) {
	SatelliteData* data = new SatelliteData();
	return data;
}

DataTranslator* BIO_bio::getTranslator() {
	DataTranslator* translator = new DataTranslator();
	return translator;
}

LocalClimate* BIO_bio::generateLocalClimate(LightParameters*, SoilParameters*, WaterParameters*, WindParameters*) {
	LocalClimate* climate = new LocalClimate(*m_coordinates);
	return climate;
}

Plants* BIO_bio::getAdpatedSpecies(LocalClimate*) {
	Plants* plants = new Plants();
	return plants;
}

Designs* BIO_bio::generateOptimizedDesigns(Plants*) {
	Designs* designs = new Designs();
	return designs;
}

void BIO_bio::sendResultToClient(DesignConfiguration, DesignData) {

}
