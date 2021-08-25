/*
 * DesignAlgorithm.cpp
 *
 *  Created on: 6 juil. 2021
 *      Author: antony
 */

#include "Biobio/DesignAlgorithms/Design.h"

Design::Design() {
}

Design::~Design() {
}

Designs::Designs() {

}

Designs::~Designs() {

}

std::vector<Design> Designs::getDesign() {
	return m_designs;
}

DesignConfiguration Designs::configuration(std::string) {
	DesignConfiguration* designConfiguration = new DesignConfiguration();
	return *designConfiguration;
}

DesignData Designs::associatedData(std::string) {
	DesignData* designData = new DesignData();
	return *designData;
}
