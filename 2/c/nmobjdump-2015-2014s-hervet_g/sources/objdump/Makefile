NAME		=	my_objdump

COMMON_DIR	=	../commons

CFLAGS		+=	-W -Wall -Werror
CFLAGS		+=	-Iinc/ -I$(COMMON_DIR)

RM		=	rm -f
FIND		=	find
CC		=	gcc

ifeq ($(debug),1)
  CFLAGS	+=	-g3
  LDFLAGS	+=	-g3
endif

SRC		=	main.c	\
			print.c	\
			flags.c

COMMONS		=	get_file_name.c	\
			recognized.c

SRCS		=	$(SRC) $(addprefix $(COMMON_DIR)/,$(COMMONS))

OBJS		=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		@printf "\033[00m"
		@$(ASCII_ART)

all:		$(NAME)

%.o:		%.c
		@$(CC) -o $@ -c $< $(CFLAGS)
		@printf "\033[00m[\033[32mOK\033[00m] \033[36m$<\033[00m\n"

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS)
		@echo "Object removed !"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) deleted !"

re:		fclean all

.PHONY:		all clean fclean re
