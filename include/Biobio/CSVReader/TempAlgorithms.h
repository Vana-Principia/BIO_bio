/*
 * TempAlgorithms.h
 *
 *  Created on: 2 sept. 2021
 *      Author: antony
 */

#ifndef INCLUDE_BIOBIO_CSVREADER_TEMPALGORITHMS_H_
#define INCLUDE_BIOBIO_CSVREADER_TEMPALGORITHMS_H_

#include <map>
#include <string>
#include <vector>

#include "Biobio/CSVReader/CSVReader.h"

std::map<std::string,std::vector<std::pair<int,int>>> getPlantsFromCSV(std::string csvName) {
	std::ifstream file(csvName);
	CSVRow row;

	int i = 1;
	std::map<std::string,std::vector<std::pair<int,int>>> coordinatesOfPlants;

	while(file >> row)
	{

		std::vector<std::pair<int,int>> coordinates;

		if (i != 1 && row[4].empty() == false) {
			//std::cout << "Coordinates of " << row[2] << " are " << row[4] <<"\n";

			//e.g. Coordinates of Corylus avellana are (4,4) (2,8) (2,9) (2,10) (2,11)
			std::string plantName(row[1]);
			std::string globalCoordinates(row[4]);
			std::string specificCoordinates;
			std::string delimiter(" ");
			size_t pos = 0;

			while ((pos = globalCoordinates.find(delimiter)) != std::string::npos) {
				specificCoordinates = globalCoordinates.substr(0, pos);
				//get coordinates "(X,Y)"

				unsigned open = specificCoordinates.find("(") + 1;
				unsigned separator = specificCoordinates.find(",");
				unsigned close = specificCoordinates.find(")") - 1;
				int X = stoi(specificCoordinates.substr(open, separator - open));
				int Y = stoi(specificCoordinates.substr (separator + 1, close - separator));

				//std::cout << "X = " << X << ", Y = " << Y << std::endl;

				coordinates.push_back(std::make_pair(X,Y));
				//std::cout << specificCoordinates << std::endl;
				globalCoordinates.erase(0, pos + delimiter.length());
			}

			coordinatesOfPlants[plantName] = coordinates;
		}

		i++;
	}

	return coordinatesOfPlants;
}

void generateCSVOfPlantsCoordinates(std::map<std::string,std::vector<std::pair<int,int>>> plantsCoordinates) {
	std::ofstream outputFile;
	outputFile.open ("./csv/plantsCoordinates.csv");

	std::map<std::string, std::vector<std::pair<int,int>>>::iterator itMap;
	std::vector<std::pair<int,int>>::iterator itVector;

	for (itMap = plantsCoordinates.begin(); itMap != plantsCoordinates.end(); itMap++) {
		outputFile << itMap->first;
		for (itVector = itMap->second.begin(); itVector != itMap->second.end(); itVector++) {
			outputFile << "," << itVector.base()->first << "," << itVector.base()->second;
		}
		outputFile << "\n";
	}

    outputFile.close();
}

#endif /* INCLUDE_BIOBIO_CSVREADER_TEMPALGORITHMS_H_ */
