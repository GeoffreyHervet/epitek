NAME		=	lib_nibbler_OGL.so

RM		=	rm -f
FIND		=	find
CXX		=	g++

SRCS		=	OpenGLObject.cpp

CXXFLAGS	+=	-W -Wall -Werror -fPIC
CXXFLAGS	+=	-I. -I../../class -I../../interfaces
LXXDFLAGS	+=	-lglut -lGL -lGLU -shared

OBJS		=	$(SRCS:.cpp=.o)

$(NAME):	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(LXXDFLAGS)
		@cp $(NAME) ../../../

all:		$(NAME)

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS)
		@echo "Object removed !"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) deleted !"

re:		fclean all

.PHONY:		all clean fclean re
