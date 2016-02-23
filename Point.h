/*
A simple implementation of a Point class with x and y values.

Author: Ailyn Tong
*/

#ifndef POINT_H
#define POINT_H

#include <cstdint>

struct Point {
	//integer of 16 bits
	int16_t x, y;

	Point(int16_t x, int16_t y) :
		x(x),
		y(y)
	{
	}
};

#endif