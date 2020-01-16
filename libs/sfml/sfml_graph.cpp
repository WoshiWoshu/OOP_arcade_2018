/*
** EPITECH PROJECT, 2019
** sfml_graph.cpp
** File description:
**
*/

#include "HandleDLib.hpp"
#include "sfml_graph.hpp"

ILibs *entryPointSfmlLib(void)
{
    ILibs *sfml = new SFML_lib();

    return sfml;
}

// IShape *entryPointSfmlRect(unsigned char x, unsigned char y, int hex, int shape)
// {
//     IShape *sfml = new SFML_Rect(x, y, hex, shape);

//     return sfml;
// }

// IShape *entryPointSfmlCircle(unsigned char x, unsigned char y, int hex, int shape)
// {
//     IShape *sfml = new SFML_Circle(x, y, hex, shape);

//     return sfml;
// }

// IText *entryPointSfmlText(std::string &font, int x, int y, std::string message)
// {
//     IText *sfml = new SFML_Text(font, x, y, message);

//     return sfml;
// }

SFML_lib::SFML_lib() :
	_font(), _window()
{
    if (!_font.loadFromFile("rsrc/ttf/font.ttf"))
         std::cerr << "Error: unable to load font.tff" << std::endl;
}

bool SFML_lib::createWindow(int horizontal, int vertical, std::string name)
{
    this->_window.create(sf::VideoMode(horizontal, vertical), name, sf::Style::Close | sf::Style::Titlebar);
    this->_window.setFramerateLimit(20);
    this->_window.setVerticalSyncEnabled(true);
    this->_window.setMouseCursorVisible(false);
    this->hor = horizontal;
    this->vert = vertical;
    return(true);
}

bool SFML_lib::closeWindow()
{
    this->_window.close();
    return(true);
}

unsigned char SFML_lib::getInputs()
{
    sf::Event event;

    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            return(ILibs::EVENT::CLOSE_WINDOW);
        if (event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
            case sf::Keyboard::Z :
                return(ILibs::EVENT::Z);
            case sf::Keyboard::S :
                return(ILibs::EVENT::S);
            case sf::Keyboard::D :
                return(ILibs::EVENT::D);
            case sf::Keyboard::Q :
                return(ILibs::EVENT::Q);
            case sf::Keyboard::T:
                return(ILibs::EVENT::T);
            case sf::Keyboard::Y :
                return(ILibs::EVENT::Y);
            case sf::Keyboard::U :
                return(ILibs::EVENT::U);
            case sf::Keyboard::I :
                return(ILibs::EVENT::I);
            case sf::Keyboard::O :
                return(ILibs::EVENT::O);
            case sf::Keyboard::P :
                return(ILibs::EVENT::P);
            case sf::Keyboard::Space :
                return(ILibs::EVENT::SPACE);
            default :
                return(ILibs::EVENT::UNKNOWN);
            }
        }

  }
  return(ILibs::EVENT::UNKNOWN);
}

bool SFML_lib::getStatusWindow() const
{
    return(this->_window.isOpen());
}

bool SFML_lib::Refresh()
{
    this->_window.display();

    return(true);
}

bool SFML_lib::Clear()
{
    const sf::Color &color = sf::Color(0, 0, 0, 255);
    this->_window.clear(color);
    return(true);
}

bool SFML_lib::setPosition(std::shared_ptr<ILibs::LibData_t> &Data, unsigned char x, unsigned char y)
{
    if (Data->Shape == 1 || Data->Shape == 2) {
        SFML_Rect *circle = reinterpret_cast<SFML_Rect*>(Data->LibObj);
        sf::RectangleShape *rec;
        rec = circle->get_shape();
        Data->Pos[0] = x;
        Data->Pos[1] = y;
        rec->setPosition(((float)x*30), ((float)y*30));
        return(true);
    }
    else {
        SFML_Circle *circle = reinterpret_cast<SFML_Circle*>(Data->LibObj);
        sf::CircleShape *rec;
        rec = circle->get_shape();
        rec->setPosition(((float)x*30), ((float)y*30));
        Data->Pos[0] = x;
        Data->Pos[1] = y;
        return(true);
    }
    return(false);
}


