#include "pch.h"
#include "Game.h"


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "WipeOut works !", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
	this->initWindow();
}


Game::~Game()
{
	delete this->window;
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}

void Game::update()
{
	sf::Event e;
	while (this->window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::render()
{
	this->window->clear();
	this->window->display();
}
