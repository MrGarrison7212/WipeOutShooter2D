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

	Bullet(float dir_X, float dir_Y, float movement_speed);

	virtual ~Bullet();

	//functions
	const sf::Vector2f& getPos() const;
	void setPos(sf::Vector2f vect);
	void setDir(sf::Vector2f dir);
	const float getSpeed() const;

	void update();
	void render(sf::RenderTarget* target);
};

