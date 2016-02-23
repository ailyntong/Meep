/*
The Game class links all components of the game:
RenderWindow, Screens, Players, Obstacles, Life.

The Game class also contains overall game control methods:
collision detection, slow detection, start/end

Author: Ailyn Tong
*/

#ifndef GAME_H
#define GAME_H

#include "Resources.h"
#include "Player.h"
#include "Screen.h"
#include "Obstacle.h"
#include "Life.h"

class Game {
public:
	/*Constructor*/
	Game();

	//runs game
	void run();

private:
	bool start;	//for startScreen

	Screen startScreen, endScreen;	//two Screens
	
	sf::RenderWindow window;	//window in which game components are drawn

	Player p1, p2;	//players
	
	std::array<Obstacle, NUM_OBSTACLES> obstacles;	//array of all obstacles in game
	Life life;	//life powerup

	void drawObstacles();	//draws all obstacles

	void checkCollision();	//meep-bullet collision detection
	void checkSlow();	//meep-obstacle slow detection
	void checkLife();	//meep-life collision detection

	bool win();	//checks if game has been won
	void end();	//ends game with a Screen and print messages

	void printScores();	//prints scores of each player
};

#endif