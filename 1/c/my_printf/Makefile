##
## Makefile for lib in /home/hervet_g//work/projets/c/bsq/lib
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov 12 21:55:00 2010 geoffrey hervet
## Last update Sun Nov 21 02:47:33 2010 geoffrey hervet
##

NAME_M	=	`uname -m`
NAME_S	=	`uname -s`

NAME	=	my_printf_$(NAME_M)-$(NAME_S).a

INC_PATH =	./include

SRC	=	./src/my_printf_putchar.c	\
		./src/my_printf_putstr.c	\
		./src/my_printf_putnbr.c	\
		./src/my_printf_putoct.c	\
		./src/my_printf_puthex.c	\
		./src/my_printf_putbin.c	\
		./src/my_printf_putstra.c	\
		./src/my_printf_putptr.c	\
		./src/my_printf_putuns.c	\
		./src/my_printf_adv_flag_process.c \
		./src/my_printf.c

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-Wstrict-prototypes -Wmissing-declarations
CFLAGS	+=	-ansi -pedantic

CFLAGS	+=	-I$(INC_PATH)

OBJ     =       $(SRC:.c=.o)

FIND	=	find .
RM      =       rm -f
AR	=	ar rc
RANLIB	=	ranlib

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)

clean:
		$(RM) $(OBJ)
		$(FIND) -path "*#*#" -exec $(RM) {} \;
		$(FIND) -path "*~"   -exec $(RM) {} \;

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re