/*
** EPITECH PROJECT, 2019
** ncurses_graph.cpp
** File description:
** 
*/

#include "ncurses_graph.hpp"

NCurses_Text::NCurses_Text(unsigned char x, unsigned char y, const char *message)
    : XPos(x), YPos(y), text((char*)message)
{
}

char *NCurses_Text::get_text()
{
    return (text);
}
