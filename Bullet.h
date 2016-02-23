/*
Players can shoot bullets through the enemy Meep to kill it.
A Bullet travels in a straight line in the direction the Player's Meep is moving
when it is shot, and continues until it hits an edge of the game screen.
NOTE: Players cannot shoot bullets if their Meep is not moving.

Author: Ailyn Tong
*/
#ifndef BULLET_H
#define BULLET_H

#include "MovingEntity.h"
#include "Meep.h"

class Bullet : public MovingEntity {	//Bullet is a subclass of MovingEntity
public:	
	/*Constructor
	Parameters:
	-spritesheet file path
	*/
	Bullet(std::string file);
	
	//virtual destructor
	virtual ~Bullet();

	/*when shot, initializes bullet with a direction, spriteNum, and starting point;
	bullets will always shoot from the Meep's leaf*/
	void init(unsigned int direction, int spriteNum, Point point);
	
	//update method inherited from MovingEntity
	void update() override;

	//disables bullet
	void disable();

	//returns init state
	inline bool isInit() const { return initialized; }
private:
	int dX, dY;	//change in x- and y-coords each update

	bool initialized;	//initialization state; default FALSE
};

#endif