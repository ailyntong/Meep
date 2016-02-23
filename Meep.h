/*
Meeps are the characters controlled by Players.
There are different colours of Meeps, and each Meep can face
8 different positions.
Meeps can die, but they will respawn after a certain number of updates.
Running over obstacles will slow their movement speed temporarily.

Author: Ailyn Tong
*/
#ifndef MEEP_H
#define MEEP_H

#include "MovingEntity.h"

class Meep : public MovingEntity {	//Meep is a subclass of MovingEntity
public:
	/*Constructor
	Parameters:
	-spritesheet file path
	*/
	Meep(std::string file);
	
	//virtual destructor
	virtual ~Meep();

	//update method inherited from MovingEntity; UNUSED
	void update() override;
	
	//updates Meep with specified direction
	void update(unsigned int direction);

	void die();	//kills Meep
	void respawn();	//respawns Meep

	//getters
	inline int getSpriteNum() const { return spriteNum; }
	inline bool isDead() const { return dead; }
private:
	int spriteNum;	//index of current sprite being rendered

	bool dead;	//whether or not this Meep is dead and waiting to respawn
};

#endif