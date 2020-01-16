/*
** EPITECH PROJECT, 2019
** Pacman.cpp
** File description:
** Pacman
*/

#include <memory>
#include <string.h>
#include "HandleDLib.hpp"
#include "Pacman.hpp"

IGame *entryPointPacman()
{
    IGame *game = new Pacman();

    return game;
}

Pacman::Pacman() : _width(19), _height(21), _gumStill(150), _win(0)
{
    _map = setMap();
    _player = setPlayer();
    _ghost = setGhost();
    _gum = setGum();
    _pacGum = setPacGum();
    _wall = setWall();
    srand(time(nullptr));
    timeStart = std::clock();
    ghostTimeStart = std::clock();
    _currentDirection = Direction::NONE;
    _nextDirection = Direction::NONE;
}

Pacman::~Pacman()
{
    int index = 0;

    while (index < 21) {
        if (_map[index] != nullptr)
            free(_map[index]);
        ++index;
    }
    if (_map != nullptr)
        free(_map);
}

char **Pacman::setMap()
{
    char **map = (char**)malloc(sizeof(char*) * 22);
    int index = 0;

    if (map == NULL)
        exit(84);
    while (index < 22) {
        map[index] = (char*)malloc(sizeof(char) * 20);
        if (map[index] == NULL)
            exit(84);           
        ++index;
    }
    strcpy(map[0],  "1111111111111111111\0");
    strcpy(map[1],  "1000000001000000001\0");
    strcpy(map[2],  "1011011101011101101\0");
    strcpy(map[3],  "1000000000000000001\0");
    strcpy(map[4],  "1011010111110101101\0");
    strcpy(map[5],  "1000010001000100001\0");
    strcpy(map[6],  "1111011101011101111\0");
    strcpy(map[7],  "0001010000000101000\0");
    strcpy(map[8],  "1111010111110101111\0");
    strcpy(map[9],  "0000000100010000000\0");
    strcpy(map[10], "1111010111110101111\0");
    strcpy(map[11], "0001010000000101000\0");
    strcpy(map[12], "1111010111110101111\0");
    strcpy(map[13], "1000000001000000001\0");
    strcpy(map[14], "1011011101011101101\0");
    strcpy(map[15], "1001000000000001001\0");
    strcpy(map[16], "1101010111110101011\0");
    strcpy(map[17], "1000010001000100001\0");
    strcpy(map[18], "1011111101011111101\0");
    strcpy(map[19], "1000000000000000001\0");
    strcpy(map[20], "1111111111111111111\0");
    return (map);
}

IGame::DataElem_t Pacman::setPlayer()
{
    IGame::DataElem_t player;

    player.XPos = 9;
    player.YPos = 15;
    player.Name = "pacman";
    player.COLOR = IGame::COLORHEX::YELLOW;
    player.FORM = IGame::SHAPE::CIRCLE;
    return (player);
}

std::vector<IGame::DataElem_t> Pacman::setGhost()
{
    std::vector<IGame::DataElem_t> ghost(4);
    int index = 0;

    while (index < 4) {
        ghost[index].Name = "ghost";
        ghost[index].FORM = IGame::SHAPE::TRIANGLE;
        ++index;
    }
    ghost[0].XPos = 9;
    ghost[0].YPos = 8;
    ghost[0].COLOR = IGame::COLORHEX::WHITE;
    _ghost0Direction = Direction::NONE;
    ghost[1].XPos = 9;
    ghost[1].YPos = 9;
    ghost[1].COLOR = IGame::COLORHEX::WHITE;
    _ghost1Direction = Direction::NONE;
    ghost[2].XPos = 8;
    ghost[2].YPos = 9;
    ghost[2].COLOR = IGame::COLORHEX::WHITE;
    _ghost2Direction = Direction::NONE;
    ghost[3].XPos = 10;
    ghost[3].YPos = 9;
    ghost[3].COLOR = IGame::COLORHEX::WHITE;
    _ghost3Direction = Direction::NONE;
    return (ghost);
}

