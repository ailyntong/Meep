/*
The Dimension class has two values: x for width, and y for height

Author: Ailyn Tong
*/

#ifndef DIMENSION_H
#define DIMENSION_H

struct Dimension {
	float x, y;

	Dimension(float x, float y) :
		x(x),
		y(y)
	{

	};
};

#endif