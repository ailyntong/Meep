#include "Game.h"

Game::Game() :
window(sf::VideoMode(DIM.x, DIM.y), "Meep!", sf::Style::Default),
p1(P1_MEEP_FILE, P1_BULLET_FILE),
p2(P2_MEEP_FILE, P2_BULLET_FILE)
{	
	window.setFramerateLimit(60);
	
	startScreen.init(START_SCREEN_FILE);

	//players have diff sets of controls
	std::array<sf::Keyboard::Key, 5>  keyMap1 = { sf::Keyboard::S, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::Space };
	std::array<sf::Keyboard::Key, 5> keyMap2 = { sf::Keyboard::L, sf::Keyboard::O, sf::Keyboard::SemiColon, sf::Keyboard::K, sf::Keyboard::Quote };

	//initializes players with a keyMap and a starting position
	p1.init(keyMap1, P1_START);
	p2.init(keyMap2, P2_START);

	std::cout << "Ready... ";
	start = true;	//enables start screen
	run();
}


void Game::run() {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				std::cout << "Game Exited\n";
			}

			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) 
					window.close();	//pressing Esc also closes window
				else if (event.key.code == sf::Keyboard::Return && start) {
					std::cout << "Go!\n";
					start = false;	//disables start screen if enter is pressed
				}
			}
		}

		window.clear({ 20, 27, 35 });	//clears into nice colour

		if (start) {	//if start screen is enabled display it
			startScreen.display(&window);
			window.display();
			continue;
		}
		if (win()) {	//if game has been won, end game and display proper end screen
			end();
			endScreen.display(&window);
			window.display();
			break;
		}

		//check if meeps touch anything
		checkCollision();
		checkSlow();
		checkLife();
		
		//update players
		p1.update();
		p2.update();

		//draw everything
		drawObstacles();
		life.draw(&window);

		p1.draw(&window);
		p2.draw(&window);
		
		window.display();
	}
}

void Game::drawObstacles() {
	for (Obstacle o : obstacles) {
		o.draw(&window);
	}
}

void Game::checkCollision() {
	if (!p1.isDead() && p1.checkHit(p2.getBulletBox())) {
		p1.die();
		p2.modifyScore(true);	//if p2 hits p1, give p2 a point
		printScores();
	}
	if (!p2.isDead() && p2.checkHit(p1.getBulletBox())) {
		p2.die();
		p1.modifyScore(true);	//if p1 hits p2, give p1 a point
		printScores();
	}
}

void Game::checkSlow() {
	for (Obstacle o : obstacles) {
		//slows players their meep is over an obstacle
		if (Resource::collision(p1.getMeepBox(), o.getHitBox()))
			p1.moveOverride();
		if (Resource::collision(p2.getMeepBox(), o.getHitBox()))
			p2.moveOverride();
	}
}

void Game::checkLife() {
	//takes a life from enemy if player picks up life
	if (Resource::collision(p1.getMeepBox(), life.getHitBox()))
		life.take(&p2);
	else if (Resource::collision(p2.getMeepBox(), life.getHitBox()))
		life.take(&p1);
}

bool Game::win() {
	return p1.getScore() == MAX_SCORE || p2.getScore() == MAX_SCORE;
}

void Game::end() {
	std::cout << "GAME OVER" << std::endl;

	std::string winner;
	if (p1.getScore() == MAX_SCORE) {
		winner = "P1";
		endScreen.init(P1_WIN_SCREEN_FILE);
	}
	else {
		winner = "P2";
		endScreen.init(P2_WIN_SCREEN_FILE);
	}

	std::cout << "WINNER: " << winner << std::endl;
}

void Game::printScores() {
	std::cout << "P1 Score: " << p1.getScore() << std::endl;
	std::cout << "P2 Score: " << p2.getScore() << std::endl;
}