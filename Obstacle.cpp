#include "Obstacle.h"

Obstacle::Obstacle() :
Entity(OBSTACLE_FILE) 
{
	int index = Resource::rng(0, 5);	//chooses a random one of five obstacle patterns
	sprite.setTextureRect(sf::IntRect(index * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));

	point = Resource::gen_position(SPRITE_SIZE * scale);	//spawns in a random location
	setPoint(point);
}