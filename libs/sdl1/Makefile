##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX		=	g++
RM		=	rm -f

CXXFLAGS	+=	-std=c++11 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall -Werror
CXXFLAGS	+=	-I./include/
CXXFLAGS	+=	-I../include/

NAME		=	../lib_arcade_sdl1.so
SRCS		+=	./sdl_lib.cpp
OBJS		=	$(SRCS:.cpp=.o)

#Remplacer les LDFLAGS de la SFML par ceux de la SDL

LDFLAGS		+=	-L./deps/glew/lib -lGLEW -lGLEWmx
LDFLAGS		+=	-L./deps/SFML-2.2/lib -lsfml-audio
LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-network -lsfml-system
LDFLAGS		+=	-Wl,--rpath=./deps/glew/lib/
LDFLAGS		+=	-Wl,--rpath=./deps/SFML-2.2/lib

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

re:		fclean all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

.PHONY          :       all clean fclean re
