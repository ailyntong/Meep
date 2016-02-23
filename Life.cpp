#include "Life.h"

Life::Life() :
Entity(LIFE_FILE, 2)
{
	point = Point(DIM.x / 2 - size() / 2, DIM.y - 100);	//always spawns at bottom center of game screen
	setPoint(point);

	isTaken = false;
}

void Life::take(Player *p) {
	isTaken = true;
	setPoint(DEFAULT_START);

	std::cout << "Life has been taken" << std::endl;

	p->modifyScore(false);
}

void Life::draw(sf::RenderWindow *window) {
	if (!isTaken)
		window->draw(sprite);
}