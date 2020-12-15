#include "01-CloseEventExample.h"

#include <SFML/Graphics.hpp>

void closeEventExample()
{
    auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Close event example");

    while (window.isOpen())
    {
        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
            
        }
    }
}
