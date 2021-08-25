/*
 * BIO_bio.h
 *
 *  Created on: 16 août 2021
 *      Author: antony
 */

#ifndef SRC_BIOBIO_BIO_BIO_BIO_BIO_H_
#define SRC_BIOBIO_BIO_BIO_BIO_BIO_H_

#include "Data/SatelliteData/SatelliteData.h"

#include "Biobio/DataTranslator/DataTranslator.h"

#include "Biobio/FieldDescription/Coordinates.h"
#include "Biobio/FieldDescription/Surface.h"
#include "Biobio/FieldDescription/LocalClimate.h"
#include "Biobio/FieldDescription/Plant.h"

#include "Biobio/DesignAlgorithms/Design.h"

class BIO_bio {
public:
	BIO_bio(Coordinates = Coordinates(), Surface = Surface());
	~BIO_bio();

	Coordinates* generateCoordinates(char*);
	SatelliteData* collectSatelliteData(Coordinates*, std::string);
	DataTranslator* getTranslator();
	LocalClimate* generateLocalClimate(LightParameters*, SoilParameters*, WaterParameters*, WindParameters*);
	Plants* getAdpatedSpecies(LocalClimate*);
	Designs* generateOptimizedDesigns(Plants*);
	void sendResultToClient(DesignConfiguration, DesignData);

private:
	Coordinates* m_coordinates;
	Surface* m_surface;
};

#endif /* SRC_BIOBIO_BIO_BIO_BIO_BIO_H_ */
