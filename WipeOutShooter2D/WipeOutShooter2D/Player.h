#pragma once
#include <SFML/Graphics.hpp>


class Player
{

private:
	sf::CircleShape shape;

	float movementSpeed;


	//private functions
	void initCircleShape();

public:
	Player();
	virtual ~Player();

	//accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const float getRad() const;


	//functions
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);
};

