#include "pch.h"
#include "Bullet.h"




Bullet::Bullet()
{
}

Bullet::Bullet(float radius, float dir_X, float dir_Y, float movement_speed)
{
	this->shape.setRadius(radius);
	this->direction.x = dir_X;
	this->direction.y = dir_Y;
	this->maxSpeed = movement_speed;
}


Bullet::~Bullet()
{
}

void Bullet::update()
{
}

void Bullet::render(sf::RenderTarget * target)
{
}
