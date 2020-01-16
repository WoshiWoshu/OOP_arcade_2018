/*
** EPITECH PROJECT, 2019
** Menu.cpp
** File description:
** Menu
*/

#include <vector>
#include "ILibs.hpp"
#include "Core.hpp"

static void createElem(std::vector<std::shared_ptr<IGame::DataElem_t>> &elem,
                       std::vector<std::shared_ptr<IGame::DataMap_t>> &map,
                       std::vector<std::shared_ptr<ILibs::LibData_t>> &data,
                       std::vector<std::shared_ptr<ILibs::LibData_t>> &libMap,
                       ILibs *libs)
{
    std::shared_ptr<ILibs::LibData_t> dataTmp;

    for (auto i : map) {
        dataTmp.reset(new ILibs::LibData_t);
        dataTmp = libs->createShape(i->XPos, i->YPos, static_cast<int>(i->COLOR), static_cast<int>(i->FORM));
        dataTmp->LibObj = libs->createShape(i->XPos, i->YPos, static_cast<int>(i->COLOR), static_cast<int>(i->FORM))->LibObj;
        libMap.push_back(dataTmp);
    }
    for (auto i : elem) {
        dataTmp.reset(new ILibs::LibData_t);
        dataTmp = libs->createShape(i->XPos, i->YPos, static_cast<int>(i->COLOR), static_cast<int>(i->FORM));
        dataTmp->LibObj = libs->createShape(i->XPos, i->YPos, static_cast<int>(i->COLOR), static_cast<int>(i->FORM))->LibObj;
        data.push_back(dataTmp);
    }
}

static void displayElem(std::vector<std::shared_ptr<IGame::DataElem_t>> &elem,
                        std::vector<std::shared_ptr<ILibs::LibData_t>> &data,
                        ILibs *libs)
{
    unsigned int j = 0;
    std::shared_ptr<ILibs::LibData_t> dataTmp;

    for (long unsigned int i = 0; i < data.size() && i < elem.size(); i++) {
        libs->setPosition(data[i], elem[i]->XPos, elem[i]->YPos);
        libs->setColor(data[i], static_cast<int>(elem[i]->COLOR));
        j++;
    }
    while (j < elem.size()) {
        dataTmp.reset(new ILibs::LibData_t);
        dataTmp = libs->createShape(elem[j]->XPos, elem[j]->YPos, static_cast<int>(elem[j]->COLOR), static_cast<int>(elem[j]->FORM));
        data.push_back(dataTmp);
        j++;
    }
    while (j < data.size())
        data.pop_back();
}

static void retrieveElem(IGame *game,
std::vector<std::shared_ptr<IGame::DataMap_t>> &map,
std::vector<std::shared_ptr<IGame::DataElem_t>> &elem)
{
    elem = game->RetriveDataElem();
    map = game->RetriveDataMap();
}