bool SFML_lib::setColor(std::shared_ptr<ILibs::LibData_t> &Data, int hex)
{
    if (Data->Shape == 0 || Data->Shape == 1) {
        SFML_Rect *circle = reinterpret_cast<SFML_Rect*>(Data->LibObj);
        sf::RectangleShape *cir;

        switch(hex){
        case 0xFF2D00:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Red);
            Data->Color = static_cast<unsigned char>(hex);
            return true;
        case 0xfff300:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Yellow);
            Data->Color = static_cast<unsigned char>(hex);
            return true;
        case 0x00FF00:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Green);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        case 0x0600bb:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Blue);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        case 0x000000:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Black);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        case 0xFFFFFF:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::White);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        default:
            return(false);
        }
        return false;
    } else {
        SFML_Circle *circle = reinterpret_cast<SFML_Circle*>(Data->LibObj);
        sf::CircleShape *cir;

        switch(hex){
        case 0xFF2D00:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Red);
            Data->Color = static_cast<unsigned char>(hex);
            return true;
        case 0xfff300:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Yellow);
            Data->Color = static_cast<unsigned char>(hex);
            return true;
        case 0x00FF00:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Green);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        case 0x0600bb:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Blue);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        case 0x000000:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::Black);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        case 0xFFFFFF:
            cir = circle->get_shape();
            cir->setFillColor(sf::Color::White);
            Data->Color = static_cast<unsigned char>(hex);
            return(true);
        default:
            return(false);
        }
        return false;
    }
}

bool SFML_lib::draw(std::shared_ptr<ILibs::LibData_t> &Data)
{
    if (Data->Shape == 0 || Data->Shape == 1) {
        SFML_Rect *circle = reinterpret_cast<SFML_Rect*>(Data->LibObj);
        sf::RectangleShape *cir;
        cir = circle->get_shape();
        _window.draw(*cir);
        return(true);
    }
    else {
        SFML_Circle *circle = reinterpret_cast<SFML_Circle*>(Data->LibObj);
        sf::CircleShape *cir;
        cir = circle->get_shape();
        _window.draw(*cir);
        return(true);
    }
    return(false);
}

bool SFML_lib::drawText(std::shared_ptr<ILibs::LibText_t> &Data)
{
    sf::Text *demo;
    SFML_Text *texto = reinterpret_cast<SFML_Text*>(Data->text);

    demo = texto->get_text();
    _window.draw(*demo);

    return(true);
}

std::shared_ptr<ILibs::LibData_t> SFML_lib::createShape(unsigned char x, unsigned char y, int hex, int shape)
{
    //int xpos = (x * 10);
    //int ypos = (y * 10);

    unsigned char Ushape = static_cast<unsigned char>(shape);
    std::shared_ptr<ILibs::LibData_t> libCircle(new ILibs::LibData_t({ {x, y}, static_cast<unsigned char>(hex), Ushape, new SFML_Circle(x, y, hex, shape)}));
    std::shared_ptr<ILibs::LibData_t> libRect(new ILibs::LibData_t({ {x, y}, static_cast<unsigned char>(hex), Ushape, new SFML_Rect(x, y, hex, shape)}));

    switch(shape){
    case 0:
        return(libCircle);
    case 1:
        return(libRect);
    case 2:
        return(libRect);
    case 3:
        return(libCircle);
    case 4:
        return(libCircle);
    case 5:
        return(libCircle);
    default:
        return nullptr;
    }
}

std::shared_ptr<ILibs::LibText_t> SFML_lib::createText(std::string &message, std::string font, int xpos, int ypos)
{
    int x = xpos * 30;
    int y = ypos * 30;
    sf::Font g_font;

        if(!g_font.loadFromFile(font))
        abort();
    std::shared_ptr<ILibs::LibText_t> lib_text(new ILibs::LibText_t({ {(unsigned char)x, (unsigned char)y}, new SFML_Text(font, xpos, ypos, message)}));

    return(lib_text);
}
