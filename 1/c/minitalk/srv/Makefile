##
## Makefile for minishell2 in /home/hervet_g/work/unix/minishell2
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Wed Feb 16 10:45:14 2011 geoffrey hervet
## Last update Wed Feb 16 10:45:14 2011 geoffrey hervet
##


NAME	=	serveur

SRC	=	main.c		\
		aff_pid.c	\
		receive_msg.c	\
		receive_pid.c

CFLAGS	+=	 -I./inc
CFLAGS	+=	$(DEBUG)
SRCS	=	$(addprefix ./src/,$(SRC))

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRCS:.c=.o)

$(NAME):	$(DEP_MY) $(DEP_CWD) $(DEP_GNL) $(OBJ)
		@printf "\n\033[00mCompilation with flags : \033[33m%55s\033[33m\n" "$(CFLAGS)"
		@printf "\033[00mLinkage with flags : \033[33m%59s\033[31m\n" "$(LDFLAGS)"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\n\033[01;32mSucces !\n\n\033[00m"

all:		$(NAME)

%.o:		%.c
		@printf "\033[00m%-73s\033[31m" "$<"
		@$(CC) -o $@ -c $< $(CFLAGS)
		@printf "\033[01;32m%7s\033[00m\n" "Succes!"

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

norme:
		@printf "\t\t*** O_o The moulinorme is comming ***\n"
		@/u/all/astek/public/norme `$(FIND) .`

.PHONY:		all clean fclean re dolib norme
