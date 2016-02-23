/*
An Entity is any game element that can interact with other game elements.
There are 4 types of Entities in this game: Meep, Bullet, Obstacle, Life.

Author: Ailyn Tong
*/
#ifndef ENTITY_H
#define ENTITY_H

#include "Resources.h"

class Entity {
public:
	/* Constructor
	Parameters:
	-spritesheet file path
	-size of one sprite in pixels
	*/
	Entity(std::string file, float scale = 4);

	//draws entity onto a RenderWindow (ie game screen)
	void draw(sf::RenderWindow *window);

	//getters and setters
	inline Point getPoint() const { return point; }
	inline void setPoint(Point point) { 
		this->point = point;
		sprite.setPosition(sf::Vector2f(point.x, point.y));
	}
	inline int16_t getX() const { return point.x; }
	inline int16_t getY() const { return point.y; }
	inline void setX(int16_t x) { setPoint(Point(x, point.y)); }
	inline void setY(int16_t y) { setPoint(Point(point.x, y)); }

	inline int size() const { return SPRITE_SIZE * scale; }	//returns rendered size of sprite
	inline sf::FloatRect getHitBox() const { return sprite.getGlobalBounds(); }	//returns bounding box of sprite
protected:
	Point point;	//entity's current location in the world

	std::string file;	//image file

	sf::Texture spritesheet;	//spritesheet referenced by sprite
	sf::Sprite sprite;	//image drawn onto game screen
	float scale;	//amount sprite is scaled by

	void loadSpriteSheet();	//loads texture with image file
};

#endif