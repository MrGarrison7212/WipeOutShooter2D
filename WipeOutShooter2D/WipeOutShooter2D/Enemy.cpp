#include "pch.h"
#include "Enemy.h"


Enemy::Enemy()
{
	this->shape.setFillColor(sf::Color::Magenta);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}


Enemy::~Enemy()
{
}

const sf::Vector2f & Enemy::getPos() const
{
	return this->shape.getPosition();
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Enemy::setPos(sf::Vector2f vect)
{
	this->shape.setPosition(vect);
}

void Enemy::update()
{
}

void Enemy::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
