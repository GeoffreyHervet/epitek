##
## Makefile for  in /home/hervet_g/nmobjdump-2015-2014s-hervet_g
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Sun Mar 11 16:35:37 2012 geoffrey hervet
## Last update Sun Mar 11 16:35:39 2012 geoffrey hervet
##

BIN1	=	my_objdump
DIR1	=	$(shell pwd)/sources/objdump

BIN2	=	my_nm
DIR2	=	$(shell pwd)/sources/nm

all:		$(BIN1)r $(BIN2)r

$(BIN1)r:
		$(MAKE) -C $(DIR1) && cp $(DIR1)/$(BIN1) .

$(BIN2)r:
		$(MAKE) -C $(DIR2) && cp $(DIR2)/$(BIN2) .

fclean:
		$(MAKE) fclean -C $(DIR1)
		$(MAKE) fclean -C $(DIR2)
		rm -f $(BIN1) $(BIN2)
clean:
		$(MAKE) clean -C $(DIR1)
		$(MAKE) clean -C $(DIR2)

re:		fclean all

.PHONY:		all clean fclean re
