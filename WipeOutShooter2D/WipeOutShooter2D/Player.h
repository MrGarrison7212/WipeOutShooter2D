#pragma once
#include <SFML/Graphics.hpp>


class Player
{

private:
	sf::CircleShape shape;

	//private functions
	void initCircleShape();

public:
	Player();
	virtual ~Player();

	//functions
	void update();
	void render(sf::RenderTarget& target);
};

