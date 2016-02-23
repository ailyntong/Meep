#include "Entity.h"

Entity::Entity(std::string file, float scale) :
point(DEFAULT_START)	//default starting location (off-screen)
{
	this->file = file;
	
	this->scale = scale;
	sprite.setScale(sf::Vector2f(scale, scale));

	loadSpriteSheet();

	sprite.setPosition(sf::Vector2f(point.x, point.y));
}

void Entity::loadSpriteSheet() {
	if (!spritesheet.loadFromFile(file)) {
		//prints error message if spritesheet fails to load
		std::cerr << "Failed to load sprite sheet from: " << file << std::endl;
	}
	sprite.setTexture(spritesheet);	//sprite references spritesheet
	sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));	//starts as first image (idle)
}

void Entity::draw(sf::RenderWindow *window) {
	window->draw(sprite);
}