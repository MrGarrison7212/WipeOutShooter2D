#include "pch.h"
#include "Player.h"


void Player::initCircleShape()
{
	this->shape.setRadius(25.f);
	this->shape.setFillColor(sf::Color::White);
}

Player::Player()
{
	this->movementSpeed = 5.f;
	this->initCircleShape();
}


Player::~Player()
{
}

const sf::Vector2f & Player::getPos() const
{
	return this->shape.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const float Player::getRad() const
{
	return this->shape.getRadius();
}



void Player::move(const float dirX, const float dirY)
{
	this->shape.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(this->shape);
}
