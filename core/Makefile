##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CXX		=	g++ -g3
NAME		=	../arcade
RM		=	rm -f

CXXFLAGS	+=	-std=c++11 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall
CXXFLAGS	+=	-I./include
CXXFLAGS	+=	-I../games/nibble/include/
CXXFLAGS	+=	-I../games/include/
CXXFLAGS	+=	-I../libs/sfml/include/
CXXFLAGS	+=	-I../libs/include/

LDFLAGS		+=	-ldl

SRCS		+=	./src/HandleDLib.cpp
SRCS		+=	./src/Core.cpp
SRCS		+=	main.cpp
OBJS		+=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

.PHONY          :       all clean fclean re
