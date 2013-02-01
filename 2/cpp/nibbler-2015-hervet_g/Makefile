BIN		= nibbler

LIB1		= Qt
LIB2		= SFML
LIB3		= OpenGL

LIB1_NAME	= lib_nibbler_Qt.so
LIB2_NAME	= lib_nibbler_SFML.so
LIB3_NAME	= lib_nibbler_OGL.so

MAKE		= make
RM		= rm -f
DIR		= proj
DIR_LIBS	= $(DIR)/graphics

MAKE_BIN	= $(MAKE) -C $(DIR)
MAKE_LIB1	= $(MAKE) -C $(DIR_LIBS)/$(LIB1)
MAKE_LIB2	= $(MAKE) -C $(DIR_LIBS)/$(LIB2)
MAKE_LIB3	= $(MAKE) -C $(DIR_LIBS)/$(LIB3)

all: $(BIN) $(LIB1) $(LIB2) $(LIB3)

$(BIN):
	$(MAKE_BIN)

$(LIB1):
	$(MAKE_LIB1)

$(LIB2):
	$(MAKE_LIB2)

$(LIB3):
	$(MAKE_LIB3)

fclean:
	$(RM) $(LIB1_NAME) $(LIB2_NAME) $(LIB3_NAME) $(BIN)
	$(MAKE_BIN)  fclean
	$(MAKE_LIB1) fclean
	$(MAKE_LIB2) fclean
	$(MAKE_LIB3) fclean

clean:
	$(MAKE_BIN)  clean
	$(MAKE_LIB1) clean
	$(MAKE_LIB2) clean
	$(MAKE_LIB3) clean

re: fclean all
