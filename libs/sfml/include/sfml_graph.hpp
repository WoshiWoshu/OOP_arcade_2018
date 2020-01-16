/*
** EPITECH PROJECT, 2019
** sfml_graph.hpp
** File description:
**
*/

#ifndef SFML_GRAPH_HPP
#define SFML_GRAPH_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <utility>
#include "ILibs.hpp"

class SFML_Text : public IText
{
public:
    SFML_Text(std::string &font, int x, int y, std::string message);
    ~SFML_Text();
    sf::Text *get_text();
private:
    sf::Text *text;
};

class SFML_Circle : public IShape {
public:
    SFML_Circle(unsigned char x, unsigned char y, int hex, int shape);
    ~SFML_Circle();
    sf::CircleShape *get_shape();
private:
    sf::CircleShape *shape;
};

class SFML_Rect : public IShape
{
public:
    SFML_Rect(unsigned char x, unsigned char y, int hex, int shape);
    ~SFML_Rect();
    sf::RectangleShape *get_shape();

private:
    sf::RectangleShape *shape;
};

class SFML_lib : public ILibs
{
public:
    SFML_lib();
    virtual ~SFML_lib() {}

    bool createWindow(int horizontal, int vertical, std::string name) override;
    bool closeWindow() override;
    unsigned char getInputs() override;
    bool getStatusWindow() const override;
    bool Refresh() override;
    bool Clear() override;
    bool setColor(std::shared_ptr<ILibs::LibData_t> &Data, int hex) override;
    bool draw(std::shared_ptr<ILibs::LibData_t> &Data) override;
    bool drawText(std::shared_ptr<ILibs::LibText_t> &Data) override;
    std::shared_ptr<ILibs::LibData_t> createShape(unsigned char x, unsigned char y, int hex, int shape) override;
    std::shared_ptr<ILibs::LibText_t> createText(std::string &message, std::string font, int xpos, int ypos) override;
    bool setPosition(std::shared_ptr<ILibs::LibData_t> &Data, unsigned char x, unsigned char y) override;
private:
    sf::Font _font;
    sf::RenderWindow _window;
    int hor;
    int vert;
};

// ILibs *entryPointSfmlLib(void)
// {
//     ILibs *sfml = new SFML_lib();

//     return sfml;
// }

#endif
