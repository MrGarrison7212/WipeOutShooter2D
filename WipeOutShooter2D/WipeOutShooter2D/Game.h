#pragma once
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <sstream>


class Game
{

private:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text pointText;
	//sound
	sf::SoundBuffer hit_buf;

	sf::Sound hit_sound;

	unsigned points;
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
	void initEnemies();
	void initSystems();
	void initGUI();
public:
	Game();
	virtual ~Game();

	//functions
	void updateVectors();
	void updateBulletsAndCombat();
	void updateEnemies();
	void updateGUI();

	void run();

	void update();

	void render();
};

