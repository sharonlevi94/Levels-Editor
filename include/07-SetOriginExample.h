#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

// click on an object changes it (shape - changes color, sprite - rotated, text - add asterisks)
// click on an empty space - creates an object (object selected based on the third of the screen clicked on)

class MyShape_07
{
public:
    MyShape_07(const sf::Vector2f& position);
    bool handleClick(const sf::Vector2f& location);
    void draw(sf::RenderWindow& window) const;

private:
    sf::CircleShape create() const;
    void nextColor();

    sf::Vector2f m_position;
    sf::Color m_color = sf::Color::Green;
};

class MyDraw_07
{
public:
    MyDraw_07(const sf::Vector2f& position, const sf::Texture& texture);
    bool handleClick(const sf::Vector2f& location);
    void draw(sf::RenderWindow& window) const;

private:
    sf::Sprite create() const;

    sf::Vector2f m_position;
    const sf::Texture& m_texture;
    bool m_rotated = false;
};

class MyText_07
{
public:
    MyText_07(const std::string& text, const sf::Vector2f& position, const sf::Font& font);
    bool handleClick(const sf::Vector2f& location);
    void draw(sf::RenderWindow& window) const;

private:
    sf::Text create() const;

    std::string m_text;
    sf::Vector2f m_position;
    const sf::Font& m_font;
};

enum class Object_07
{
    Shape,
    Sprite,
    Text,
};

class Board_07
{
public:
    Board_07();
    bool handleClick(const sf::Vector2f& location);
    void draw(sf::RenderWindow& window) const;

    void addObject(Object_07 objectType, const sf::Vector2f& location);

private:
    std::vector<MyShape_07> m_shapes;
    std::vector<MyDraw_07> m_sprites;
    std::vector<MyText_07> m_texts;

    sf::Texture m_digger;
    sf::Font m_font;

    int m_counter = 0;
};

class SetOriginExample
{
public:
    SetOriginExample();
    void run();

private:
    Object_07 selectedObject(const sf::Vector2f& location) const;

    sf::RenderWindow m_window;
    Board_07 m_board;
};
