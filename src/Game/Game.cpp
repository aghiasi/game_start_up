#include <iostream>
#include "Game.hpp"
#include <string.h>
Game::Game(unsigned int x, unsigned int y, std::string str)
{
  this->initVariables();
  this->initWindow(x, y, str);
  this->initEnemy();
}
Game::~Game()
{
  delete this->window;
}
void Game::initVariables()
{
  this->window = nullptr;
  this->points = 0;
  this->enemySpawnTimer = 0.f;
  this->enemySpawnTimerMax = 3000.f;
  this->maxEnemies = 5;
}
void Game::initWindow(unsigned int x, unsigned int y, std::string str)
{
  this->window = new sf::RenderWindow(sf::VideoMode({x, y}), str, sf::Style::Titlebar | sf::Style::Close);
}
void Game::initEnemy()
{
  this->enemy.setPosition(sf::Vector2(0.f, 0.f));
  this->enemy.setSize(sf::Vector2f(50.f, 50.f));
  this->enemy.setFillColor(sf::Color::Cyan);
  this->enemy.setOutlineColor(sf::Color::Green);
  this->enemy.setOutlineThickness(1.f);
}
void Game::run()
{
  while (window->isOpen())
  {
    this->processEvents();
    this->update();
    this->render();
  }
}
void Game::processEvents()
{
  while (const auto event = window->pollEvent())
  {
    if (event->is<sf::Event::Closed>())
      this->window->close();
    if (const auto *key = event->getIf<sf::Event::KeyPressed>())
      switch (key->code)
      {
      case sf::Keyboard::Key::D:
        move += 1.f;
        break;
      case sf::Keyboard::Key::A:
        move -= 1.f;
      default:
        break;
      }
  }
}
void Game::update()
{
  this->updateMousePosition();
  this->updateEnemy();
}
void Game::updateEnemy()
{
  if (this->enemeis.size() < this->maxEnemies)
  {
    if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
    {
      this->spawnEnemy();
      this->enemySpawnTimer = 0.f;
    }
    else
      this->enemySpawnTimer += 1.f;
  }
  for (int i = 0; i < this->enemeis.size(); i++)
  {
    bool del = false;
    this->enemeis[i].move(sf::Vector2f(0.f, 0.09f));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
      if (this->enemeis[i].getGlobalBounds().contains(this->mouseView))
      {
        this->enemeis[i].setFillColor(sf::Color::Green);
      }
    if (this->enemeis[i].getPosition().y >= this->window->getSize().y)
    {
      std::cout << "in the delete enemy \n";
      this->enemeis.erase(this->enemeis.begin() + i);
      i--;
      continue;
    }
  }
}
void Game::spawnEnemy()
{
  this->initEnemy();
  this->enemy.setPosition(sf::Vector2f(
      static_cast<float>(rand() % (static_cast<int>(this->window->getPosition().x - this->enemy.getPosition().x))), 0.f));
  this->enemeis.push_back(this->enemy);
}
void Game::renderEnemy()
{
  for (auto &e : this->enemeis)
  {
    this->window->draw(e);
  }
}
void Game::render()
{
  window->clear();
  this->renderEnemy();
  window->display();
}
void Game::updateMousePosition()
{
  this->mousePosition = sf::Mouse::getPosition(*this->window);
  this->mouseView = this->window->mapPixelToCoords(this->mousePosition);
}
