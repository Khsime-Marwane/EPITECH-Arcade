GPP		=	g++

NAME	=	lib_arcade_solarfox.so

COMMON	=	../../common/

GAME_COMMON	=	../common/

SRC		=	$(COMMON)Color.cpp \
				$(COMMON)Sprite.cpp \
				$(COMMON)Sound.cpp \
				$(COMMON)Component.cpp \
				$(COMMON)GUI.cpp \
				$(GAME_COMMON)Tile.cpp \
				Enemy.cpp \
				SfGame.cpp \
				Map.cpp	\
				Player.cpp \
				Shot.cpp

GAMESDIR	=	../../../games/

OBJ 	    =	$(SRC:.cpp=.o)

CXXFLAGS    =   -std=c++14

CXXFLAGS    +=  -W -Wall -Wextra -fPIC

CXXFLAGS    +=  -I../../../includes/common \
								-I../../../includes \
								-I../../../includes/games/common \
								-I../../../includes/games/solarfox

LDFLAGS			=	-shared

$(NAME):	$(OBJ)
		    $(GPP) -o $(NAME) $(OBJ) $(LDFLAGS)
				mv $(NAME) $(GAMESDIR)

all:		$(NAME)

clean:
				$(RM)	$(OBJ)

fclean:	clean
				$(RM) $(GAMESDIR)$(NAME)

re:			fclean all
