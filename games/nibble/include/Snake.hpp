/*
** EPITECH PROJECT, 2019
** Snake.hpp
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <stdlib.h>
#include <ctime>
#include <vector>
#include "IGame.hpp"

class Snake : public IGame
{
public:
    Snake();
    ~Snake() {};

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE,
    };
    int getWidth();
    int getHeight();
    int getSnakeSize();
    int getDirection();

    void snakeReset(int &Score);
    unsigned char keyEvent(unsigned char KeyPressed);
    void setNextDirection(Direction new_direction);

    int snakeGrow();
    void snakeMove();
    bool snakeBlock();

    std::vector<std::shared_ptr<IGame::DataElem_t>>
    &RetriveDataElem() override;
    std::vector<std::shared_ptr<IGame::DataMap_t>> &RetriveDataMap() override;
    void LoadData() override;
    void LoadMap() override;
    void UpdateData(unsigned char KeyPressed, int &Score,
                    bool &GameOver) override;

    std::vector<IGame::DataElem_t> _corps;
    IGame::DataElem_t _fruit;
    std::vector<IGame::DataMap_t> _wall;

    std::vector<std::shared_ptr<IGame::DataElem_t>> ElemBox;
    std::vector<std::shared_ptr<IGame::DataMap_t>> MapBox;

private:
    int _width;
    int _height;
    unsigned char _life;
    int _hiscore;
    unsigned int _snakeSize;
    Direction _nextDirection;
    Direction _lastDirection;
    std::clock_t timeStart;
    double timeNow;
};

#endif
