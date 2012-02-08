NAME		=	avm

CFLAGS		+=	-W -Wall -Werror

RM		=	rm -f
FIND		=	find
CC		=	g++

SRCDIR		=	src

SRC		=	Stack.cpp	\
			Asm.cpp		\
			utils.cpp	\
			Lexer.cpp	\
			main.cpp



SRCS		=	$(addprefix $(SRCDIR)/,$(SRC))

OBJS		=	$(SRCS:.cpp=.o)

PERCENT		=	./.percent.sh

ifeq ($(verbose),1)
  AFF		=\n
else
  AFF		=\r
endif

ifeq ($(noascii),1)
  ASCII_ART	=
else
  ASCII_ART	= 	@cat .make_msg 2>/dev/null
endif

ifeq ($(debug),1)
  CFLAGS	+=	-g3
  LDFLAGS	+=	-g3
endif

$(NAME):	$(OBJS)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		@printf "\033[00m"
		@$(ASCII_ART)

all:		$(NAME)

%.o:		%.cpp
		@printf "\033[00m[%02d%%][\033[36m$<\033[00m]%50s\033[031m$(AFF)" `$(PERCENT) $@ $(OBJS)`
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS)
		@echo "Object removed !"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) deleted !"

re:		fclean all

.PHONY:		all clean fclean re
