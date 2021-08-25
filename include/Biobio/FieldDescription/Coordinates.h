/*
 * Coordinates.h
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_COORDINATES_H_
#define INCLUDE_COORDINATES_H_

#include <string>

class Coordinates {
public:
	Coordinates();
	Coordinates(std::string);
	~Coordinates();

private:
	std::string m_coordinatesAsString;

};



#endif /* INCLUDE_COORDINATES_H_ */
