#include "pch.h"
#include "Game.h"


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "WipeOut works !", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::updateVectors()
{
	this->playerCenter = sf::Vector2f(this->player->getPos().x + this->player->getRad(), this->player->getPos().y + this->player->getRad());
	this->mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*this->window));
	this->aimDir = this->mousePosWindow - this->playerCenter;
	this->aimDirNorm = this->aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.x, 2));

}

void Game::updateBullets()
{
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}


Game::~Game()
{
	delete this->window;
	delete this->player;
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
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
			this->window->close();
		}
	}

	//update vectors
	this->updateVectors();
	std::cout << this->aimDirNorm.x << " " << this->aimDirNorm.y << "\n";


	// move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		this->player->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->player->move(0.f, 1.f);
	}
}

void Game::render()
{
	this->window->clear();
	//draw
	this->player->render(*this->window);
	this->window->display();

}
