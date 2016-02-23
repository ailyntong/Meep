/*
A Game Screen (start screen, end screen)

Author: Ailyn Tong
*/

#ifndef SCREEN_H
#define SCREEN_H

#include "Resources.h"

class Screen {
public:
	/*Constructor*/
	Screen();

	void init(std::string file);	//gives texture an image file and sets sprite
	void display(sf::RenderWindow *window);	//renders screen onto specified RenderWindow

private:	
	sf::Texture texture;	//image referenced by sprite
	sf::Sprite sprite;	//encapsulates image to be rendered
};

#endif