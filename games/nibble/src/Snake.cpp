/*
** EPITECH PROJECT, 2019
** Snake.cpp
** File description:
** Snake
*/

#include <memory>
#include "Snake.hpp"
#include "HandleDLib.hpp"

IGame *entryPoint()
{
    IGame *game = new Snake();

    return game;
}

Snake::Snake()
{
    std::vector<IGame::DataElem_t> corps(4);
    std::vector<IGame::DataMap_t> wall(124);
    int index = 0;
    int x = 0;
    int y = 0;

    _width = 30;
    _height = 30;
    _life = 3;
    _hiscore = 0;
    while (index < 4) {
        if (index == 0) {
            corps[index].COLOR = IGame::COLORHEX::RED;
            corps[index].FORM = IGame::SHAPE::SQUARE;
            corps[index].Name = "head";
        } else {
            corps[index].COLOR = IGame::COLORHEX::GREEN;
            corps[index].FORM = IGame::SHAPE::SQUARE;
            corps[index].Name = "corps";
        }
        ++index;
    }
    _corps = corps;
    _fruit.COLOR = IGame::COLORHEX::YELLOW;
    _fruit.FORM = IGame::SHAPE::CIRCLE;
    _fruit.Name = "fruit";
    index = 0;
    while (index < 124) {
        wall[index].XPos = x;
        wall[index].YPos = y;
        wall[index].COLOR = IGame::COLORHEX::WHITE;
        wall[index].FORM = IGame::SHAPE::SQUARE;
        ++index;
        if (index < 32)
            ++x;
        else if (index >= 32 && index < 63)
            ++y;
        else if (index >= 63 && index < 94)
            --x;
        else
            --y;
    }
    _wall = wall;
    srand(time(nullptr));
    snakeReset(_hiscore);
    timeStart = std::clock();
    _lastDirection = Direction::NONE;
    _nextDirection = Direction::NONE;

}

int Snake::getWidth()
{
    return (_width);
}

int Snake::getHeight()
{
    return (_height);
}

int Snake::getSnakeSize()
{
    return (_snakeSize);
}

int Snake::getDirection()
{
    if (_nextDirection == Direction::NONE)
        return (0);
    else
        return (1);
}

void Snake::snakeReset(int &Score)
{
    unsigned int index = 0;

    if (Score > _hiscore)
        _hiscore = Score;
    Score = 0;
    _snakeSize = 4;
    _nextDirection = Direction::NONE;
    _lastDirection = Direction::NONE;
    while (_corps.size() > _snakeSize)
        _corps.pop_back();
    while (index < _snakeSize) {
        _corps[index].XPos = (_width / 2);
        _corps[index].YPos = (_height / 2);
        ++index;
    }
    _fruit.XPos = rand() % (_width - 2) + 1;
    _fruit.YPos = rand() % (_height - 2) + 1;
    while (_fruit.XPos == _corps[0].XPos && _fruit.YPos == _corps[0].YPos) {
        _fruit.XPos = rand() % (_width - 2) + 1;
        _fruit.YPos = rand() % (_height - 2) + 1;
    }
}

unsigned char Snake::keyEvent(unsigned char KeyPressed)
{
    switch (KeyPressed) {
    case 2:
        setNextDirection(Snake::Direction::UP);
        return(1);
    case 4:
        setNextDirection(Snake::Direction::DOWN);
        return(1);
    case 3:
        setNextDirection(Snake::Direction::LEFT);
        return(1);
    case 5:
        setNextDirection(Snake::Direction::RIGHT);
        return(1);
    default:
        return(0);
    }
}

void Snake::setNextDirection(Direction new_direction)
{
    switch (new_direction) {
    case Direction::UP:
        if (_lastDirection != Direction::DOWN)
            this->_nextDirection = new_direction;
        break;
    case Direction::DOWN:
        if (_lastDirection != Direction::UP)
            this->_nextDirection = new_direction;
        break;
    case Direction::LEFT:
        if (_lastDirection != Direction::RIGHT)
            this->_nextDirection = new_direction;
        break;
    case Direction::RIGHT:
        if (_lastDirection != Direction::LEFT)
            this->_nextDirection = new_direction;
        break;
    default:
        break;
    }
}

