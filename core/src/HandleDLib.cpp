/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <dlfcn.h>
#include <cstdio>
#include <iostream>
#include "HandleDLib.hpp"

HandleDLib::HandleDLib(const char *file) : _lib(nullptr)
{
    if (static_cast<const std::string>(file) != "")
        _lib = openDynLib(file);
}

HandleDLib::~HandleDLib()
{
    closeDynLib(_lib);
}

ILibs *HandleDLib::getSymbolSFML()
{
    ENTRY_POINT_SFML_LIB entryPoint =
    reinterpret_cast<ENTRY_POINT_SFML_LIB>(searchSymb(_lib, "entryPointSfmlLib"));
    return (*entryPoint)();
}

ILibs *HandleDLib::getSymbolNcurses()
{
    ENTRY_POINT_NCURSES_LIB entryPoint =
    reinterpret_cast<ENTRY_POINT_NCURSES_LIB>(searchSymb(_lib, "entryPointNcursesLib"));
    return (*entryPoint)();
}
        
IGame *HandleDLib::getSymbolSnake()
{    
    ENTRY_POINT_GAME entryPoint =
    reinterpret_cast<ENTRY_POINT_GAME>(searchSymb(_lib, "entryPoint"));
    return (*entryPoint)();
}

IGame *HandleDLib::getSymbolPacman()
{    
    ENTRY_POINT_PACMAN entryPoint =
    reinterpret_cast<ENTRY_POINT_PACMAN>(searchSymb(_lib, "entryPointPacman"));
    return (*entryPoint)();
}

HandleDLib &HandleDLib::operator=(const std::string &file)
{
    if (_lib != nullptr)
        closeDynLib(_lib);
    _lib = openDynLib(file.c_str());
    return *this;
}

inline void *HandleDLib::openDynLib(const char *file)
{
    void *lib = dlopen(file, RTLD_LAZY);

    if (!lib) {
        std::cerr << dlerror() << std::endl;
        exit(84);
    }
    return lib;
}

void *HandleDLib::searchSymb(void *lib, const char *symbol)
{
    void *funct = dlsym(lib, symbol);

    if (!funct) {
        std::cerr << dlerror() << std::endl;
        closeDynLib(&lib);
        exit(84);
    }
    return funct;
}

void HandleDLib::closeDynLib(void *lib)
{
    dlclose(&lib);
}
