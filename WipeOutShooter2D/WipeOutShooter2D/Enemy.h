#pragma once
#include <SFML/Graphics.hpp>


class Enemy
{

private:
	sf::RectangleShape shape;


public:
	Enemy();
	virtual ~Enemy();
	//functions
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	void setPos(sf::Vector2f vect);
	void update();
	void render(sf::RenderTarget* target);
};

