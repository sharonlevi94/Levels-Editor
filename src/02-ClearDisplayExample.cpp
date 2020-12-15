#include "02-ClearDisplayExample.h"

#include <SFML/Graphics.hpp>

void clearDisplayExample()
{
    auto window = sf::RenderWindow(sf::VideoMode(500, 500), "Clear()/Display() example");

    while (window.isOpen())
    {
        window.clear();
        window.display();

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
