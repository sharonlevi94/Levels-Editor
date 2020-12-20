#pragma once
//============================ include section ===============================
#include <fstream> // for string
#include <SFML/Graphics.hpp>
//=========================== prototypes section =============================
void terminate(const std::string);
bool isInRec(const sf::Vector2f&, const sf::Vector2f&, const sf::Vector2f&);