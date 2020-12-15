#include "05-DrawManyExample.h"

MyShape_05::MyShape_05(const sf::Vector2f& position)
    : m_position(position)
{
}

void MyShape_05::handleClick(const sf::Vector2f& clickLocation)
{
    if (createShape().getGlobalBounds().contains(clickLocation))
    {
        nextColor();
    }

}

void MyShape_05::draw(sf::RenderWindow& window) const
{
    window.draw(createShape());
}

sf::RectangleShape MyShape_05::createShape() const
{
    auto shape = sf::RectangleShape({ 30, 30 });
    shape.setFillColor(m_color);
    shape.setPosition(m_position);
    return shape;
}

void MyShape_05::nextColor()
{
    if (m_color == sf::Color::Red)
    {
        m_color = sf::Color::Yellow;
        return;
    }

    if (m_color == sf::Color::Yellow)
    {
        m_color = sf::Color::Green;
        return;
    }

    // m_color == sf::Color::Green
    m_color = sf::Color::Red;
}

void DrawManyExample::run()
{
    auto window = sf::RenderWindow(sf::VideoMode(800, 400), "Draw many example");

    while (window.isOpen())
    {
        window.clear();
        for (auto i = size_t(0); i < m_shapes.size(); ++i)
        {
            m_shapes[i].draw(window);
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
                    createShape(location);
                    break;
                case sf::Mouse::Button::Right:
                    handleClick(location);
                    break;
                }

                break;
            }
            }
        }
    }
}

void DrawManyExample::createShape(const sf::Vector2f& location)
{
    m_shapes.push_back(MyShape_05(location));
}

void DrawManyExample::handleClick(const sf::Vector2f& location)
{
    for (auto i = size_t(0); i < m_shapes.size(); ++i)
    {
        m_shapes[i].handleClick(location);
    }
}
