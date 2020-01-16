##
## EPITECH PROJECT, 2019
## Makefile
## File description:
##
##

CXX		=	g++ -g3
RM		=	rm -f

CXXFLAGS	+=	-std=c++11 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall -Werror
CXXFLAGS	+=	-I../include/
CXXFLAGS	+=	-I./include/
CXXFLAGS        +=      -I../../core/include/
CXXFLAGS        +=      -I../../games/nibble/include/
CXXFLAGS        +=      -I../../games/include/

NAME		=	../lib_arcade_ncurses.so
SRCS		+=	ncurses_graph.cpp
SRCS		+=	ncurses_shapes.cpp
SRCS		+=	ncurses_text.cpp
OBJS		=	$(SRCS:.cpp=.o)

LDFLAGS		+=	-lncurses

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

re:		fclean all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

.PHONY          :       all clean fclean re
