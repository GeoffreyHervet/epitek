NAME		=	../../client

COMMON_DIR	=	../commons
SRC_DIR		=	./src

CFLAGS		+=	-W -Wall -Werror
CFLAGS		+=	-Iinc/ -I$(COMMON_DIR)
CFLAGS		+=  -g3
LDFLAGS		+=  -g3

ifeq (exists, $(shell [ -d /usr/include/editline/ ] && echo exists || echo fail))
  CFLAGS	+=	-I/usr/include/editline/
endif
ifeq (exists, $(shell [ -d /usr/include/readline/ ] && echo exists || echo fail))
  CFLAGS	+=	-I/usr/include/readline/
endif

ifeq (exists,$(shell [ -f /lib64/libreadline.so.6.1 ] && echo exists || echo fail))
  LDFLAGS	+=	/lib64/libreadline.so.6.1
else
  LDFLAGS	+=	-lreadline
endif

RM		=	rm -f
FIND		=	find
CC		=	gcc

ifeq ($(debug),1)
  CFLAGS	+=	-g3
  LDFLAGS	+=	-g3
endif

SRC		=	main.c		\
			init.c		\
			run.c		\
			set_put.c	\
			set_get.c

COMMONS		=	
		

SRCS		=	$(addprefix $(SRC_DIR)/,$(SRC)) $(addprefix $(COMMON_DIR)/,$(COMMONS))

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
