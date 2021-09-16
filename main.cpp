// 	--- IN PROGRESS ---
// 	This software is called "BIO_bio"
//	Let's try to make it as clear and detailed as possible for open-source and knowledge sharing reasons

//	Feel free to give feedbacks, tips and advices : contact@vanaprincipia.com <3

// 	This program was initiated by Vana Principia
//	CURRENT VERSION : V0.002
//	DATE : August 2021

#include <Python.h>

#include <iostream>
#include <map>

#include "Biobio/BIO_bio/BIO_bio.h"

#include "Biobio/CSVReader/CSVReader.h"
#include <Biobio/CSVReader/TempAlgorithms.h>

#include "Biobio/FieldDescription/Coordinates.h"
#include "Biobio/FieldDescription/LocalClimate.h"
#include "Biobio/FieldDescription/Plant.h"

#include "Biobio/DataTranslator/DataTranslator.h"

#include "Biobio/DesignAlgorithms/Design.h"

#include "Data/SatelliteData/SatelliteData.h"


int main(int argc, char** argv) {

	BIO_bio BIO_bio;

	//std::string fieldCoordinates = "48.396591, 4.507757";

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

	//--------------- CSV PART ---------------

	std::map<std::string,std::vector<std::pair<int,int>>> coordinatesOfPlants = getPlantsFromCSV("./csv/CelesteField.csv");

    std::map<std::string, std::vector<std::pair<int,int>>>::iterator it;

//    std::cout << "Number of species is " << coordinatesOfPlants.size() << std::endl;
//    for (it = coordinatesOfPlants.begin(); it != coordinatesOfPlants.end(); it++) {
//		std::cout << "Number of coordinates of " << it->first << " is " << it->second.size() << std::endl;
//    }

    generateCSVOfPlantsCoordinates(coordinatesOfPlants);

	//----------------------------------------


	//--------------- PYTHON PART ---------------

	char filename[] = "./python/fieldDisplayer.py";
	FILE* fp;

	Py_Initialize();

	fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);
	Py_Finalize();

	//------------ END OF PYTHON PART -----------

	return 0;
}
