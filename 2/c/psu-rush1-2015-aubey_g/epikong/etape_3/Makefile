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
PNAME		=	epikong_etape_3


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

LDFLAGS		+=	-lSDL -lSDL_ttf

# Debug / Release
ifeq ($(DEBUG),yes)
		CFLAGS	+=  -g3
		NAME = $(DEBUG_DIR)/$(PNAME)
		CC = gcc -DDEBUG
else
		NAME = $(RELEASE_DIR)/$(PNAME)
		CC = gcc -DNDEBUG
endif

ifeq ($(shell getconf LONG_BIT),64)
	FMOD	=	api/lib/libfmodex64.so -pthread
else
	FMOD	=	api/lib/libfmodex.so -pthread
endif

RM		=	rm -rf

SRC		=	main.c	 		\
			misc.c			\
			sound/sound.c		\
			sound/sound_init.c	\
			game/map.c		\
			game/init_map.c		\
			game/game_map.c		\
			game/game.c		\
			game/scene.c		\
			game/event.c		\
			game/game_logic.c	\
			game/update_camera.c	\
			game/menu.c		\
			game/gui.c		\
			game/animation.c	\
			game/collision.c	\
			game/manage_event_item.c \
			game/player_collision.c \
			game/entity/entity.c	\
			game/entity/player.c	\
			game/entity/monster.c	\
			game/entity/item.c	\
			game/entity/entity_update.c \
			graphics/surface.c	\
			graphics/load_sprites.c	\
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
		$(CC) $^ -o $(NAME) $(LDFLAGS) $(FMOD)

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
