#include "03-DrawExample.h"

#include <SFML/Graphics.hpp>

void drawExample()
{
    auto window = sf::RenderWindow(sf::VideoMode(1000, 600), "Draw() example");
    int width=300, height=300;
    //auto circle = sf::CircleShape(100);
    
    auto rectangle = sf::RectangleShape(sf::Vector2f(width,height));
    rectangle.setFillColor(sf::Color::Yellow);
    rectangle.setPosition(width/2, height/2);
    
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