int core(HandleDLib &dynLib, std::string &libParam,
    const std::string &action, bool &enterName, int &score)
{
    ILibs *lib;
    HandleDLib dynGame;
    IGame *game;
    std::vector<std::shared_ptr<IGame::DataElem_t>> elem;
    std::vector<std::shared_ptr<IGame::DataMap_t>> map;
    unsigned char keyPressed = 0;
    bool gameOver = false;
    std::string gameInfo("");
    std::vector<std::shared_ptr<ILibs::LibData_t>> libData(0);
    std::vector<std::shared_ptr<ILibs::LibData_t>> libMap(0);
    bool is_running = true;
    bool is_open = true;

    std::shared_ptr<ILibs::LibText_t> text;
    if (action == "snake")
        gameInfo = "games/lib_arcade_nibbler.so";
    if (action == "pacman")
        gameInfo = "games/lib_arcade_pacman.so";
    if (libParam == "libs/lib_arcade_ncurses.so")
        lib = dynLib.getSymbolNcurses();
    if (libParam == "libs/lib_arcade_sfml.so")
        lib = dynLib.getSymbolSFML();
    if (gameInfo == "games/lib_arcade_nibbler.so") {
        dynGame = "games/lib_arcade_nibbler.so";
        game = dynGame.getSymbolSnake();
    }
    if (gameInfo == "games/lib_arcade_pacman.so") {
        dynGame = "games/lib_arcade_pacman.so";
        game = dynGame.getSymbolPacman();
    }
    lib->createWindow(960, 960, "Arcade");
    retrieveElem(game, map, elem);
    createElem(elem, map, libData, libMap, lib);
    while (is_running == true) {
        displayElem(elem, libData, lib);
        lib->Clear();
        for (auto i : libMap)
            lib->draw(i);
        for (auto i : libData)
            lib->draw(i);
        lib->Refresh();
        game->UpdateData(keyPressed, score, gameOver);
        if (gameOver == true) {
            is_open = false;
            lib->closeWindow();
            enterName = false;
            std::cout << "!!!!" << std::endl;
            std::cout << "Game over !" << std::endl;
            return 1;
        }
        retrieveElem(game, map, elem);
        keyPressed = lib->getInputs();
        if (keyPressed == ILibs::EVENT::T) {
            is_open = false;
            enterName = false;
            lib->closeWindow();
            return 1;
        }
        else if (keyPressed == ILibs::EVENT::SPACE) {
            if (gameInfo == "games/lib_arcade_nibbler.so") {
                elem.clear();
                map.clear();
                libData.clear();
                libMap.clear();
                game = dynGame.getSymbolSnake();
                retrieveElem(game, map, elem);
                createElem(elem, map, libData, libMap, lib);
            }
            if (gameInfo == "games/lib_arcade_pacman.so") {
                elem.clear();
                map.clear();
                libData.clear();
                libMap.clear();
                game = dynGame.getSymbolPacman();
                retrieveElem(game, map, elem);
                createElem(elem, map, libData, libMap, lib);
            }
            score = 0;
        }
        else if (keyPressed == ILibs::EVENT::U && gameInfo == "games/lib_arcade_pacman.so") {
            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            dynGame = "games/lib_arcade_nibbler.so";
            gameInfo = "games/lib_arcade_nibbler.so";
            game = dynGame.getSymbolSnake();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            score = 0;
        }
        else if (keyPressed == ILibs::EVENT::U && gameInfo == "games/lib_arcade_nibbler.so") {
            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            dynGame = "games/lib_arcade_pacman.so";
            gameInfo = "games/lib_arcade_pacman.so";
            game = dynGame.getSymbolPacman();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            score = 0;
        }
        else if (keyPressed == ILibs::EVENT::Y && gameInfo == "games/lib_arcade_pacman.so") {
            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            dynGame = "games/lib_arcade_nibbler.so";
            gameInfo = "games/lib_arcade_nibbler.so";
            game = dynGame.getSymbolSnake();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            score = 0;
        }
        else if (keyPressed == ILibs::EVENT::Y && gameInfo == "games/lib_arcade_nibbler.so") {
            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            dynGame = "games/lib_arcade_pacman.so";
            gameInfo = "games/lib_arcade_pacman.so";
            game = dynGame.getSymbolPacman();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            score = 0;
        }
        else if (keyPressed == ILibs::EVENT::I && libParam == "libs/lib_arcade_sfml.so") {
            lib->closeWindow();
            dynLib = "libs/lib_arcade_ncurses.so";
            libParam = "libs/lib_arcade_ncurses.so";
            lib = dynLib.getSymbolNcurses();

            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            lib->createWindow(960, 960, "Arcade");
        }
        else if (keyPressed == ILibs::EVENT::I && libParam == "libs/lib_arcade_ncurses.so") {
            lib->closeWindow();
            dynLib = "libs/lib_arcade_sfml.so";
            libParam = "libs/lib_arcade_sfml.so";
            lib = dynLib.getSymbolSFML();

            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            lib->createWindow(960, 960, "Arcade");
        }
        else if (keyPressed == ILibs::EVENT::O && libParam == "libs/lib_arcade_sfml.so") {
            lib->closeWindow();
            dynLib = "libs/lib_arcade_ncurses.so";
            libParam = "libs/lib_arcade_ncurses.so";
            lib = dynLib.getSymbolNcurses();

            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            lib->createWindow(960, 960, "Arcade");
        }
        else if (keyPressed == ILibs::EVENT::O && libParam == "libs/lib_arcade_ncurses.so") {
            lib->closeWindow();
            dynLib = "libs/lib_arcade_sfml.so";
            libParam = "libs/lib_arcade_sfml.so";
            lib = dynLib.getSymbolSFML();

            elem.clear();
            map.clear();
            libData.clear();
            libMap.clear();
            retrieveElem(game, map, elem);
            createElem(elem, map, libData, libMap, lib);
            lib->createWindow(960, 960, "Arcade");
        }
        if (lib->getStatusWindow() == false && is_open == false)
            is_running = false;
    }
    return 0;
}
