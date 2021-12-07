#pragma once
#include <SFML/Graphics.hpp>


class Player
{

private:
	sf::CircleShape shape;

	float movementSpeed;

	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	//private functions
	void initCircleShape();

public:
	Player();
	virtual ~Player();

	//functions
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);
};

