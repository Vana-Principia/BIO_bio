/*
 * Position.h
 *
 *  Created on: 3 juil. 2021
 *      Author: antony
 */

#ifndef INCLUDE_POSITION_H_
#define INCLUDE_POSITION_H_

class Position {
public:
	Position();
	Position(int coordX, int coordY, int coordZ);
	~Position();

private:
	int X, Y, Z;
};



#endif /* INCLUDE_POSITION_H_ */
