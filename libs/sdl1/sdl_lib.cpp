/*
** EPITECH PROJECT, 2019
** sdl_lib.cpp
** File description:
** 
*/

#include "sdl_lib.hpp"


SDL_Event* mainEvent;

void Update();
void Draw(SDL_Renderer* rR);

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
SDL_SetWindowIcon(window, loadedSurface);
SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
SDL_Surface* loadedSurface = SDL_LoadBMP(fileName.c_str());

SDL_PollEvent(mainEvent);
SDL_RenderClear(rR);

SLD_lib::SDL_lib(void)
{

}

SLD_lib::~SDL_lib(void)
{

}

std::string SDL_lib::&getName()
{

}

bool SDL_lib::createWindow(int horizontal, int vertical, std::string name)
{
    this->_window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, horizontal, vertical, SDL_WINDOW_OPENGL);
    this->rR = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL)
        return(false);
    return(true);
}

bool SDL_lib::closeWindow()
{
    if(!SDL_DestroyWindow(_window) || !SDL_Quit() || SDL_DestroyRenderer(rR))
        return(false);
    return(true);
}

unsigned char SDL_lib::getInputs()
{
    SDL_PollEvent(mainEvent);
    
    if (mainEvent == SDL_QUIT)
        return(Ilibs::EVENT::CLOSE_WINDOW);
    switch (event->key.keysym.scancode) {
    case "z":
        return(ILibs::EVENT::Z);
    case "s": 
        return(ILibs::EVENT::S);
    case "q":
        return(ILibs::EVENT::Q);
    case "d":
        return(ILibs::EVENT::D);
    case "t":
        return(ILibs::EVENT::T);
    case "y":
        return(ILibs::EVENT::Y);
    case "u":
        return(ILibs::EVENT::U);
    case "i":
        return(ILibs::EVENT::I);
    case "o":
        return(ILibs::EVENT::O);
    case "p":
        return(ILibs::EVENT::P);
    case "Space":
        return(ILibs::EVENT::SPACE);
    default
            return(ILibs::EVENT::UNKNOWN);
    }
}


bool SDL_lib::getStatusWindow()
{
    if (this->_window == NULL)
        return(false);
    return(true);
}

bool SDL_lib::Refresh()
{

}

bool SDL_lib::setColor(std::shared_ptr<ILibs::LibData_t> &Data, int hex)
{
    switch(hex){
    case 0xFF2D00: //red
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect( rR, Data->LibObj);
        Data->color = hex;
        return(Data);
    case :0xfff300 : //yellow
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xF3, 0x00, 0xFF);
        SDL_RenderFillRect( rR, Data->LibObj);
        Data->color = hex;
        return(Data);
    case 0x00FF00: //green
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
        SDL_RenderFillRect(rR, Data->LibObj);
        Data->color = hex;
        return(Data);
    case 0x0600bb: //blue
        SDL_SetRenderDrawColor(gRenderer, 0x06, 0x00, 0xBB, 0xFF);
        SDL_RenderFillRect( rR, Data->LibObj);
        Data->color = hex;
        return(Data);
    case 0x000000: //black
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(rR, Data->LibObj);
        Data->color = hex;
        return(Data);
    case 0xFFFFFF: //white
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(rR, Data->LibObj);
        Data->color = hex;
        return(Data);
    default
	return(Data);
    }
    return(Data);

}
        
bool SDL_lib::draw(std::shared_ptr<ILibs::LibData_t> &Data)
{

}
    
bool SDL_lib::drawText(std::shared_ptr<ILibs::LibText_t> &text)
{

}

std::shared_ptr<ILibs::LibData_t> createShape(unsigned char x, unsigned char y, int hex, int shape)
{
    int xpos = (x * 50);
    int ypos = (y * 50);
    
    ILibs::LibData_t lib;
    
    switch(shape) {
    case 0:
        SDL_RenderDrawPoint circle()
        lib->LibObj = circle;
        lib->pos[0] = x;
        lib->pos[1] = y;
        lib->shape = 0;
        return(lib);
    case 1:
        sf::RectangleShape square(50, 50);
        lib->LibObj = square;
        lib->LibObj.setPosition(xpos.f, ypos.f);
        lib->pos[0] = x;
	lib->pos[1] = y;
        lib->shape = 1;
        return(lib);
    case 2:
        SDL_Rect Rect =
            { xpos, ypos, SCREEN_WIDTH, SCREEN_HEIGHT };
        sf::RectangleShape rectangle(50, 25);
        lib->LibObj = rectangle;
	lib->LibObj.setPosition(xpos.f, ypos.f);
        lib->pos[0] = x;
	lib->pos[1] = y;
        lib->shape = 2;
        return(lib);
    case 3:
        sf::CircleShape triangle(50, 3);
        lib->LibObj = triangle;
        lib->LibObj.setPosition(xpos.f, ypos.f);
        lib->pos[0] = x;
        lib->pos[1] = y;
        lib->shape = 3;
        return(lib);
    case 4:
        sf::CircleShape hexagone(50, 6);
        lib->LibObj = hexagone;
        lib->LibObj.setPosition(xpos.f, ypos.f);
        lib->pos[0] = x;
	lib->pos[1] = y;
        lib->shape = 4;
        return(lib);
    case 5:
        sf::CircleShape octogone(50, 8);
        lib->LibObj = octogone;
	lib->LibObj.setPosition(xpos.f, ypos.f);
        lib->pos[0] = x;
	lib->pos[1] = y;
        lib->shape = 5;
        return(lib);
    }
    
}

std::shared_ptr<ILibs::LibText_t> createText(std::string &message, std::string &font, int xpos, int ypos)
{

}
