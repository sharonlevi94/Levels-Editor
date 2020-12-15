#include "03-DrawExample.h"

#include <SFML/Graphics.hpp>

void drawExample()
{
    auto window = sf::RenderWindow(sf::VideoMode(200, 200), "Draw() example");
    int width=100, height=100;
    //auto circle = sf::CircleShape(100);
    
    auto rectangle = sf::RectangleShape(sf::Vector2f(width,height));
    rectangle.setFillColor(sf::Color::Blue);
    
    while (window.isOpen())
    {
        window.clear();
        auto event = sf::Event{};
        while (window.waitEvent(event) ) {
            window.draw(rectangle);
            window.display();
               
            
                auto rectangle = sf::RectangleShape(sf::Vector2f(width, height));
        }
    }
}