int Snake::snakeGrow()
{
    unsigned int index = 0;
    IGame::DataElem_t newCorps;

    if ((_corps[0].XPos == _fruit.XPos) && (_corps[0].YPos == _fruit.YPos)) {
        newCorps.COLOR = IGame::COLORHEX::GREEN;
        newCorps.FORM = IGame::SHAPE::SQUARE;
        newCorps.Name = "corps";
        newCorps.XPos = _corps[_snakeSize - 1].XPos;
        newCorps.YPos = _corps[_snakeSize - 1].YPos;
        _snakeSize += 1;
        _corps.push_back(newCorps);
        _fruit.XPos = rand() % (_width - 2) + 1;
        _fruit.YPos = rand() % (_height - 2) + 1;
        while (index < _snakeSize) {
            if (_fruit.XPos == _corps[index].XPos
                && _fruit.YPos == _corps[index].YPos) {
                _fruit.XPos = rand() % (_width - 2) + 1;
                _fruit.YPos = rand() % (_height - 2) + 1;
                index = 0;
            }
            else
                ++index;
        }
        return (1);
    }
    return (0);
}

void Snake::snakeMove()
{
    int index = _snakeSize - 1;
    int nextX = 0;
    int nextY = 0;

    switch (_nextDirection) {
    case Direction::UP:
        nextY = -1;
        break;
    case Direction::DOWN:
        nextY = 1;
        break;
    case Direction::LEFT:
        nextX = -1;
        break;
    case Direction::RIGHT:
        nextX = 1;
        break;
    default:
        break;
    }
    while (index > 0) {
        _corps[index].XPos = _corps[index - 1].XPos;
        _corps[index].YPos = _corps[index - 1].YPos;
        --index;
    }
    _corps[0].XPos += nextX;
    _corps[0].YPos += nextY;
    _lastDirection = _nextDirection;
}

bool Snake::snakeBlock()
{
    unsigned int index = 0;

    if ((_corps[0].XPos <= 0) || (_corps[0].XPos >= _width + 1)
        || (_corps[0].YPos <= 0) || (_corps[0].YPos >= _height + 1))
        return (true);
    while (++index < _snakeSize) {
        if (_nextDirection != Direction::NONE
            && _corps[0].XPos == _corps[index].XPos
            && _corps[0].YPos == _corps[index].YPos) {
            return (true);
        }
    }
    return (false);
}

std::vector<std::shared_ptr<IGame::DataElem_t>>& Snake::RetriveDataElem()
{
    ElemBox.clear();
    LoadData();
    return (ElemBox);
}

std::vector<std::shared_ptr<IGame::DataMap_t>>& Snake::RetriveDataMap()
{
    MapBox.clear();
    LoadMap();
    return (MapBox);
}

void Snake::LoadData()
{
    unsigned int index = 0;

    while (index < _snakeSize) {
        std::shared_ptr<IGame::DataElem_t> tmp(new IGame::DataElem_t());
        tmp->XPos = _corps[index].XPos;
        tmp->YPos = _corps[index].YPos;
        tmp->Name = _corps[index].Name;
        tmp->COLOR = _corps[index].COLOR;
        tmp->FORM = _corps[index].FORM;
        ElemBox.push_back(tmp);
        ++index;
    }
    std::shared_ptr<IGame::DataElem_t> tmp(new IGame::DataElem_t());
    tmp->XPos = _fruit.XPos;
    tmp->YPos = _fruit.YPos;
    tmp->Name = _fruit.Name;
    tmp->COLOR = _fruit.COLOR;
    tmp->FORM = _fruit.FORM;
    ElemBox.push_back(tmp);
}

void Snake::LoadMap()
{
    unsigned int index = 0;

    while (index < _wall.size()) {
        std::shared_ptr<IGame::DataMap_t> tmp(new IGame::DataMap_t());
        tmp->XPos = _wall[index].XPos;
        tmp->YPos = _wall[index].YPos;
        tmp->COLOR = _wall[index].COLOR;
        tmp->FORM = _wall[index].FORM;
        MapBox.push_back(tmp);
        ++index;
    }
}

void Snake::UpdateData(unsigned char KeyPressed, int &Score, bool &GameOver)
{
    static char got = 0;

    got = keyEvent(KeyPressed);
    timeNow = (std::clock() - timeStart) / (double)CLOCKS_PER_SEC;
    if ((got == 0 && timeNow > 0.008) || (got == 1 && timeNow > 0.001)) {
        snakeMove();
        if (snakeBlock() == true) {
            _life -= 1;
            snakeReset(Score);
        }
        if (_life == 0) {
            GameOver = true;
            Score = _hiscore;
            return;
        }
        Score += snakeGrow();
        timeStart = std::clock();
    }
}
