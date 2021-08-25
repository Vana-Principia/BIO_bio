/*
 * Resources.h
 *
 *  Created on: 12 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_FIELDDESCRIPTION_RESOURCES_H_
#define INCLUDE_FIELDDESCRIPTION_RESOURCES_H_

#include "Position.h"

class Resources {
public:
	Resources(Position resourcesPosition = Position());
	~Resources();

private:
	Position m_resourcesPosition;
};

#endif /* INCLUDE_FIELDDESCRIPTION_RESOURCES_H_ */
