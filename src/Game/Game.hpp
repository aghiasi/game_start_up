#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#include <ctime>
#ifndef GAME_H
#define GAME_H
// Class for Game engine
class Game
{
  std::vector<sf::RectangleShape> enemeis;
  sf::RectangleShape enemy;
  sf::RenderWindow *window;
  sf::Vector2i mousePosition;
  sf::Vector2f mouseView;
  float enemySpawnTimer;
  float enemySpawnTimerMax;
  int maxEnemies;
  int points;
  float move = 10.f;
  void processEvents();
  void update();
  void render();
  void initVariables();
  void initWindow(unsigned int, unsigned int, std::string);
  void initEnemy();
  void updateMousePosition();
  void spawnEnemy();
  void renderEnemy();
  void updateEnemy();

public:
  // consturctors / destructors
  Game(unsigned int, unsigned int, std::string);
  ~Game();
  void run();
};
#endif
