##
## Makefile for makefile in /home/hervet_g//work/projets/c/bistro
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Fri Nov  5 11:18:07 2010 geoffrey hervet
## Last update Wed Jan  5 16:02:50 2011 geoffrey hervet
##

NAME	=	mysh


SRC	=	main.c				\
		errors.c			\
		gnl.c				\
		builtins/is_builtins.c		\
		builtins/exec_builtins.c	\
		builtins/cd.c			\
		builtins/env.c			\
		builtins/setenv.c		\
		builtins/unsetenv.c		\
		builtins/cd_strcat_pwd.c	\
		cmd/get_cmd.c			\
		cmd/exec_cmd.c			\
		cmd/split_cmd.c			\
		cmd/launcher.c			\
		env/save_env.c			\
		env/free_env.c			\
		env/get_env.c			\
		env/set_env.c			\
		env/path_gestion.c		\
		prompt/prompt_set.c	

LIB_MY	=	my_$(shell uname -m)-$(shell uname -s)

LIB	=	$(LIB_MY) 

ifeq ($(shell ls ./lib/lib$(LIB_MY).a | grep -e "^./lib"),)
  EXEC	=	dolib
else
  EXEC	=
endif

# ifndef DEBUG
#   DEBUG	=
# endif

LDFLAGS	+=	-L./lib
LDFLAGS	+=	$(DEBUG)
LDFLAGS	+=	$(addprefix -l,$(LIB))

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-pedantic
CFLAGS	+=	-I./lib -I./inc
CFLAGS	+=	$(DEBUG)

SRCS	=	$(addprefix $(PWD)/src/,$(SRC))

CC	=	gcc
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRCS:.c=.o)

$(NAME):	$(EXEC) $(OBJ)
		@printf "\n\033[00mCompilation with flags : \t\033[33m$(CFLAGS)\n"
		@printf "\033[00mLinkage with flags : \t\t\033[33m$(LDFLAGS) \033[31m\n"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\033[32mSucces !\n\033[00m"

all:		$(NAME)

%.o:		%.c
		@printf "\033[00mLinkage with flags : \t\t\033[33m$(LDFLAGS) \033[31m\n"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\033[32mSucces !\n\033[00m"

all:		$(NAME)

%.o:		%.c
		@printf "\033[00m$<\033[31m\n"
		@$(CC) -o $@ -c $< $(CFLAGS)
		@printf "\033[00m\t\t\t\t\t\t\t\t\t\t\t\t\tDone !\n\033[31m"

dolib:
		@make -C ./lib/my/
		@printf "\t\t*** Lib is compiled ***\n"

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