#include "Screen.h"

Screen::Screen()
{
	
}

void Screen::init(std::string file) {
	if (!texture.loadFromFile(file)) {
		//prints error message if image fails to load
		std::cerr << "Failed to load image from: " << file << std::endl;
	}

	sprite.setTexture(texture);
	sprite.scale(DIM.x / texture.getSize().x, DIM.y / texture.getSize().y);	//scales image to fill game screen
}

void Screen::display(sf::RenderWindow *window) {
	window->draw(sprite);
}