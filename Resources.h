/*
Constants, simple data structures, and static methods

Author: Ailyn Tong
*/
#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "MoveDirection.h"
#include "Point.h"
#include "Dimension.h"

#define DIM Dimension(1500, 900)	//size of game screen

//movespeeds
#define MEEP_SPEED_NORMAL 4
#define MEEP_SPEED_SLOW 2
#define BULLET_SPEED 7

#define SPRITE_SIZE 16	//size of one sprite on spritesheet (px)
#define MAX_SCORE 3		//score needed to win
#define RESPAWN_TIMER 300	//time to respawn after death (# updates)

#define NUM_OBSTACLES 20	//# obstacles in game

#define DEFAULT_START Point(-100, -100)	//default spawn point for entities
#define P1_START Point(100, 100)	//P1's starting position
#define P2_START Point(1336, 100)	//P2's starting position

//image files
#define P1_MEEP_FILE "assets/BasicMeeps/BasicMeep_pink.png"
#define P2_MEEP_FILE "assets/BasicMeeps/BasicMeep_Blue.png"
#define P1_BULLET_FILE "assets/Bullets/Bullet_PinkGreen.png"
#define P2_BULLET_FILE "assets/Bullets/Bullet_BlueGreen.png"

#define OBSTACLE_FILE "assets/Miscellaneous/Obstacles.png"
#define LIFE_FILE "assets/Miscellaneous/Life.png"

#define START_SCREEN_FILE "assets/Screens/StartScreen.png"
#define P1_WIN_SCREEN_FILE "assets/Screens/EndScreen_P1.png"
#define P2_WIN_SCREEN_FILE "assets/Screens/EndScreen_P2.png"

/*Static Methods*/
namespace Resource {
	
	//Generates a random int between [min, max)
	//Creds: Neelay Junnarkar
	static int rng(double min, double max) {
		static unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::default_random_engine gen(seed);
		return std::uniform_int_distribution<int>(min, max)(gen);
	}

	//Collision algorithm: uses hitboxes of entities
	static bool collision(sf::FloatRect a, sf::FloatRect b) {
		return a.intersects(b);
	}

	//Generates a random position for an entity
	static Point gen_position(int size) {
		return Point(rng(0, DIM.x-size), rng(0, DIM.y-size));
	}
}

#endif