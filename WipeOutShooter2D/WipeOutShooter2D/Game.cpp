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

void Game::initBullet()
{

}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::updateVectors()
{
	this->playerCenter = sf::Vector2f(this->player->getPos().x + this->player->getRad(), this->player->getPos().y + this->player->getRad());
	this->mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*this->window));
	this->aimDir = this->mousePosWindow - this->playerCenter;
	this->aimDirNorm = this->aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

}

void Game::updateBullets()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->b1 = new Bullet();
		this->b1->setPos(this->playerCenter);
		this->b1->setDir(this->aimDirNorm * this->b1->getSpeed());

		this->bullets.push_back(b1);
	}
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i]->update();

		if (bullets[i]->getPos().x < 0 || bullets[i]->getPos().x > window->getSize().x
			|| bullets[i]->getPos().y < 0 || bullets[i]->getPos().y > window->getSize().y) {
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Game::updateEnemiesAndCombat() {
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= spawnTimerMax && this->enemyCounter < 5) {
		this->e1 = new Enemy();
		this->e1->setPos(sf::Vector2f(rand()%window->getSize().x, rand() % window->getSize().y));
		this->enemies.push_back(e1);
		this->spawnTimer = 0.f;
		this->enemyCounter++;
	}
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
	this->initBullet();
	this->initEnemies();
}


Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->b1;
	delete this->e1;
	for (auto *i : this->bullets) {
		delete i;
	}
	for (auto *i : this->enemies) {
		delete i;
	}
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

	//bullets and shooting
	this->updateBullets();
	this->updateEnemiesAndCombat();
}

void Game::render()
{
	this->window->clear();
	//draw
	for (auto *bullet : this->bullets) {
		bullet->render(this->window);
	}

	for (auto *enemy : this->enemies) {
		enemy->render(this->window);
	}

	this->player->render(*this->window);
	this->window->display();

}
