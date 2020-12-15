#include "06-TextureAndFontExample.h"

#include <SFML/Graphics.hpp>
#include <vector>

void textureAndFontExample()
{
    auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Texture and Font example");

    auto digger = sf::Texture();
    digger.loadFromFile("digger.png");

    auto font = sf::Font();
    font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

    std::vector<sf::Sprite> m_sprites;
    std::vector<sf::Text> m_texts;

    while (window.isOpen())
    {
        window.clear();
        for (auto i = size_t(0); i < m_sprites.size(); ++i)
        {
            window.draw(m_sprites[i]);
        }
        for (auto i = size_t(0); i < m_texts.size(); ++i)
        {
            window.draw(m_texts[i]);
        }
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
            {
                auto location = window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left:
                {
                    auto sprite = sf::Sprite(digger);
                    sprite.setPosition(location);
                    m_sprites.push_back(sprite);
                    break;
                }
                case sf::Mouse::Button::Right:
                {
                    auto text = sf::Text(std::to_string(m_texts.size()), font);
                    text.setPosition(location);
                    m_texts.push_back(text);
                    break;
                }
                }

                break;
            }
            }
        }
    }
}
