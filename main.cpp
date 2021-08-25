// 	--- IN PROGRESS ---
// 	This software is called "BIO_bio"
//	Let's try to make it as clear and detailed as possible for open-source and knowledge sharing reasons

//	Feel free to give feedbacks, tips and advices : contact@vanaprincipia.com <3

// 	This program was initiated by Vana Principia
//	CURRENT VERSION : V0.002
//	DATE : August 2021

#include <iostream>

#include "Biobio/BIO_bio/BIO_bio.h"

#include "Biobio/FieldDescription/Coordinates.h"
#include "Biobio/FieldDescription/LocalClimate.h"
#include "Biobio/FieldDescription/Plant.h"

#include "Biobio/DataTranslator/DataTranslator.h"

#include "Biobio/DesignAlgorithms/Design.h"

#include "Data/SatelliteData/SatelliteData.h"


int main(int argc, char** argv) {

	BIO_bio BIO_bio;

	Coordinates* coordinates = BIO_bio.generateCoordinates(argv[1]);

	SatelliteData* satelliteData = BIO_bio.collectSatelliteData(coordinates, "all");
	//this will take a while (Copernicus + GBIF + other ToBeDefined)
	//TODO need to be detailed (Priority 1)

	DataTranslator* translator = BIO_bio.getTranslator();

	LightParameters* lightParameters = translator->light(satelliteData);
	SoilParameters* soilParameters = translator->soil(satelliteData);
	WaterParameters* waterParameters = translator->water(satelliteData);
	WindParameters* windParameters = translator->wind(satelliteData);
	//now we got our parameters

	LocalClimate* localClimate = BIO_bio.generateLocalClimate(lightParameters, soilParameters, waterParameters, windParameters);
	//now we got our local climate
	//TODO could be detailed

	Plants* matchingPlants = BIO_bio.getAdpatedSpecies(localClimate);
	//now we got our plants
	//TODO could be detailed

	Designs* designs =  BIO_bio.generateOptimizedDesigns(matchingPlants);
	//and now, our designs!
	//TODO need to be detailed (Priority 1)

	BIO_bio.sendResultToClient(designs->configuration("all"), designs->associatedData("all"));
	//results sent to client
	//TODO could be detailed

	return 0;
}
