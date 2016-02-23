/*
A MovingEntity is a type of Entity that can be controlled by Players.
They cannot move beyond the bounds of the game screen.
Meeps and Bullets are MovingEntities.

Author: Ailyn Tong
*/
#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include <map>

#include "Entity.h"

class MovingEntity : public Entity {	//MovingEntity is a subclass of Entity
public:
	/*Constructor
	Parameters:
	-spritesheet file path
	-speed at which entity moves
	-amount sprite is to be scaled by
	*/
	MovingEntity(std::string file, int moveSpeed, float scale = 4);
	
	//update method implemented by subclasses
	virtual void update() = 0;

	//checks if moving in a specified direction will cause entity to go off-screen
	bool hitBounds(MoveDirection direction);

	//getters and setters
	inline unsigned int getDirection() { return direction; }
	inline unsigned int getSpeed() { return moveSpeed; }
	inline void setSpeed(int speed) { moveSpeed = speed; }
protected:
	std::map<unsigned int, int> spriteMap;	//maps a direction to a spriteNum

	unsigned int direction;	//current direction movingentity is facing/moving
	int moveSpeed;	//speed at which entity moves

	void initMap();	//initializes spriteMap
};

#endif