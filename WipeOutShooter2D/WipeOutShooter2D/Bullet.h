#pragma once
#include <SFML/Graphics.hpp>


class Bullet
{
private:
	sf::CircleShape shape;
	
	sf::Vector2f direction;
	float maxSpeed;

public:
	Bullet();

	Bullet(float radius, float dir_X, float dir_Y, float movement_speed);

	virtual ~Bullet();

	//functions
	void update();
	void render(sf::RenderTarget* target);
};

