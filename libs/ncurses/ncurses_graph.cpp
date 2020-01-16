/*
** EPITECH PROJECT, 2019
** ncurses_graph.cpp
** File description:
** 
*/

#include "HandleDLib.hpp"
#include "ncurses_graph.hpp"

ILibs *entryPointNcursesLib(void)
{
    ILibs *ncurses = new NCurses_lib();

    return ncurses;
}

// IShape *entryPointNcursesRect(unsigned char x, unsigned char y, int hex, int shape)
// {
//     IShape *sfml = new SFML_Rect(x, y, hex, shape);

//     return sfml;
// }

// IShape *entryPointNcursesCircle(unsigned char x, unsigned char y, int hex, int shape)
// {
//     IShape *sfml = new SFML_Circle(x, y, hex, shape);

//     return sfml;
// }

// IText *entryPointNcursesText(std::string &font, int x, int y, std::string message)
// {
//     IText *sfml = new SFML_Text(font, x, y, message);

//     return sfml;
// }

NCurses_lib::NCurses_lib(void)
{
    this->_isOpen = false;
    //noecho();
    nodelay(stdscr, true);
    //curs_set(false);
}

bool NCurses_lib::createWindow(int horizontal, int vertical, std::string name)
{
    std::string strtmp = name;
    int tmp = horizontal;
    
    tmp = vertical;
    tmp = tmp;
    initscr();
    win = newwin(33, 33, 1, 1);
    noecho();
    cbreak();
    curs_set(false);
    start_color();                                                                                       
    /*   init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);*/
    if (!stdscr)
        return (false);
    this->_isOpen = true;
    return (true);
}

bool NCurses_lib::closeWindow()
{
    // clrtobot();
    //clear();
    //delwin(win);
    endwin();
    delwin(win);
    /*if (stdscr)
      return (false);*/
    this->_isOpen = false;
    return (true);
}

unsigned char NCurses_lib::getInputs()
{
    char event = 0;
    timeout(100);
    event = getch();
    switch (event) {
    case 'z':
        return(ILibs::EVENT::Z);
    case 's':
        return(ILibs::EVENT::S);
    case 'q':
        return(ILibs::EVENT::Q);
    case 'd':
        return(ILibs::EVENT::D);
    case 't':
        return(ILibs::EVENT::T);
    case 'y':
        return(ILibs::EVENT::Y);
    case'u':
        return(ILibs::EVENT::U);
    case'i':
        return(ILibs::EVENT::I);
    case'o':
        return(ILibs::EVENT::O);
    case'p':
        return(ILibs::EVENT::P);
    case ' ':
        return(ILibs::EVENT::SPACE);
    default:
        return(ILibs::EVENT::UNKNOWN);
    }
}

bool NCurses_lib::getStatusWindow() const
{
    return(this->_isOpen);
}

bool NCurses_lib::Clear()
{
    //clrtobot();
    wclear(win);
    return(true);
    /*if (!clear())
        return(false);
        return(true);*/        
}

bool NCurses_lib::Refresh()
{
    wrefresh(win);
    return(true);
    /*if (!refresh())
        return(false);
        return(true);*/
}

bool NCurses_lib::setColor(std::shared_ptr<ILibs::LibData_t> &Data, int hex)
{
    /*if(has_colors() == FALSE)
        return(false);
        //start_color();*/
    switch(hex){
    case 0xFF2D00:
        //attron(COLOR_PAIR(1));
//init_pair(1, COLOR_RED, COLOR_BLACK);
        //Data->LibObj->color = 1;
        Data->Color = hex;
        break;
    case 0xfff300:
        //attron(COLOR_PAIR(2));
//init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        //      Data->LibObj->color = 2;
        Data->Color = hex;
        break;
    case 0x00FF00:
        //attron(COLOR_PAIR(3));
        //init_pair(3, COLOR_GREEN, COLOR_BLACK);
//	Data->Color = 3;
        Data->Color = hex;
        break;
    case 0x0600bb:
        //attron(COLOR_PAIR(4));
//init_pair(5, COLOR_BLUE, COLOR_BLACK);
//	Data->LibObj->color = 4;
        Data->Color = hex;
        break;
    case 0x000000:
        //attron(COLOR_PAIR(5));
        //init_pair(5, COLOR_BLACK, COLOR_BLACK);
        //      Data->Color = 5;
        Data->Color = hex;
        break;
    case 0xFFFFFF:
        //attron(COLOR_PAIR(6));
        //init_pair(6, COLOR_WHITE, COLOR_BLACK);
//	Data->LibObj->color = 6;
        Data->Color = hex;
        break;
    default:
        break;
    }
    return(true);
}
    
bool NCurses_lib::draw(std::shared_ptr<ILibs::LibData_t> &Data)
{
    NCurses_Shape *item = reinterpret_cast<NCurses_Shape*>(Data->LibObj);
    char shape[2];
    
    shape[0] = item->get_shape();
    shape[1] = '\0';
    if (Data == nullptr)
        return (false);
    //set_color(Data, Data->Color);
//    wattron(win, COLOR_PAIR(Data->Color));
//attron(COLOR_PAIR(Data->Color));
    mvwprintw(win, Data->Pos[1], Data->Pos[0], static_cast<const char*>(shape));
    //twattroff(win, COLOR_PAIR(Data->Color));
    return (true);
}

bool NCurses_lib::drawText(std::shared_ptr<ILibs::LibText_t> &LibTex)
{
    char *demo;
    NCurses_Text *texto = reinterpret_cast<NCurses_Text*>(LibTex->text);
    
    if (LibTex == nullptr)
        return (false);
    demo = texto->get_text();
    mvprintw(LibTex->Pos[1], LibTex->Pos[0], demo);
    return (true);
}

std::shared_ptr<ILibs::LibData_t> NCurses_lib::createShape(unsigned char x, unsigned char y, int hex, int shape)
{
    unsigned char Ushape = static_cast<unsigned char>(shape);
    std::shared_ptr<ILibs::LibData_t> libShape(new ILibs::LibData_t({ {x, y}, static_cast<unsigned char>(hex), Ushape, new NCurses_Shape(x, y, hex, shape)}));
return (libShape);
}

std::shared_ptr<ILibs::LibText_t> NCurses_lib::createText(std::string &message, std::string font, int xpos, int ypos)
{
    static_cast<void>(font);
    std::shared_ptr<ILibs::LibText_t> lib_text(new ILibs::LibText_t({ {(unsigned char)xpos, (unsigned char)ypos}, new NCurses_Text((unsigned char)xpos, (unsigned char)ypos, message.c_str())}));

    return(lib_text);
}

bool NCurses_lib:: setPosition(std::shared_ptr<ILibs::LibData_t> &Data, unsigned char x, unsigned char y)
{
    NCurses_Shape *Shape = reinterpret_cast<NCurses_Shape*>(Data->LibObj);
    char shapeo[2];

    Data->Pos[0] = x;
    Data->Pos[1] = y;
    shapeo[0] = Shape->get_shape();
    shapeo[1] = '\0';
    mvprintw(y, x, shapeo);
    return(true);

}
