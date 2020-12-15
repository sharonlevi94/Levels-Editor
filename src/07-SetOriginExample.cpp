#include "07-SetOriginExample.h"

#include <vector>

MyShape_07::MyShape_07(const sf::Vector2f& position)
    : m_position(position)
{
}

bool MyShape_07::handleClick(const sf::Vector2f& location)
{
    if (create().getGlobalBounds().contains(location))
    {
        nextColor();
        return true;
    }

    return false;
}

void MyShape_07::draw(sf::RenderWindow& window) const
{
    window.draw(create());
}

sf::CircleShape MyShape_07::create() const
{
    auto result = sf::CircleShape(100);
    result.setFillColor(m_color);
    result.setOrigin(result.getRadius(), result.getRadius());
    result.setPosition(m_position);
    return result;
}

void MyShape_07::nextColor()

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

MyDraw_07::MyDraw_07(const sf::Vector2f& position, const sf::Texture& texture)
    : m_position(position), m_texture(texture)
{
}

bool MyDraw_07::handleClick(const sf::Vector2f& location)
{
    if (create().getGlobalBounds().contains(location))
    {
        m_rotated = !m_rotated;
        return true;
    }

    return false;
}

void MyDraw_07::draw(sf::RenderWindow& window) const
{
    window.draw(create());
}

sf::Sprite MyDraw_07::create() const
{
    auto result = sf::Sprite(m_texture);
    result.setPosition(m_position);
    result.setRotation(m_rotated ? 90.f : 0.f);
    result.setOrigin(sf::Vector2f(result.getTexture()->getSize() / 2u));
    return result;
}

MyText_07::MyText_07(const std::string& text, const sf::Vector2f& position, const sf::Font& font)
    : m_text(text), m_position(position), m_font(font)
{
}

bool MyText_07::handleClick(const sf::Vector2f& location)
{
    if (create().getGlobalBounds().contains(location))
    {
        m_text = "*" + m_text + "*";
        return true;
    }

    return false;
}

void MyText_07::draw(sf::RenderWindow& window) const
{
    window.draw(create());
}

sf::Text MyText_07::create() const
{
    auto result = sf::Text(m_text, m_font);
    result.setPosition(m_position);
    const auto rect = result.getLocalBounds();
    result.setOrigin(rect.width / 2, rect.height / 2);
    return result;
}

Board_07::Board_07()
{
    m_digger.loadFromFile("digger.png");
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}

bool Board_07::handleClick(const sf::Vector2f& location)
{
    for (auto i = size_t(0); i < m_shapes.size(); ++i)
    {
        if (m_shapes[i].handleClick(location))
        {
            return true;
        }
    }
    for (auto i = size_t(0); i < m_sprites.size(); ++i)
    {
        if (m_sprites[i].handleClick(location))
        {
            return true;
        }
    }
    for (auto i = size_t(0); i < m_texts.size(); ++i)
    {
        if (m_texts[i].handleClick(location))
        {
            return true;
        }
    }

    return false;
}

void Board_07::draw(sf::RenderWindow& window) const
{
    for (auto i = size_t(0); i < m_shapes.size(); ++i)
    {
        m_shapes[i].draw(window);
    }
    for (auto i = size_t(0); i < m_sprites.size(); ++i)
    {
        m_sprites[i].draw(window);
    }
    for (auto i = size_t(0); i < m_texts.size(); ++i)
    {
        m_texts[i].draw(window);
    }
}

void Board_07::addObject(Object_07 objectType, const sf::Vector2f& location)
{
    switch (objectType)
    {
    case Object_07::Shape:
        m_shapes.push_back(MyShape_07(location));
        break;
    case Object_07::Sprite:
        m_sprites.push_back(MyDraw_07(location, m_digger));
        break;
    case Object_07::Text:
        m_texts.push_back(MyText_07(std::to_string(m_counter++), location, m_font));
        break;
    }
}

SetOriginExample::SetOriginExample()
    : m_window(sf::VideoMode(800, 800), "Set origin example")
{
}

void SetOriginExample::run()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_board.draw(m_window);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                if (!m_board.handleClick(location))
                {
                    m_board.addObject(selectedObject(location), location);
                }
                break;
            }
            }
        }
    }
}

// Select object to create based on area of the screen, each third gets its own type of objects
Object_07 SetOriginExample::selectedObject(const sf::Vector2f& location) const
{
    return Object_07(int(location.y / m_window.getSize().y * 3));
}
