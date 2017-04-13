GPP		=	g++

NAME	=	lib_arcade_sfml.so

SRC		=	sfml.cpp			\
                        ../../common/SoundManager.cpp

GAMESDIR	=	../../../lib/

OBJ 	    =	$(SRC:.cpp=.o)

CXXFLAGS    =   -std=c++14

CXXFLAGS    +=  -W -Wall -Wextra -fPIC

CXXFLAGS    +=  -I../../../includes/lib/sfml -I../../../includes -I../../../includes/common

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lopenal -lsndfile

LDFLAGS		+=	-shared

$(NAME):	$(OBJ)
		    $(GPP) -o $(NAME) $(OBJ) $(LDFLAGS)
				mv $(NAME) $(GAMESDIR)

all:		$(NAME)

clean:
				$(RM)	$(OBJ)

fclean:	clean
				$(RM) $(GAMESDIR)$(NAME)

re:			fclean all
