/*
** EPITECH PROJECT, 2019
** sfml_text.cpp
** File description:
** 
*/

#include "sfml_graph.hpp"

SFML_Text::SFML_Text(std::string &font, int x, int y, std::string message)
{
    sf::Font Ffont;

    Ffont.loadFromFile(font);
    this->text->setString(message);
    this->text->setFont(Ffont);
    this->text->setPosition(x, y);
}

SFML_Text::~SFML_Text()
{
}

sf::Text* SFML_Text::get_text()
{
    return(text);
}
