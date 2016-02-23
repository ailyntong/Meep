/*
A Player is composed of a Meep and a Bullet, and controls the behavior of
the Meep and Bullet based on user input.

Author: Ailyn Tong
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <array>

#include "Resources.h"
#include "Meep.h"
#include "Bullet.h"

class Player {
public:
	/*Constructor
	Parameters:
	-spritesheet file path for meep
	-spritesheet file path for bullet
	*/
	Player(std::string meepFile, std::string bulletFile);

	//initializes player with a keyMap and a starting point
	void init(std::array<sf::Keyboard::Key, 5> keyMap, Point start);

	//updates player
	void update();

	//checks if player's Meep has collided with another entity's hitBox
	bool checkHit(sf::FloatRect hitBox);

	//toggles movement speed
	void moveOverride();
	
	//kills player's Meep
	void die();

	//respawns player's Meep and resets respawnCount
	void respawn();

	//draws meep (and bullet) onto game screen
	void draw(sf::RenderWindow *window);

	//increments or decrements player score
	void modifyScore(bool positive);

	//getters
	inline Point getPoint() { return meep.getPoint(); }
	inline sf::FloatRect getMeepBox() { return meep.getHitBox(); };
	inline sf::FloatRect getBulletBox() { return bullet.getHitBox(); }
	inline unsigned int getDirection() { return meep.getDirection(); }
	inline unsigned int getMeepSpeed() { return meep.getSpeed(); }
	inline unsigned int getBulletSpeed() { return bullet.getSpeed(); }
	inline int getScore() { return score; }

	inline bool isDead() { return meep.isDead(); }
private:
	//A Player has a Meep and a Bullet
	Meep meep;
	Bullet bullet;

	bool slow;	//whether or not player has been slowed by obstacle(s)

	int respawnCount;	//current number of updates player has been waiting to respawn

	int score;	//current score

	inline bool key(sf::Keyboard::Key key) { return sf::Keyboard::isKeyPressed(key); }	//checks if specified key is pressed
	
	std::array<sf::Keyboard::Key, 5> keyMap;	//maps a specific key to a MoveDirection or combination thereof
};

#endif