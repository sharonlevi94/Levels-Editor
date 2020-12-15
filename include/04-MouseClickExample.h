#pragma once

#include <SFML/Graphics.hpp>

class MouseClickExample
{
public:
    MouseClickExample();
    void run();

private:
    void handleClick(const sf::Event::MouseButtonEvent& event);

    sf::RenderWindow m_window;
    sf::CircleShape m_shape;
};
