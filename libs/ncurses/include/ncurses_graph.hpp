/*
** EPITECH PROJECT, 2019
** ncurses_graph.hpp
** File description:
** 
*/

#ifndef NCUSRSES_GRAPH_HPP
#define NCURSES_GRAPH_HPP

#include <ncurses.h>
#include <utility>
#include <unistd.h>
#include <map>
#include <functional>

#include "ILibs.hpp"

class NCurses_Text : public IText
{
public:
    NCurses_Text(unsigned char x, unsigned char y, const char *message);
    ~NCurses_Text() {};
    char *get_text();
private:
    unsigned char XPos;
    unsigned char YPos;
    char *text;
};

class NCurses_Shape : public IShape {
public:
    NCurses_Shape(unsigned char x, unsigned char y, int hex, int _shape);
    ~NCurses_Shape() {};
    char get_shape();
private:
    unsigned char XPos;
    unsigned char YPos;
    int color;
    char shape;
};

class NCurses_lib : public ILibs
{
public:
    NCurses_lib();
    virtual ~NCurses_lib() {}
    
    bool createWindow(int horizontal, int vertical, std::string name) override;
    bool closeWindow() override;
    unsigned char getInputs() override;
    bool getStatusWindow() const override;
    bool Refresh() override;
    bool Clear() override;
    bool setColor(std::shared_ptr<ILibs::LibData_t> &Data, int hex) override;
    bool draw(std::shared_ptr<ILibs::LibData_t> &Data) override;
    bool drawText(std::shared_ptr<ILibs::LibText_t> &text) override;
    bool setPosition(std::shared_ptr<ILibs::LibData_t> &Data, unsigned char x, unsigned char y) override;
    std::shared_ptr<ILibs::LibData_t> createShape(unsigned char x, unsigned char y, int hex, int shape) override;
    std::shared_ptr<ILibs::LibText_t> createText(std::string &message, std::string font, int xpos, int ypos) override;
private:
    int _max;
    int _size;
    std::string _chars;
    bool _isOpen;
    WINDOW *win;
};


#endif
