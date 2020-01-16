/*
** EPITECH PROJECT, 2019
** Ilibs.hpp
** File description:
** 
*/

#ifndef ILIBS_HPP
#define ILIBS_HPP

#include <memory>
#include <iostream>
#include <string>
#include "IShape.hpp"
#include "IText.hpp"

class ILibs
{
public:
    virtual ~ILibs() {};
    
    typedef struct LibData_s {
        std::array<unsigned char, 2> Pos;
        unsigned char Color;
        unsigned char Shape;
        IShape *LibObj;
    } LibData_t;
    
    typedef struct LibText_s {
        std::array<unsigned char, 2> Pos;
        IText *text;
    } LibText_t;
    
    enum EVENT {
            UNKNOWN, CLOSE_WINDOW, Z, Q, S, D, T, Y, U, I, O, P, SPACE
        };
    enum SHAPE {
        CIRCLE, SQUARE, RECTANGLE, TRIANGLE, STAR, ELLIPSEF
    };

    virtual bool Clear() = 0;
    virtual bool createWindow(int horizontal, int vertical, std::string name) = 0;
    virtual bool closeWindow() = 0;
    virtual unsigned char getInputs() = 0;
    virtual bool getStatusWindow() const = 0;
    virtual std::shared_ptr<ILibs::LibData_t> createShape(unsigned char x, unsigned char y, int hex, int shape) = 0;
    
    virtual bool Refresh() = 0;
    virtual bool setPosition(std::shared_ptr<ILibs::LibData_t> &Data, unsigned char x, unsigned char y) = 0;
    virtual bool setColor(std::shared_ptr<ILibs::LibData_t> &Data, int hex) = 0;
    virtual bool draw(std::shared_ptr<ILibs::LibData_t> &Data) = 0;
    
    virtual std::shared_ptr<ILibs::LibText_t> createText(std::string &message, std::string font, int xpos, int ypos) = 0;
    virtual bool drawText(std::shared_ptr<ILibs::LibText_t> &text) = 0;
};

#endif
