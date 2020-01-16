##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX		=	g++ -g3
RM		=	rm -f

CXXFLAGS	+=	-std=c++11 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall
CXXFLAGS	+=	-I./include/
CXXFLAGS	+=	-I../include/
CXXFLAGS	+=	-I../libs/sfml/sfml_graph.hpp
CXXFLAGS	+=	-I../../core/include/
CXXFLAGS	+=	-I../../games/nibble/include/
CXXFLAGS	+=	-I../../games/include/

NAME		=	../lib_arcade_sfml.so
SRCS		+=	./sfml_graph.cpp \
			./sfml_shapes.cpp \
			./sfml_text.cpp
OBJS		=	$(SRCS:.cpp=.o)

# LDFLAGS		+=	-L./deps/glew/lib -lGLEW -lGLEWmx
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
