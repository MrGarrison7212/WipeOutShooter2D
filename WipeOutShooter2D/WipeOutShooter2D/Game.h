#pragma once
#include <SFML/Graphics.hpp>


class Game
{

private:
	sf::RenderWindow* window;


	//private functions
	void initWindow();


public:
	Game();
	virtual ~Game();

	void run();
};

