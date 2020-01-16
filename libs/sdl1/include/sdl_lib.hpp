/*
** EPITECH PROJECT, 2019
** sdl_lib.hpp
** File description:
** 
*/

#ifndef SDL_LIB_HPP
#define SDL_LIB_HPP

#include <ncurses.h>
#include <utility>
#include <unistd.h>
#include <map>
#include <functional>

#include "ILibs.hpp"

class SDL_lib : ILibs
{
public:
    SDL_lib(void);
    ~SDL_lib(void) override;
    std::string &getName() override;
    bool createWindow(int horizontal, int vertical, std::string name) override;
    bool closeWindow() override;
    unsigned char getInputs() override;
    bool getStatusWindow() override;
    bool Refresh() override;
    bool setColor(std::shared_ptr<ILibs::LibData_t> &Data, int hex) override;
    bool draw(std::shared_ptr<ILibs::LibData_t> &Data) override;
    bool drawText(std::shared_ptr<ILibs::LibText_t> &text) override;
    std::shared_ptr<ILibs::LibData_t> createShape(unsigned char x, unsigned char y, int hex, int shape) override;
    std::shared_ptr<ILibs::LibText_t> createText(std::string &message, std::string &font, int xpos, int ypos) override;
private:
    SDL_Window* _window;
    SDL_Renderer* rR;
    SDL_Event* mainEvent;
};


#endif
