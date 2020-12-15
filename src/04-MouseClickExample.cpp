#include "04-MouseClickExample.h"

MouseClickExample::MouseClickExample()
    : m_window(sf::VideoMode(300, 300), "Mouse click example"),
    m_shape(100)
{
    m_shape.setFillColor(sf::Color::Green);
}

void MouseClickExample::run()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.draw(m_shape);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
                handleClick(event.mouseButton);
                break;
            }
        }
    }
}

sf::Color computeNextColor(const sf::Color& color)
{
    if (color == sf::Color::Red)
    {
        return sf::Color::Yellow;
    }

    if (color == sf::Color::Yellow)
    {
        return sf::Color::Green;
    }

    // color == sf::Color::Green
    return sf::Color::Red;

}

void MouseClickExample::handleClick(const sf::Event::MouseButtonEvent& event)
{
    if (m_shape.getGlobalBounds().contains(
        m_window.mapPixelToCoords({ event.x, event.y })))
    {
        m_shape.setFillColor(computeNextColor(m_shape.getFillColor()));
    }
}