std::vector<IGame::DataElem_t> Pacman::setGum()
{
    unsigned char gumCoorX[150] =
        {
            1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17,
            4, 8, 10, 14,
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
            1, 4, 6, 12, 14, 17,
            1, 2, 3, 4, 6, 7, 8, 10, 11, 12, 14, 15, 16, 17,
            4, 14,
            4, 14,
            4, 14,
            4, 14,
            4, 14,
            4, 14,
            4, 14,
            1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17,
            1, 4, 8, 10, 14, 17,
            2, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 16,
            2, 4, 6, 12, 14, 16,
            1, 2, 3, 4, 6, 7, 8, 10, 11, 12, 14, 15, 16, 17,
            1, 8, 10, 17,
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17
        };
    unsigned char gumCoorY[150] =
        {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            2, 2, 2, 2,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            4, 4, 4, 4, 4, 4,
            5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
            6, 6,
            7, 7,
            8, 8,
            9, 9,
            10, 10,
            11, 11,
            12, 12,
            13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
            14, 14, 14, 14, 14, 14,
            15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
            16, 16, 16, 16, 16, 16,
            17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
            18, 18, 18, 18,
            19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19
        };
    std::vector<IGame::DataElem_t> gum(146);
    int index = 0;

    while (index < 146) {
        gum[index].XPos = gumCoorX[index];
        gum[index].YPos = gumCoorY[index];
        gum[index].Name = "gum";
        gum[index].COLOR = IGame::COLORHEX::RED;
        gum[index].FORM = IGame::SHAPE::RECTANGLE;
        ++index;
    }
    return (gum);
}

std::vector<IGame::DataElem_t> Pacman::setPacGum()
{
    unsigned char gumCoorX[5] = {1, 17, 1, 17};
    unsigned char gumCoorY[5] = {2, 2, 15, 15};

    std::vector<IGame::DataElem_t> pacGum(4);
    int index = 0;

    while (index < 4) {
        pacGum[index].Name = "pacgum";
        pacGum[index].COLOR = IGame::COLORHEX::RED;
        pacGum[index].FORM = IGame::SHAPE::CIRCLE;
        pacGum[index].XPos = gumCoorX[index];
        pacGum[index].YPos = gumCoorY[index];
        ++index;
    }
    return (pacGum);
}

std::vector<IGame::DataMap_t> Pacman::setWall()
{
    unsigned char wallCoorX[200] =
        {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, //19 0
            0, 9, 18, //3 1
            0, 2, 3, 5, 6, 7, 9, 11, 12, 13, 15, 16, 18, //13 2
            0, 18, //2 3
            0, 2, 3, 5, 7, 8, 9, 10, 11, 13, 15, 16, 18, //13 4
            0, 5, 9, 13, 18, //5 5
            0, 1, 2, 3, 5, 6, 7, 9, 11, 12, 13, 15, 16, 17, 18, //15 6
            3, 5, 13, 15, //4 7
            0, 1, 2, 3, 5, 7, 8, 10, 11, 13, 15, 16, 17, 18, //14 8
            7, 11, //2 9
            0, 1, 2, 3, 5, 7, 8, 9, 10, 11, 13, 15, 16, 17, 18, //15 10
            3, 5, 13, 15, // 4 11
            0, 1, 2, 3, 5, 7, 8, 9, 10, 11, 13, 15, 16, 17, 18, //15 12
            0, 9, 18, //3 13
            0, 2, 3, 5, 6, 7, 9, 11, 12, 13, 15, 16, 18, //13 14
            0, 3, 15, 18, //4 15
            0, 1, 3, 5, 7, 8, 9, 10, 11, 13, 15, 17, 18, //13 16
            0, 5, 9, 13, 18, //5 17
            0, 2, 3, 4, 5, 6, 7, 9, 11, 12, 13, 14, 15, 16, 18, //15 18
            0, 18, //2 19
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 //19 20
            /*198*/
        };
    unsigned char wallCoorY[200] =
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //19
            1, 1, 1, //3
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, //13
            3, 3, //2
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, //13
            5, 5, 5, 5, 5, //5
            6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, //15
            7, 7, 7, 7, //4
            8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, //14
            9, 9, //2
            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, //15
            11, 11, 11, 11, //4
            12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, // 15
            13, 13, 13, //3
            14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, //13
            15, 15, 15, 15, //4
            16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, //13
            17, 17, 17, 17, 17, //5
            18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, //15
            19, 19, //2
            20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
            20, 20, 20 //19
            //198
        };
    std::vector<IGame::DataMap_t> wall(198);
    int index = 0;

    while (index < 198) {
        wall[index].XPos = wallCoorX[index];
        wall[index].YPos = wallCoorY[index];
        wall[index].COLOR = IGame::COLORHEX::BLUE;
        wall[index].FORM = IGame::SHAPE::SQUARE;
        ++index;
    }
    return (wall);
}

