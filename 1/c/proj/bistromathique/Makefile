##
## Makefile for Makefile in /u/epitech_2013/wacren_p/cu/public
##
## Made by pierre wacrenier
## Login   <wacren_p@epitech.net>
##
## Started on  Mon Jun  1 17:26:16 2009 pierre wacrenier
## Last update Sat Oct 30 16:50:06 2010 geoffrey hervet
##




SRCS		=	./parsing/operators.c \
			./parsing/bistromathique.c \
			./btree/btree_functions.c \
			./main.c \
			./basic_functions.c \
			./str_functions.c

NAME		=	BistromatiX

CC		=	gcc

RM		=	rm -rf
FIND		=	find

CFLAGS		+=	-W -Wall -Wchar-subscripts -Werror
CFLAGS		+=	-Wimplicit-function-declaration
CFLAGS		+=	-Wmissing-prototypes -Wmissing-declarations
CFLAGS		+=	-Wredundant-decls -Wparentheses -Wreturn-type
CFLAGS		+=	-Wstrict-prototypes -Wpointer-arith
CFLAGS		+=	-Wpacked -Waggregate-return -Wcast-qual -Wcast-align
CFLAGS		+=	-Waggregate-return -Wmissing-noreturn
CFLAGS		+=	-ansi -pedantic

OBJS		=	$(SRCS:.c=.o)

$(NAME):		#$(SRCS) $(OBJS)
			$(CC) -o $(NAME) $(SRCS)

all:			$(NAME)

war:
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
			@$(RM) $(OBJS)
			@$(FIND) . -name "*~" -print -exec rm -f {} \;
			@$(FIND) . -name "*\#*" -print -exec rm -f {} \;
			@$(RM) $(NAME).core

fclean:			clean
			@$(RM) $(NAME)
			@$(RM) TAGS

.PHONY:			clean all fclean
