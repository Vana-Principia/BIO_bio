/*
 * DataTranslator.h
 *
 *  Created on: 25 août 2021
 *      Author: antony
 */

#ifndef SRC_BIOBIO_DATATRANSLATOR_DATATRANSLATOR_H_
#define SRC_BIOBIO_DATATRANSLATOR_DATATRANSLATOR_H_

#include "Data/SatelliteData/SatelliteData.h"

#include "Biobio/ClimateParameters/LightParameters.h"
#include "Biobio/ClimateParameters/SoilParameters.h"
#include "Biobio/ClimateParameters/WaterParameters.h"
#include "Biobio/ClimateParameters/WindParameters.h"

class DataTranslator {
public:
	DataTranslator();
	~DataTranslator();

	LightParameters* light(SatelliteData*);
	SoilParameters* soil(SatelliteData*);
	WaterParameters* water(SatelliteData*);
	WindParameters* wind(SatelliteData*);

private:
};

#endif /* SRC_BIOBIO_DATATRANSLATOR_DATATRANSLATOR_H_ */
