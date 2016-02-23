#include "Meep.h"

Meep::Meep(std::string file) : 
MovingEntity(file, MEEP_SPEED_NORMAL)
{
	spriteNum = 0;
	dead = false;
}

void Meep::update() {
	//UNUSED
}

void Meep::update(unsigned int direction) {
	if (dead)
		return;	//skips update if Meep is dead

	//Meep only moves if it will not go out of bounds
	if (direction & MoveDirection::DOWN && !hitBounds(MoveDirection::DOWN))
		point.y += moveSpeed;
	if (direction & MoveDirection::UP && !hitBounds(MoveDirection::UP))
		point.y -= moveSpeed;
	if (direction & MoveDirection::RIGHT && !hitBounds(MoveDirection::RIGHT))
		point.x += moveSpeed;
	if (direction & MoveDirection::LEFT && !hitBounds(MoveDirection::LEFT))
		point.x -= moveSpeed;

	this->direction = direction;
	
	//sets Meep's new sprite image and position
	spriteNum = spriteMap[direction];
	sprite.setTextureRect(sf::IntRect(spriteNum * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
	setPoint(point);
}

void Meep::die() {
	dead = true;
	point = DEFAULT_START;	//moves Meep off-screen to avoid invisible collision
}

void Meep::respawn() {
	dead = false;
	point = Resource::gen_position(SPRITE_SIZE * scale);	//respawns in a random location
}

Meep::~Meep() {

}