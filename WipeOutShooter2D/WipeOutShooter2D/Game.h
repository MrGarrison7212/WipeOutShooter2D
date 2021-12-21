#pragma once
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
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
	std::vector<Enemy*> enemies;
	Enemy* e1;

	float spawnTimer;
	float spawnTimerMax;
	int enemyCounter;
	//Vectors

	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	//private functions
	void initWindow();
	void initPlayer();
	void initBullet();
	void initEnemies();
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

