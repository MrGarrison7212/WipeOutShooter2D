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
