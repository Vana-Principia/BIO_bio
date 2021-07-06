// This software aims to create an expert 2.0
// Please feel free to improve this solution, we'll need as much willing soul as possible. For the greater good.

#include <string>
#include <iostream>

#include "FieldDescription/Field.h"

int main(int argc, char** argv) {

	std::string coordinatesOfTheField = "4.507289,48.396723:4.508242,48.396742";
	const Coordinates coordinates(coordinatesOfTheField);
	Field field("Celeste", coordinates, 50);

	std::string fieldName = field.getID();
	std::cout << "The name of the field is " << fieldName << " and its coordinates are " << coordinatesOfTheField << std::endl;
}
