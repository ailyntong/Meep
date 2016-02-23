#include "Player.h"

Player::Player(std::string meepFile, std::string bulletFile) :
meep(meepFile),
bullet(bulletFile) {
	respawnCount = 0;
	score = 0;	//players start with a score of 0

	slow = false;
}

void Player::init(std::array<sf::Keyboard::Key, 5> keyMap, Point start) {
	this->keyMap = keyMap;
	meep.setPoint(start);
}

void Player::update() {
	if (isDead()) {	//if player is dead increases respawnCount until it is time to respawn
		if (respawnCount == RESPAWN_TIMER)
			respawn();
		else 
			respawnCount++;
	}

	//player's current direction is determined by which keys are pressed
	unsigned int direction = 0;
	if (key(keyMap[0]))
		direction |= MoveDirection::DOWN;
	if (key(keyMap[1]))
		direction |= MoveDirection::UP;
	if (key(keyMap[2]))
		direction |= MoveDirection::RIGHT;
	if (key(keyMap[3]))
		direction |= MoveDirection::LEFT;

	//meep slows if on an obstacle
	if (slow) {
		meep.setSpeed(MEEP_SPEED_SLOW);
		moveOverride();
	}
	else
		meep.setSpeed(MEEP_SPEED_NORMAL);

	meep.update(direction);

	//initializes bullet if shooting is available
	if (key(keyMap[4]) && !bullet.isInit() && direction != 0)
		bullet.init(direction, meep.getSpriteNum(), Point(meep.getX() + meep.size()/2, meep.getY()));	//shoots from the leaf

	bullet.update();
}

bool Player::checkHit(sf::FloatRect hitBox) {
	return Resource::collision(getMeepBox(), hitBox);
}

void Player::moveOverride() {
	slow = !slow;
}

void Player::die() {
	meep.die();
}

void Player::respawn() {
	respawnCount = 0;
	meep.respawn();
}

void Player::modifyScore(bool positive) {
	if (positive)
		++score;
	else if (score < 0)
		--score;
}

void Player::draw(sf::RenderWindow *window) {
	if (!meep.isDead())	//only draws meep if not dead
		meep.draw(window);

	if (bullet.isInit())	//only draws bullet if it has been shot
		bullet.draw(window);
}