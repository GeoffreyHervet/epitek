NAME=		plazza
CXX=		clang++
LXX=		g++
FIND=		find
RM=		rm -f

#####################
#      FILES        #
#####################

SRCDIR=		./src
INCDIR=		./inc
LIBDIR=		./lib
CLADIR=		./classes

SRC=		$(SRCDIR)/main.cpp			\
		$(SRCDIR)/Core.cpp			\
		rendering/SDLazy_DrawCircle.cpp		\
		rendering/SDLazy_SetPix.cpp		\
		rendering/strtools.cpp
CLASSES=	
LIBS=		$(LIBDIR)/Pthread/Pthread_Thread.cpp	\
		$(LIBDIR)/Pthread/Pthread_Mutex.cpp	\
		$(LIBDIR)/Pthread/Pthread_CondVar.cpp	\
		$(LIBDIR)/NamedPipe/NamedPipe.cpp


SRCS=		$(CLASSES) $(SRC) $(LIBS)

OBJ=		$(SRCS:.cpp=.o)

#####################
#      FLAGS        #
#####################

CFLAGS+=	-Wall -Wextra
CFLAGS+=	-I$(INCDIR) -I$(LIBDIR) -I$(LIBDIR)/interfaces -Irendering
LDFLAGS=	-lpthread -lSDL

ifdef DEBUG
  CFLAGS+=	-g3 -DDEBUG
else
  CFLAGS+=	-Werror
endif


all:		$(NAME)

$(NAME):	$(OBJ)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		$(LXX) -o $(NAME) $(OBJ) $(LDFLAGS)
		@printf "\033[00m"
ifeq (ok,$(shell which doxygen>/dev/null 2> /dev/null && echo ok))
		@doxygen 2>/dev/null
else
		@echo \`doxygen\` not found
endif

%.o:		%.cpp
		@printf "\033[00m[\033[31mWORKING\033[00m] \033[36m$<\033[00m\r"
		@$(CXX) -o $@ -c $< $(CFLAGS)
		@printf "\033[00m[\033[32mOK\033[00m] \033[36m$<\033[00m              \n"

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJ)
		@echo "Object removed !"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) deleted !"

re:		fclean all

.PHONY:		all clean fclean re
