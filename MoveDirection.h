/*
A Direction enum for Meep and Bullet classes.
Uses binary format and bit operations to represent multiple directions simultaneously.

Author: Ailyn Tong
*/
#ifndef MOVEDIRECTION_H
#define MOVEDIRECTION_H

enum MoveDirection {
	UP = 1 << 1,
	DOWN = 1 << 2,
	LEFT = 1 << 3,
	RIGHT = 1 << 4
};

#endif