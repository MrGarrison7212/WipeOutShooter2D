#include "pch.h"
#include "Player.h"


void Player::initCircleShape()
{
	this->shape.setRadius(25.f);
	this->shape.setFillColor(sf::Color::White);
}

Player::Player()
{
	this->initCircleShape();
}


Player::~Player()
{
}

void Player::update()
{
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(this->shape);
}
