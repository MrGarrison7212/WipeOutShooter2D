#pragma once
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>


class Game
{

private:
	sf::RenderWindow* window;

	//player
	Player* player;

	//Bullets
	Bullet* b1;
	std::vector<Bullet*> bullets;
	//Enemy


	//Vectors

	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	//private functions
	void initWindow();
	void initPlayer();
	void initBullet();
public:
	Game();
	virtual ~Game();

	//functions
	void updateVectors();
	void updateBullets();
	void updateEnemiesAndCombat();

	void run();

	void update();

	void render();
};

