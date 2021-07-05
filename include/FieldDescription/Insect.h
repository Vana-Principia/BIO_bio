/*
 * Insect.h
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_INSECT_H_
#define INCLUDE_INSECT_H_

#include <string>

class Insect {
public:
	Insect(std::string insectName);
	~Insect();

private:
	std::string insectName;
};

#endif /* INCLUDE_INSECT_H_ */