void Pacman::newGamePacman()
{
    unsigned int index = 0;

    while (index < _gum.size())
    {
        _gum[index].COLOR = IGame::COLORHEX::RED;
        index++;
    }
    index = 0;
    while (index < _pacGum.size()) {
        _pacGum[index].COLOR = IGame::COLORHEX::RED;
        index++;
    }
    _gumStill = 150;
    resetPacman();
}

void Pacman::resetPacman()
{
    int index = -1;

    _player.XPos = 9;
    _player.YPos = 15;
    while (++index < 4)
        _ghost[index].FORM = IGame::SHAPE::TRIANGLE;
    _ghost[0].XPos = 9;
    _ghost[0].YPos = 8;
    _ghost[0].COLOR = IGame::COLORHEX::WHITE;
    _ghost0Direction = Direction::NONE;
    _ghost[1].XPos = 9;
    _ghost[1].YPos = 9;
    _ghost[1].COLOR = IGame::COLORHEX::WHITE;
    _ghost1Direction = Direction::NONE;
    _ghost[2].XPos = 8;
    _ghost[2].YPos = 9;
    _ghost[2].COLOR = IGame::COLORHEX::WHITE;
    _ghost2Direction = Direction::NONE;
    _ghost[3].XPos = 10;
    _ghost[3].YPos = 9;
    _ghost[3].COLOR = IGame::COLORHEX::WHITE;
    _ghost3Direction = Direction::NONE;
    _currentDirection = Direction::NONE;
    _nextDirection = Direction::NONE;
    spawnTimeStart = std::clock();
    gumTimeStart = std::clock();
}

void Pacman::keyEvent(unsigned char KeyPressed)
{
    switch (KeyPressed) {
    case 2:
        _nextDirection = Direction::UP;
        break;
    case 4:
        _nextDirection = Direction::DOWN;
        break;
    case 3:
        _nextDirection = Direction::LEFT;
        break;
    case 5:
        _nextDirection = Direction::RIGHT;
        break;
    case ' ':
        newGamePacman();
    default:
        break;
    }
}

void Pacman::changeDirectionPacman()
{
    if (_currentDirection == Direction::NONE)
        spawnTimeStart = std::clock();
    switch (_nextDirection) {
    case Direction::UP:
        if (_map[_player.YPos - 1][_player.XPos] == '0')
            _currentDirection = _nextDirection;
        break;
    case Direction::DOWN:
        if (_map[_player.YPos + 1][_player.XPos] == '0')
            _currentDirection = _nextDirection;
        break;
    case Direction::LEFT:
        if ((_player.YPos == 9 && _player.XPos == 0)
        || (_map[_player.YPos][_player.XPos - 1] == '0'))
            _currentDirection = _nextDirection;
        break;
    case Direction::RIGHT:
        if ((_player.YPos == 9 && _player.XPos == 18)
        || (_map[_player.YPos][_player.XPos + 1] == '0'))
            _currentDirection = _nextDirection;
        break;
    default:
        break;
    }
}

void Pacman::movePacman()
{
    switch (_currentDirection) {
    case Direction::UP:
        if (_map[_player.YPos - 1][_player.XPos] == '0')
            _player.YPos -= 1;
        break;
    case Direction::DOWN:
        if (_map[_player.YPos + 1][_player.XPos] == '0')
            _player.YPos += 1;
        break;
    case Direction::LEFT:
        if (_player.YPos == 9 && _player.XPos == 0)
            _player.XPos = 18;
        else if (_map[_player.YPos][_player.XPos - 1] == '0')
            _player.XPos -= 1;
        break;
    case Direction::RIGHT:
        if (_player.YPos == 9 && _player.XPos == 18)
            _player.XPos = 0;
        else if (_map[_player.YPos][_player.XPos + 1] == '0')
            _player.XPos += 1;
        break;
    default:
        break;
    }
}

void Pacman::startGhost()
{
    spawnTimeNow = (std::clock() - spawnTimeStart) / (double)CLOCKS_PER_SEC;
    if (_ghost[0].XPos == 9 && _ghost[0].YPos == 8) {
        _ghost[0].YPos = 7;
        _ghost0Direction = Direction::LEFT;
    }
    if (_ghost[1].XPos == 9 && _ghost[1].YPos == 9 && spawnTimeNow > 0.5) {
        _ghost[1].YPos = 7;
        _ghost1Direction = Direction::LEFT;
    }
    if (_ghost[2].XPos == 8 && _ghost[2].YPos == 9 && spawnTimeNow > 1.0) {
        _ghost[2].XPos = 9;
        _ghost[2].YPos = 7;
        _ghost2Direction = Direction::RIGHT;
    }
    if (_ghost[3].XPos == 10 && _ghost[3].YPos == 9 && spawnTimeNow > 1.5) {
        _ghost[3].XPos = 9;
        _ghost[3].YPos = 7;
        _ghost3Direction = Direction::RIGHT;
    }
}

