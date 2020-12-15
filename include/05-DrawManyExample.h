#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

// Adding _05 to make sure it doesn't collide with similar classes in other examples.
// Instead of saving the shape directly, we save only the ingredients to create it,
// following the instructions for ex04
class MyShape_05
{
public:
    MyShape_05(const sf::Vector2f& position);
    void handleClick(const sf::Vector2f& clickLocation);
    void draw(sf::RenderWindow& window) const;

private:
    sf::RectangleShape createShape() const;
    void nextColor();

    sf::Vector2f m_position;
    sf::Color m_color = sf::Color::Green;
};
//==================================================================================
class DrawManyExample
{
public:
    void run();

private:
    void createShape(const sf::Vector2f& location);
    void handleClick(const sf::Vector2f& location);

    std::vector<MyShape_05> m_shapes;
};
