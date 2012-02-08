prod		=	prod
perenoel	=	perenoel

CFLAGS		+=	-W -Wall -Werror

RM		=	rm -f
FIND		=	find
CC		=	g++

SRCDIR		=	src

SRC		=	Carton.cpp		\
			ElfDePePeNoel.cpp	\
			Emballage.cpp 		\
			Jouet.cpp		\
			Nounours.cpp		\
			Objet.cpp		\
			PapierCadeau.cpp	\
			PetitPoney.cpp		\
			TablePePeNoel.cpp 	\
			TapisRoulantPePeNoel.cpp\
			serialize.cpp		\
			TableAleat.cpp		\
			TapisRoulantAleat.cpp

SRC_prod	=	$(SRC) main.cpp
SRC_perenoel	=	$(SRC) perenoel.cpp

SRCS_prod	=	$(addprefix $(SRCDIR)/,$(SRC_prod))
SRCS_perenoel	=	$(addprefix $(SRCDIR)/,$(SRC_perenoel))

OBJS_prod	=	$(SRCS_prod:.cpp=.o)
OBJS_pepenoel	=	$(SRCS_perenoel:.cpp=.o)

PERCENT		=	.percent.sh
PERCENT		=	./.percent.out

ifeq ($(verbose),1)
  AFF		=\n
else
  AFF		=\r
endif

ASCII_ART	= 	@cat .make_msg 2>/dev/null
ifeq ($(noascii),1)
  ASCII_ART	=
endif

ifeq ($(debug),1)
  CFLAGS	+=	-g3
endif

ifeq ($(trace),1)
  CFLAGS	+=	-D TRACE
endif

all:		$(prod) $(perenoel)


$(prod):	$(OBJS_prod)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		$(CC) -o $(prod) $(OBJS_prod) $(LDFLAGS)
		@printf "\033[00m"

$(perenoel):	$(OBJS_pepenoel)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		$(CC) -o $(perenoel) $(OBJS_pepenoel) $(LDFLAGS)
		@printf "\033[00m"

all:		$(NAME)
		$(ASCII_ART)


%.o:		%.cpp
		@printf "\033[00m[%02d%%][\033[36m$<\033[00m]%50s\033[031m$(AFF)" `$(PERCENT) $@ $(OBJS_prod)`
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS_prod) $(OBJS_pepenoel)
		@echo "Object removed !"

fclean:		clean
		@$(RM) $(prod) $(perenoel)
		@echo "$(prod) & $(perenoel) deleted !"

re:		fclean all

.PHONY:		all clean fclean re
