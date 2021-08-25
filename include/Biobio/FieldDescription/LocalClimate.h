/*
 * LocalClimate.h
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_LOCALCLIMATE_H_
#define INCLUDE_LOCALCLIMATE_H_

#include <string>
#include "Coordinates.h"

class LocalClimate {
public:
	LocalClimate(Coordinates coordinates);
	~LocalClimate();

private:
	Coordinates m_coordinates;
};



#endif /* INCLUDE_LOCALCLIMATE_H_ */
