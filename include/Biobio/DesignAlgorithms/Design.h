/*
 * Design.h
 *
 *  Created on: 25 août 2021
 *      Author: antony
 */

#ifndef INCLUDE_DESIGNALGORITHMS_DESIGN_H_
#define INCLUDE_DESIGNALGORITHMS_DESIGN_H_

#include "Biobio/FieldDescription/Field.h"
#include "Biobio/FieldDescription/Plant.h"

#include "DesignConfiguration.h"
#include "DesignData.h"

class Design {
public:
	Design();
	~Design();

private:

};

class Designs {
public:
	Designs();
	~Designs();
	std::vector<Design> getDesign();

	DesignConfiguration configuration(std::string);
	DesignData associatedData(std::string);

private:
	std::vector<Design> m_designs;

};

#endif /* INCLUDE_DESIGNALGORITHMS_DESIGN_H_ */
