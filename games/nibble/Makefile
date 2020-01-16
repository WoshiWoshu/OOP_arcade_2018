##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX		=	g++ -g3
RM		=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-W -Wextra -Wall -fPIC
CXXFLAGS	+=	-I./include
CXXFLAGS	+=	-I../include
CXXFLAGS	+=	-I../../core/include
CXXFLAGS	+=	-I../../libs/sfml/include/
CXXFLAGS	+=	-I../../libs/include/

NAME		=	../lib_arcade_nibbler.so

SRCS		+=	./src/Snake.cpp
OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -shared $(OBJS) -o $(NAME)

re:		fclean all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

.PHONY          :       all clean fclean re
