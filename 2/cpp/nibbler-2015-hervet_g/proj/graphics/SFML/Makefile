##
## Makefile for sfml in /home/terroi_s//sfml
## 
## Made by samuel terroitin
## Login   <terroi_s@epitech.net>
## 
## Started on  Mon Mar  5 17:22:24 2012 samuel terroitin
## Last update Sat Mar 17 19:04:38 2012 laura bernhardt
##

NAME		=	lib_nibbler_SFML.so

RM		=	rm -vf

CXX		=	g++

FIND		=	find

PRINTF		=	printf

###################### FILE #######################

SRC		=	SfmlDisplay.cpp \
			main.cpp

OBJ		=	$(SRC:.cpp=.o)

################## COMPILATION ####################

CXXFLAGS		+= -W -Wall -Wextra -Werror  -fPIC -I../../. -I../../class -I../../interfaces -I../ -I./lib
LDFLAGS         	+= -Wl,-R/usr/local/lib/ -ldl
# LDFLAGS         +=      -L/graphics/SFML/
LDFLAGS         	+= -L/usr/local/lib -lsfml-system -lsfml-window -lsfml-graphics -shared


$(NAME):		$(OBJ)
			@$(PRINTF) "\n\033[33mCompilation... \033[0m\n"
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)
##			g++ $(OBJ) -o $(NAME) $(LDFLAGS)
			@$(PRINTF) "\033[33mCompilation of\033[m \033[31m'$(NAME)'\033[m \033[33mdone.\033[m\n"
			@cp $(NAME) ../../../

all:			$(NAME)

clean:
		        @$(PRINTF) "\033[33mDeleting objects/temp... \033[0m\n"
			@$(RM) $(OBJ)
	        	@$(FIND) . -name "*~" -print -exec rm -f {} \;
			@$(FIND) . -name "\#*\#" -print -exec rm -f {} \;
			@$(PRINTF) "\033[33mDeleting done.\033[0m\n"

fclean:         	clean
			@$(PRINTF) "\n\033[33mDeleting bin... \033[0m\n"
			@$(RM) $(NAME)
	        	@$(PRINTF) "\033[33mDeleting bin done. \033[0m\n\n"

re:			fclean all

.PHONY:			all clean fclean re
