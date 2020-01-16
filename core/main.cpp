/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main.cpp
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "Core.hpp"
#include "HandleDLib.hpp"

static void help(void)
{
    std::cout << "----" << std::endl << "GAMES: Pacman and Snake" << std::endl;
    std::cout << "----" << std::endl
              << "GRAPHICAL LIBRARIES: SFML and nCurses" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "Key mapping:" << std::endl;
    std::cout << "- Previous Game: Y" << std::endl;
    std::cout << "- Next Game: U" << std::endl;
    std::cout << "- Previous Graphical Library: I" << std::endl;
    std::cout << "- Next Graphical Library: O" << std::endl;
    std::cout << "- Reset Game: SPACE" << std::endl;
    std::cout << "- Main Menu: T" << std::endl;
}

int main(int ac, char **av)
{
    (void)ac;
    if (ac != 2) {
        std::cerr << "[USAGE]:    ./arcade \"./lib_arcade_name.so\"" << std::endl;
        return 84;
    }
    int i = 0;
    while (av[1][i] != '\0') {
        if (av[1][i] == '.' && av[1][i + 1] == '/')
            return 0;
        i++;
    }
    HandleDLib dynLib(av[1]);
    std::string playerName;
    std::string action;
    bool enterName = false;
    std::string libParam(av[1]);
    int score = 0;

    help();
    while (42) {
        if (enterName == false) {
            std::cout << "----" << std::endl;
            std::cout << "Please enter your name..." << std::endl;
            std::cin >> playerName;
            std::cout << "Welcome " << playerName << " !" << std::endl;
            std::cout << "----" << std::endl;
        }
        if (enterName == true)
            std::cout << "----" << std::endl;
        enterName = true;
        std::cout << "Please enter a game, \"help\" or \"quit\" to quit the program" << std::endl;
        std::cout << "Available game: Snake, Pacman" << std::endl;
        std::cin >> action;
        std::transform(action.begin(), action.end(), action.begin(), ::tolower);
        if (action == "quit") {
            std::cout << "----" << std::endl;
            dynLib.~HandleDLib();
            break;
        }
        else if (action == "help")
            help();
        else if (action != "snake" && action != "pacman")
            std::cout << "[ERROR] Wrong entry " << action << std::endl;
        else {
            if (core(dynLib, libParam, action, enterName, score) == 1) {
                std::cout << "!!!!" << std::endl;
                std::cout << "Your score is: ";
                std::cout << score << std::endl;
                std::cout << "!!!!" << std::endl;
            }
            score = 0;
        }
    }
    return 0;
}
