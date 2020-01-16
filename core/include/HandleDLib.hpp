/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#ifndef _TE_HPP
#define _TE_HPP

#include <tuple>
#include "../../games/include/IGame.hpp"
#include "ILibs.hpp"

extern "C" {
    IGame *entryPoint();
    IGame *entryPointPacman();
    ILibs *entryPointSfmlLib(void);
    ILibs *entryPointNcursesLib(void);
}

using ENTRY_POINT_GAME = decltype(&entryPoint);
using ENTRY_POINT_PACMAN = decltype(&entryPointPacman);
using ENTRY_POINT_SFML_LIB = decltype(&entryPointSfmlLib);
using ENTRY_POINT_NCURSES_LIB = decltype(&entryPointNcursesLib);

class HandleDLib
{
public:
    explicit HandleDLib(const char *file = "");
    ~HandleDLib();

    HandleDLib &operator=(const std::string &file);
    ILibs *getSymbolSFML();
    ILibs *getSymbolNcurses();
    IGame *getSymbolSnake();
    IGame *getSymbolPacman();
private:
    void *_lib;
    inline void *openDynLib(const char *file);
    void closeDynLib(void *lib);
    void *searchSymb(void *lib, const char *symbol);
};

#endif
