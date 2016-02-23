#include "MovingEntity.h"

MovingEntity::MovingEntity(std::string file, int moveSpeed, float scale) :
Entity(file, scale)
{	
	direction = 0;
	this->moveSpeed = moveSpeed;

	initMap();
}

void MovingEntity::initMap() {
	spriteMap[MoveDirection::DOWN] = 0;
	spriteMap[MoveDirection::DOWN | MoveDirection::RIGHT] = 1;
	spriteMap[MoveDirection::RIGHT] = 2;
	spriteMap[MoveDirection::UP | MoveDirection::RIGHT] = 3;
	spriteMap[MoveDirection::UP] = 4;
	spriteMap[MoveDirection::UP | MoveDirection::LEFT] = 5;
	spriteMap[MoveDirection::LEFT] = 6;
	spriteMap[MoveDirection::DOWN | MoveDirection::LEFT] = 7;
}

bool MovingEntity::hitBounds(MoveDirection direction) {
	if (direction == 0) return true;
	
	if (direction & MoveDirection::UP && point.y - moveSpeed <= 0)
		return true;
	if (direction & MoveDirection::DOWN && point.y + SPRITE_SIZE*scale + moveSpeed >= DIM.y)
		return true;
	if (direction & MoveDirection::RIGHT && point.x + SPRITE_SIZE*scale + moveSpeed >= DIM.x)
		return true;
	if (direction & MoveDirection::LEFT && point.x - moveSpeed <= 0)
		return true;

	return false;
}