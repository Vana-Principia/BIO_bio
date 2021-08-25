/*
 * DataTranslator.cpp
 *
 *  Created on: 25 août 2021
 *      Author: antony
 */

#include "Biobio/DataTranslator/DataTranslator.h"

DataTranslator::DataTranslator() {
}

DataTranslator::~DataTranslator() {
}

LightParameters* DataTranslator::light(SatelliteData* satelliteData) {
	LightParameters* light = new LightParameters();
	return light;
}

SoilParameters* DataTranslator::soil(SatelliteData* satelliteData) {
	SoilParameters* soil = new SoilParameters();
	return soil;
}

WaterParameters* DataTranslator::water(SatelliteData* satelliteData) {
	WaterParameters* water = new WaterParameters();
	return water;
}

WindParameters* DataTranslator::wind(SatelliteData* satelliteData) {
	WindParameters* wind = new WindParameters();
	return wind;
}
