##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

all:
	make -C ./libs/sfml/
	make -C ./libs/ncurses/
	make -C ./games/nibble/
	make -C ./games/pacman/
	make -C ./core/

games:
	make -C ./games/nibble/
	make -C ./games/pacman/

graphicals:
	make -C ./libs/sfml/
	make -C ./libs/ncurses/

core:
	make -C ./core/

re:	fclean all

clean:
	make clean -C ./libs/sfml/
	make clean -C ./libs/ncurses/
	make clean -C ./games/nibble/
	make clean -C ./games/pacman/
	make clean -C ./core/

fclean:
	make fclean -C ./libs/sfml/
	make fclean -C ./libs/ncurses/
	make fclean -C ./games/nibble/
	make fclean -C ./games/pacman/
	make fclean -C ./core/

.PHONY	:	all clean fclean re games graphicals core
