##
## Makefile for make_my_printf in /home/yau_t//my_printf
##
## Made by tom-brent yau
## Login   <yau_t@epitech.net>
##
## Started on  Sun Nov 21 14:54:47 2010 tom-brent yau
## Last update Fri Mar 25 02:18:05 2011 tom-brent yau
##

NAME=		libmy_printf_$(shell uname -m)-$(shell uname -s).a

SRC=		call_func.c		\
		disp_space_int.c	\
		disp_space_string.c	\
		disp_space_unsigned.c	\
		disp_zero_int.c		\
		disp_zero_unsigned.c	\
		get_flags.c		\
		get_len.c		\
		hash_option.c		\
		if_param.c		\
		minus_option.c		\
		my_getnbr.c		\
		my_printf.c		\
		my_putchar_p.c		\
		my_putnbr_base.c	\
		my_put_nbr_p.c		\
		my_putstr_p.c		\
		my_strlen.c		\
		my_strlen_unsigned.c	\
		nb_len.c		\
		nb_len_unsigned.c	\
		plus_option.c		\
		space_option.c		\
		type_b.c		\
		type_c.c		\
		type_d.c		\
		type_o.c		\
		type_p.c		\
		type_s.c		\
		type_s_up.c		\
		type_u.c		\
		type_x_down.c		\
		type_x_up.c		\
		zero_pad_op.c

CFLAGS=		-Wall -Wall -ansi -pedantic

AR=		ar
RC=		rc
RANLIB=		ranlib
RM=		rm -f
FIND	=	find

OBJ=		$(SRC:.c=.o)

$(NAME):	$(OBJ)
		@printf "\n\033[00mCompilation with flags : \033[33m%55s\033[33m\n" "$(CFLAGS)"
		@$(AR) $(RC) $(NAME) $(OBJ)
		@$(RANLIB) $(NAME)
		@printf "\n\033[01;32mLibrary is ready to use !\n\n\033[00m"

all:		$(NAME)

%.o:		%.c
		@printf "$(PREFIX)$<\n"
		@$(CC) -o $@ -c $< $(CFLAGS)
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

re:		fclean all
