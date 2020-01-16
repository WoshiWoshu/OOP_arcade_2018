/*
** EPITECH PROJECT, 2019
** Menu.hpp
** File description:
** Menu for arcade
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "HandleDLib.hpp"

enum class COLORHEX {
    RED = 0xFF2D00, BLUE = 0x0600bb, YELLOW = 0xfff300,
    BLACK = 0x000000, WHITE = 0xFFFFFF, GREEN = 0x00FF00
};

typedef struct DataText_s {
    unsigned char XPos;
    unsigned char YPos;
    std::string Text;
    COLORHEX COLOR;
} DataText_t;

int core(HandleDLib &dynLib, std::string &libParam,
    const std::string &action, bool &enterName, int &score);

#endif
