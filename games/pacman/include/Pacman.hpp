/*
** EPITECH PROJECT, 2019
** Pacman.hpp
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <ctime>
#include <vector>
#include "IGame.hpp"

class Pacman : public IGame
{
public:
    Pacman();
    ~Pacman();

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE,
    };

    char **setMap();
    IGame::DataElem_t setPlayer();
    std::vector<IGame::DataElem_t> setGhost();
    std::vector<IGame::DataElem_t> setGum();
    std::vector<IGame::DataElem_t> setPacGum();
    std::vector<IGame::DataMap_t> setWall();

    void newGamePacman();
    void resetPacman();
    void keyEvent(unsigned char KeyPressed);
    void changeDirectionPacman();
    void movePacman();
    void startGhost();
    void moveGhost(Direction &ghostDirection, IGame::DataElem_t &ghost);
    void recolorGhost();
    void eatGum(int &Score);
    void pacmanEatGhost(int &Score);
    bool ghostEatPacman();

    std::vector<std::shared_ptr<IGame::DataElem_t>>
    &RetriveDataElem() override;
    std::vector<std::shared_ptr<IGame::DataMap_t>> &RetriveDataMap() override;
    void LoadData() override;
    void LoadMap() override;
    void UpdateData(unsigned char KeyPressed, int &Score,
                    bool &GameOver) override;

public:
    IGame::DataElem_t _player;
    std::vector<IGame::DataElem_t> _ghost;
    std::vector<IGame::DataElem_t> _gum;
    std::vector<IGame::DataElem_t> _pacGum;
    std::vector<IGame::DataMap_t> _wall;

    std::vector<std::shared_ptr<IGame::DataElem_t>> ElemBox;
    std::vector<std::shared_ptr<IGame::DataMap_t>> MapBox;

private:
    int _width;
    int _height;
    std::clock_t timeStart;
    double timeNow;
    std::clock_t ghostTimeStart;
    double ghostTimeNow;
    std::clock_t spawnTimeStart;
    double spawnTimeNow;
    std::clock_t gumTimeStart;
    double gumTimeNow;
    Direction _currentDirection;
    Direction _nextDirection;
    Direction _ghost0Direction;
    Direction _ghost1Direction;
    Direction _ghost2Direction;
    Direction _ghost3Direction;
    char **_map;
    unsigned char _gumStill;
    unsigned char _win;
    int _life = 3;
};

#endif