void Pacman::moveGhost(Direction &ghostDirection, IGame::DataElem_t &ghost)
{
    switch (ghostDirection) {
    case Direction::UP:
        if (_map[ghost.YPos - 1][ghost.XPos] == '0')
            ghost.YPos -= 1;
        if (_map[ghost.YPos][ghost.XPos - 1] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::LEFT;
        else if (_map[ghost.YPos][ghost.XPos + 1] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::RIGHT;
        break;
    case Direction::DOWN:
        if (_map[ghost.YPos + 1][ghost.XPos] == '0')
            ghost.YPos += 1;
        if (_map[ghost.YPos][ghost.XPos - 1] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::LEFT;
        else if (_map[ghost.YPos][ghost.XPos + 1] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::RIGHT;
        break;
    case Direction::LEFT:
        if (ghost.YPos == 9 && ghost.XPos == 0)
            ghost.XPos = 18;
        else if (_map[ghost.YPos][ghost.XPos - 1] == '0')
            ghost.XPos -= 1;
        if (_map[ghost.YPos - 1][ghost.XPos] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::UP;
        else if (_map[ghost.YPos + 1][ghost.XPos] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::DOWN;
        break;
    case Direction::RIGHT:
        if (ghost.YPos == 9 && ghost.XPos == 18)
            ghost.XPos = 0;
        else if (_map[ghost.YPos][ghost.XPos + 1] == '0')
            ghost.XPos += 1;
        if (_map[ghost.YPos - 1][ghost.XPos] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::UP;
        else if (_map[ghost.YPos + 1][ghost.XPos] == '0'
        && (std::rand() % 2) == 1)
            ghostDirection = Direction::DOWN;
        break;
    default:
        break;
    }
}

void Pacman::recolorGhost()
{
    _ghost[0].COLOR = IGame::COLORHEX::WHITE;
    _ghost[1].COLOR = IGame::COLORHEX::WHITE;
    _ghost[2].COLOR = IGame::COLORHEX::WHITE;
    _ghost[3].COLOR = IGame::COLORHEX::WHITE;
}

void Pacman::eatGum(int &Score)
{
    unsigned int index = 0;

    while (index < _gum.size()) {
        if (_gum[index].COLOR == IGame::COLORHEX::RED
        && (_gum[index].YPos == _player.YPos
        && _gum[index].XPos == _player.XPos)) {
            _gum[index].COLOR = IGame::COLORHEX::GREEN;
            _gumStill -= 1;
            Score += 10;
        }
        index++;
    }
    index = 0;
    while (index < _pacGum.size()) {
        if (_pacGum[index].COLOR == IGame::COLORHEX::RED
        && (_pacGum[index].YPos == _player.YPos
        && _pacGum[index].XPos == _player.XPos)) {
            _pacGum[index].COLOR = IGame::COLORHEX::GREEN;
            _gumStill -= 1;
            _ghost[0].COLOR = IGame::COLORHEX::BLUE;
            _ghost[1].COLOR = IGame::COLORHEX::BLUE;
            _ghost[2].COLOR = IGame::COLORHEX::BLUE;
            _ghost[3].COLOR = IGame::COLORHEX::BLUE;
            gumTimeStart = std::clock();
        }
        index++;
    }
}

void Pacman::pacmanEatGhost(int &Score)
{
    int index = 0;

    while (index < 4) {
        if (_ghost[index].XPos == _player.XPos
        && _ghost[index].YPos == _player.YPos
        && _ghost[index].COLOR == IGame::COLORHEX::BLUE) {
            if (index == 0) {
                _ghost[0].XPos = 9;
                _ghost[0].YPos = 8;
                _ghost[0].COLOR = IGame::COLORHEX::WHITE;
                _ghost0Direction = Direction::NONE;
            }
            if (index == 1) {
                _ghost[1].XPos = 9;
                _ghost[1].YPos = 9;
                _ghost[1].COLOR = IGame::COLORHEX::WHITE;
                _ghost1Direction = Direction::NONE;
            }
            if (index == 2) {
                _ghost[2].XPos = 8;
                _ghost[2].YPos = 9;
                _ghost[2].COLOR = IGame::COLORHEX::WHITE;
                _ghost2Direction = Direction::NONE;
            }
            if (index == 3) {
                _ghost[3].XPos = 10;
                _ghost[3].YPos = 9;
                _ghost[3].COLOR = IGame::COLORHEX::WHITE;
                _ghost3Direction = Direction::NONE;
            }
            Score += 200;
        }
        ++index;
    }
}

bool Pacman::ghostEatPacman()
{
    int index = 0;

    while (index < 4) {
        if (_ghost[index].XPos == _player.XPos
        && _ghost[index].YPos == _player.YPos
        && _ghost[index].COLOR == IGame::COLORHEX::WHITE)
            return (true);
        ++index;
    }
    return (false);
}

std::vector<std::shared_ptr<IGame::DataElem_t>> &Pacman::RetriveDataElem()
{
    ElemBox.clear();
    LoadData();
    return (ElemBox);
}

std::vector<std::shared_ptr<IGame::DataMap_t>> &Pacman::RetriveDataMap()
{
    MapBox.clear();
    LoadMap();
    return (MapBox);
}

void Pacman::LoadData()
{
    unsigned int index = 0;

    while (index < _gum.size()) {
        std::shared_ptr<IGame::DataElem_t> tmp(new IGame::DataElem_t());
        tmp->XPos = _gum[index].XPos;
        tmp->YPos = _gum[index].YPos;
        tmp->Name = _gum[index].Name;
        tmp->COLOR = _gum[index].COLOR;
        tmp->FORM = _gum[index].FORM;
        ElemBox.push_back(tmp);
        ++index;
    }
    index = 0;
    while (index < _pacGum.size()) {
        std::shared_ptr<IGame::DataElem_t> tmp(new IGame::DataElem_t());
        tmp->XPos = _pacGum[index].XPos;
        tmp->YPos = _pacGum[index].YPos;
        tmp->Name = _pacGum[index].Name;
        tmp->COLOR = _pacGum[index].COLOR;
        tmp->FORM = _pacGum[index].FORM;
        ElemBox.push_back(tmp);
        ++index;
    }
    index = 0;
    while (index < _ghost.size()) {
        std::shared_ptr<IGame::DataElem_t> tmp(new IGame::DataElem_t());
        tmp->XPos = _ghost[index].XPos;
        tmp->YPos = _ghost[index].YPos;
        tmp->Name = _ghost[index].Name;
        tmp->COLOR = _ghost[index].COLOR;
        tmp->FORM = _ghost[index].FORM;
        ElemBox.push_back(tmp);
        ++index;
    }
    std::shared_ptr<IGame::DataElem_t> tmp(new IGame::DataElem_t());
    tmp->XPos = _player.XPos;
    tmp->YPos = _player.YPos;
    tmp->Name = _player.Name;
    tmp->COLOR = _player.COLOR;
    tmp->FORM = _player.FORM;
    ElemBox.push_back(tmp);
}

void Pacman::LoadMap()
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

void Pacman::UpdateData(unsigned char KeyPressed, int &Score, bool &GameOver)
{
    keyEvent(KeyPressed);
    if (_nextDirection == Direction::NONE) {
        spawnTimeStart = std::clock();
        return;
    }
    changeDirectionPacman();
    timeNow = (std::clock() - timeStart) / (double)CLOCKS_PER_SEC;
    ghostTimeNow = (std::clock() - ghostTimeStart) / (double)CLOCKS_PER_SEC;
    gumTimeNow = (std::clock() - gumTimeStart) / (double)CLOCKS_PER_SEC;
    startGhost();
    if (timeNow > 0.024) {
        movePacman();
        eatGum(Score);
        gumTimeNow = (std::clock() - gumTimeStart) / (double)CLOCKS_PER_SEC;
        timeStart = std::clock();
    }
    pacmanEatGhost(Score);
    if (gumTimeNow > 1.0)
        recolorGhost();
    if (_gumStill == 0) {
        _win += 1;
        newGamePacman();
    }
    if (ghostTimeNow > 0.020) {
        moveGhost(_ghost0Direction, _ghost[0]);
        moveGhost(_ghost1Direction, _ghost[1]);
        moveGhost(_ghost2Direction, _ghost[2]);
        moveGhost(_ghost3Direction, _ghost[3]);
        ghostTimeStart = std::clock();
    }
    if (ghostEatPacman() == true) {
        --_life;
        if (_life == 0)
            GameOver = true;
        else
            resetPacman();
    }
}
