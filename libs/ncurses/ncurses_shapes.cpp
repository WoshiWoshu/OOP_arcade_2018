/*
** EPITECH PROJECT, 2019
** ncurses_graph.cpp
** File description:
** 
*/

#include "ncurses_graph.hpp"

NCurses_Shape::NCurses_Shape(unsigned char x, unsigned char y, int hex,
                             int _shape) : XPos(x), YPos(y)//, color(hex)
{
    switch(_shape) {
    case 0:
        this->shape = 'O';
        break;
    case 1:
        this->shape = 'X';
        break;
    case 2:
        this->shape = '.';
        break;
    case 3:
        this->shape = '@';
        break;
    case 4:
        this->shape = '*';
	break;
    case 5:
        this->shape = '#';
        break;
    default:
        this->shape = ' ';
        break;
    }
    //if(has_colors() == TRUE) {
    start_color();
    /*  init_pair(1, COLOR_RED, COLOR_BLACK);
         init_pair(2, COLOR_YELLOW, COLOR_BLACK);
         init_pair(3, COLOR_GREEN, COLOR_BLACK);
         init_pair(4, COLOR_BLUE, COLOR_BLACK);
         init_pair(5, COLOR_BLACK, COLOR_BLACK);
         init_pair(6, COLOR_WHITE, COLOR_BLACK);*/
        switch(hex){
        case 0xFF2D00:
            init_pair(1, COLOR_RED, COLOR_BLACK);
            color = 1;
            break;
        case 0xfff300:
            init_pair(2, COLOR_YELLOW, COLOR_BLACK);
            color = 2;
        break;
        case 0x00FF00:
            init_pair(3, COLOR_GREEN, COLOR_BLACK);
            color = 3;
            break;
        case 0x0600bb:
            init_pair(4, COLOR_BLUE, COLOR_BLACK);
            color = 4;
            break;
        case 0x000000:
            init_pair(5, COLOR_BLACK, COLOR_BLACK);
            color = 5;
            break;
        case 0xFFFFFF:
            init_pair(6, COLOR_WHITE, COLOR_BLACK);
            color = 6;
            break;
        default:
            break;
            //}
        }
}

char NCurses_Shape::get_shape()
{
    return(shape);
}
