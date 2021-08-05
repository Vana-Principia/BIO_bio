// 	This software is called "Biobio"
//	Let's try to make it as clear and detailed as possible for open-source and knowledge sharing reasons
//	e.g.
//		"DataTranslator translator = BIO_bio.getTranslator();
//		LightParameters lightParameters = translator.light(data);
//		(...)"
//	give us more information (for now) than
//		"BIO_bio.generateLocalClimate(data)"

//	Feel free to give feedbacks, tips and advices : contact@vanaprincipia.com <3

// 	This program was initiated by Vana Principia
//	CURRENT VERSION : V0.001
//	DATE : August 2021

#include <iostream>

#include "Biobio.h"

#include "Coordinates.h"

#include "Data.h"
#include "DataTranslator.h"

#include "LightParameters.h"
#include "SoilParameters.h"
#include "WaterParameters.h"
#include "WindParameters.h"

#include "LocalClimate.h"
#include "Plant.h"
#include "Design.h"

int main(int argc, char** argv) {

	Biobio BIO_bio;

	Coordinates coordinates = BIO_bio.generateCoordinates(argv[1]);

	Data data = BIO_bio.collectData(coordinates, "all");
	//this will take a while (Copernicus + GBIF + other ToBeDefined)
	//TODO need to be detailed (Priority 1)

	DataTranslator translator = BIO_bio.getTranslator();

	LightParameters lightParameters = translator.light(data);
	SoilParameters soilParameters = translator.soil(data);
	WaterParameters waterParameters = translator.water(data);
	WindParameters windParameters = translator.wind(data);
	//now we got our parameters

	LocalClimate localClimate = BIO_bio.generateLocalClimate(lightParameters, soilParameters, waterParameters, windParameters);
	//now we got our local climate
	//TODO could be detailed

	Plant matchingPlants = BIO_bio.getAdpatedSpecies(localClimate);
	//now we got our plants
	//TODO could be detailed

	Design designs =  BIO_bio.generateOptimizedDesigns(matchingPlants);
	//and now, our designs!
	//TODO need to be detailed (Priority 1)

	BIO_bio.sendResultToClient(designs.configuration("all"), designs.associatedData("all"));
	//results sent to client
	//TODO could be detailed

	return 0;
}
