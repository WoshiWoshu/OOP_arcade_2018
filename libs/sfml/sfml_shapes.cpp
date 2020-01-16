/*
** EPITECH PROJECT, 2019
** SFML_shapes.cpp
** File description:
**
*/

#include "sfml_graph.hpp"

SFML_Circle::SFML_Circle(unsigned char x, unsigned char y, int hex, int shape)
{
    sf::Color color(hex);

    switch(shape) {
    case 0:
        this->shape = new sf::CircleShape(15);
        break;
    case 3:
        this->shape = new sf::CircleShape(15, 3);
        break;
    case 4:
        this->shape = new sf::CircleShape(15, 6);
        break;
    case 5:
        this->shape = new sf::CircleShape(15, 8);
        break;
    default:
        return;
    }
    this->shape->setPosition(static_cast<float>(x * 30), static_cast<float>(y * 30));
    this->shape->setFillColor(color);
}

SFML_Circle::~SFML_Circle()
{
}

sf::CircleShape *SFML_Circle::get_shape()
{
    return (shape);
}

SFML_Rect::SFML_Rect(unsigned char x, unsigned char y, int hex, int shape)
{
    sf::Color color(hex);
    sf::Vector2f vec(x * 30,y * 30);
    sf::Vector2f size(30,30);
    sf::Vector2f sizeo(30,30);

    switch(shape) {
    case 1:
        this->shape = new sf::RectangleShape(vec);
        this->shape->setSize(size);
        break;
    case 2:
        this->shape = new sf::RectangleShape(vec);
        this->shape->setSize(sizeo);
        break;
    default:
        return;
    }
    this->shape->setPosition((x * 30), (y * 30));
    this->shape->setFillColor(color);
}

SFML_Rect::~SFML_Rect()
{
}

sf::RectangleShape *SFML_Rect::get_shape()
{
    return (shape);
}
