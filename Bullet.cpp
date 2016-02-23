#include "Bullet.h"

Bullet::Bullet(std::string file) : 
MovingEntity(file, BULLET_SPEED, 1)
{		
	disable();	//bullet starts disabled
}

void Bullet::init(unsigned int direction, int spriteNum, Point point) {
	this->point = point;

	//determines dX and dY based on direction
	this->direction = direction;
	if (direction & MoveDirection::UP)
		dY = -moveSpeed;
	if (direction & MoveDirection::DOWN)
		dY = moveSpeed;
	if (direction & MoveDirection::RIGHT)
		dX = moveSpeed;
	if (direction & MoveDirection::LEFT)
		dX = -moveSpeed;

	sprite.setTextureRect(sf::IntRect(spriteNum * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));

	//bullet is fully initialized, can move
	initialized = true;
}

void Bullet::disable() {
	initialized = false;

	point = DEFAULT_START;
	sprite.setPosition(sf::Vector2f(point.x, point.y));

	dX = 0;
	dY = 0;
}

void Bullet::update() {
	if (!initialized)
		return;

	if (hitBounds(MoveDirection::UP) || hitBounds(MoveDirection::DOWN) || hitBounds(MoveDirection::RIGHT) || hitBounds(MoveDirection::LEFT)) {
		disable();
		return;
	}

	//updates position every turn while initialized
	point.x += dX;
	point.y += dY;

	sprite.setPosition(sf::Vector2f(point.x, point.y));
}

Bullet::~Bullet() {

}