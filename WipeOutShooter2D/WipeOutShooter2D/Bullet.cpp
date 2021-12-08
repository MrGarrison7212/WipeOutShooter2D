#include "pch.h"
#include "Bullet.h"




Bullet::Bullet()
{
	this->shape.setRadius(5.f);
	this->shape.setFillColor(sf::Color::Red);
	this->direction.x = 0.f;
	this->direction.y = 0.f;
	this->maxSpeed = 5.f;
}

Bullet::Bullet(float dir_X, float dir_Y, float movement_speed)
{
	this->shape.setRadius(5.f);
	this->direction.x = dir_X;
	this->direction.y = dir_Y;
	this->maxSpeed = movement_speed;
}




Bullet::~Bullet()
{
}

const sf::Vector2f & Bullet::getPos() const
{
	return this->shape.getPosition();

}

void Bullet::setPos(sf::Vector2f vect)
{
	this->shape.setPosition(vect);
}

void Bullet::setDir(sf::Vector2f dir)
{
	this->direction = dir;
}

const float Bullet::getSpeed() const
{
	return this->maxSpeed;
}

void Bullet::update()
{
	this->shape.move(this->direction * this->maxSpeed);
}

void Bullet::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
