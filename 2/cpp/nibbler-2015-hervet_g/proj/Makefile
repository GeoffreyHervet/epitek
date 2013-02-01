NAME		=	nibbler

RM		=	rm -f
FIND		=	find
CXX		=	g++
PERCENT		=	./.percent.sh

SRC		=	main.cpp

SRC_CLASS	=	Core.cpp	\
			Opts.cpp	\
			DLLoader.cpp

CXXFLAGS	+=	-W -Wall -Werror  
CXXFLAGS	+=	-I. -Iclass -Iinterfaces 

LXXDFLAGS	+=	-ldl -rdynamic

SRCS		=	$(SRC)
SRCS		+=	$(addprefix class/,$(SRC_CLASS))

OBJS		=	$(SRCS:.cpp=.o)

ifeq ($(verbose),1)
  AFF		=\n
else
  AFF		=\r
endif

ifeq ($(debug),1)
  CXXFLAGS	+=	-g3
  LXXDFLAGS	+=	-g3
endif

ifeq ($(noascii),1)
  ASCII_ART	=
else
  ASCII_ART	= 	@cat .make_msg 2>/dev/null
endif

$(NAME):	$(OBJS)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CXXFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LXXDFLAGS)\033[34m\n"
		@$(CXX) -o $(NAME) $(OBJS) $(LXXDFLAGS)
		@printf "\033[00m"
		@$(ASCII_ART)
		@cp $(NAME) ../

all:		$(NAME)

%.o:		%.cpp
		@printf "\033[00m[%0''''2d%%][\033[36m$<\033[00m]%50s\033[031m$(AFF)" `$(PERCENT) $@ $(OBJS)`
		@$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS)
		@echo "Object removed !"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) deleted !"

re:		fclean all

.PHONY:		all clean fclean re
