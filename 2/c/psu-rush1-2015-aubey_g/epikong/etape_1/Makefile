##
## Makefile for  in /home/wotan/project/Epikong
## 
## Made by geoffroy aubey
## Login   <aubey_g@epitech.net>
## 
## Started on  Sat Mar  3 00:21:42 2012 geoffroy aubey
## Last update Sat Mar  3 00:21:42 2012 geoffroy aubey
##

# Project name
PNAME		=	epikong_etape_1


# Source directory
SRCDIR 		=	./src/

# Debug mode
DEBUG 		=	no

# DIR
DEBUG_DIR 	=	.

RELEASE_DIR	=	.

MKDIR		=	mkdir -p

INC		+=	-I $(SRCDIR)

CFLAGS		+= 	-W -Wall $(INC)

LDFLAGS		+=	-lSDL

# Debug / Release
ifeq ($(DEBUG),yes)
		CFLAGS	+=  -g3
		NAME = $(DEBUG_DIR)/$(PNAME)
		CC = gcc -DDEBUG
else
		NAME = $(RELEASE_DIR)/$(PNAME)
		CC = gcc -DNDEBUG
endif

RM		=	rm -rf

SRC		=	main.c	 		\
			misc.c			\
			xmalloc.c		\
			game/map.c		\
			game/init_map.c		\
			game/game_map.c		\
			game/game.c		\
			game/scene.c		\
			game/event.c		\
			game/game_logic.c	\
			game/entity/entity.c	\
			game/entity/player.c	\
			game/entity/monster.c	\
			game/entity/item.c	\
			graphics/surface.c	\
			graphics/init.c		\
			graphics/graphics.c	\
			graphics/camera.c	\
			list/list_info.c	\
			list/list_mod_push.c	\
			list/list_mod_del.c  	\
			list/list_get.c

SRC		:=	$(addprefix $(SRCDIR), $(SRC))

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)


$(NAME):        $(OBJ)
		$(CC) $^ -o $(NAME) $(LDFLAGS)

%.o: %.c
	        $(CC) -c $< -o $@ $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

ex:		$(NAME)
		$(NAME)

depend:
		@makedepend -- $(CFLAGS) -- -Y $(SRC) 2> /dev/null

.SUFFIXES:

.PHONY:		clean, fclean
# DO NOT DELETE
