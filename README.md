# OOP_arcade_2018
Second year project in C++ in which the goal is to build an Arcade that can support games. The games as well as the graphical libraries can be loaded and switch in run time with the help of dynamic libraries. The games consist of pacman and snake. As for the graphical libraries : SFML, ncurses and SDL. There is also a core which handle dynamic libraries switch and process datas between graphic (displays entities) and game physics (control the logic of the game : walls, jump, moves etc...).

PREREQUISITE : 

    SFML, ncurses and SDL needs to be installed.

USAGE :
    
    Make
    
    ./arcade [./library.so]

KEY MAPPING (when program launched) :

    - to change the game "u"/"y".
    - to change library "k"/"h".

EXEMPLE :

    > ./arcade ./lib_arcade_sfml.so

![Image description](PacmanCover.jpg)

![Image description](SnakeCover.png)
