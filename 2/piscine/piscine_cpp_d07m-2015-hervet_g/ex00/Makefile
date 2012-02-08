##
## Makefile for ex00 in /home/hervet_g/piscine/cpp/ex00
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Mon Jan 09 09:06:20 2012 geoffrey hervet
## Last update Mon Jan 09 09:06:20 2012 geoffrey hervet
##

NAME	=	test

SRCS	=	main.cpp	\
		Federation.cpp	\
		Warpsystem.cpp

CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -Werror

CC	=	g++
RM	=	rm -f
FIND	=	find

OBJ	=	$(SRCS:.cpp=.o)

$(NAME):	$(DEP_MY) $(DEP_CWD) $(DEP_GNL) $(OBJ)
		@printf "\n\033[00mCompilation with flags : \033[33m%55s\033[33m\n" "$(CFLAGS)"
		@printf "\033[00mLinkage with flags : \033[33m%59s\033[31m\n" "$(LDFLAGS)"
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\n\033[01;32mSucces !\n\n\033[00m"

all:		$(NAME)

%.o:		%.cpp
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
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re dolib

