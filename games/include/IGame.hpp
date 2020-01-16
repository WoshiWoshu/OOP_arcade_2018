/*
** EPITECH PROJECT, 2019
** arcade hpp
** File description:
** IGAME
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_
 
#include <vector>
#include <memory>
 
class IGame
{
public:
    IGame() {};
    ~IGame() {};

    enum class COLORHEX {
        RED = 0xFF2D00, BLUE = 0x0600bb, YELLOW = 0xfff300,
        BLACK = 0x000000, WHITE = 0xFFFFFF, GREEN = 0x00FF00
    };
    enum class SHAPE {
        CIRCLE, SQUARE, RECTANGLE, TRIANGLE, STAR, ELLIPSE
    };
    typedef struct DataElem_s {
        unsigned char XPos;
        unsigned char YPos;
        std::string Name;
        IGame::COLORHEX COLOR;
        IGame::SHAPE FORM;
    } DataElem_t;
    
    typedef struct DataMap_s {
        unsigned char XPos;
        unsigned char YPos;
        IGame::COLORHEX COLOR;
        IGame::SHAPE FORM;
    } DataMap_t;
    
    virtual std::vector<std::shared_ptr<DataElem_t>> &RetriveDataElem() = 0;
    virtual std::vector<std::shared_ptr<DataMap_t>> &RetriveDataMap() = 0;
    virtual void LoadData() = 0;
    virtual void LoadMap() = 0;
    virtual void UpdateData(unsigned char KeyPressed, int &Score,
                            bool &GameOver) = 0;
protected:
private:
};
 
#endif /* !IGAME_HPP_ */
