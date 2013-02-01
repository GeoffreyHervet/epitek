NAME		=	avm

CFLAGS		+=	-W -Wall -Werror
CFLAGS		+=	-Iinc/
#CFLAGS		+=	-Weffc++

RM		=	rm -f
FIND		=	find
CC		=	g++


SRCDIR		=	src

SRC		=	Stack.cpp		\
			StackInstructions.cpp	\
			utils.cpp		\
			Lexer.cpp		\
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
ifneq ($(TERM),dumb)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		@printf "\033[00m"
		@$(ASCII_ART)
else
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
endif

all:		$(NAME)

%.o:		%.cpp
ifneq ($(TERM),dumb)
		@printf "\033[00m[%0''''2d%%][\033[36m$<\033[00m]%50s\033[031m$(AFF)" `$(PERCENT) $@ $(OBJS)`
		@$(CC) -o $@ -c $< $(CFLAGS)
else
		$(CC) -o $@ -c $< $(CFLAGS)
endif

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS)
		@echo "Object removed !"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) deleted !"

re:		fclean all

##
# Dependencies
##

src/StackInstructions.o : inc/IOperand.hh inc/Operands.hh inc/Stack.hh
src/Lexer.o : inc/Lexer.h inc/utils.h
src/Operands.o : inc/Operands.hh
src/Stack.o : inc/IOperand.hh inc/Operands.hh inc/Stack.hh
src/main.o : inc/Lexer.h inc/Stack.hh
src/utils.o : inc/utils.h inc/Operands.hh
src/IOperand.hh :
src/Lexer.h : inc/macros.h
src/Operands.hh : inc/IOperand.hh inc/Stack.hh inc/utils.h
src/Stack.hh : inc/IOperand.hh inc/Lexer.h
src/macros.h :
src/msg.h :
src/utils.h : inc/IOperand.hh

.PHONY:		all clean fclean re
