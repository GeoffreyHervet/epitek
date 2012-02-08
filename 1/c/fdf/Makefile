##
## Makefile for tp in /home/hervet_g//work/tp/libx/tp_1/1
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov 12 14:05:23 2010 geoffrey hervet
## Last update Wed Dec  8 16:20:29 2010 geoffrey hervet
##

SRC_PATH=	./src/

NAME	=	fdf

SRC	=	$(SRC_PATH)main.c		\
		$(SRC_PATH)load_file.c		\
		$(SRC_PATH)load_points.c	\
		$(SRC_PATH)draw_line.c		\
		$(SRC_PATH)put_pix.c		\
		$(SRC_PATH)get_next_line.c	\
		$(SRC_PATH)is.c			\
		$(SRC_PATH)set.c		\
		$(SRC_PATH)char_to_int.c	\
		$(SRC_PATH)list.c		\
		$(SRC_PATH)linker.c		\
		$(SRC_PATH)draw_points.c

# libX
CFLAGS	+=	-I/usr/local/include  -L/usr/local/lib -L/usr/lib/ -lmlx_$(OSTYPE) -lX11 -lXext

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic
CFLAGS	+=	-I./inc
CFLAGS	+=	-g3

CC	=	gcc
RM	=	rm -f
FIND	=	find

EDIT	=	$(EDITOR) -nw

OBJ	=	$(SRC:.c=.o)

COMPIL	=	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMPIL)

clean:
		@printf "~> "
		$(RM) $(OBJ)
		@printf "~> "
		$(FIND) . -name "*#*#" -exec $(RM) {} \;
		@printf "~> "
		$(FIND) . -name "*~"   -exec $(RM) {} \;

fclean:		clean
		@printf "~> "
		$(RM) $(NAME)

re:		fclean $(NAME)

edit:
		@printf "~> "
		$(EDIT) ./Makefile

.PHONY:		all clean fclean re edit