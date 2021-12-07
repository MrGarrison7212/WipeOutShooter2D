#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>


class Game
{

private:
	sf::RenderWindow* window;

	//player
	Player* player;

	//private functions
	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//functions

	void run();

	void update();

	void render();
};

