##
## Makefile for minishell2 in /home/hervet_g/work/unix/minishell2
##
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
##
## Started on  Wed Feb 16 10:45:14 2011 geoffrey hervet
## Last update Wed Feb 16 10:45:14 2011 geoffrey hervet
##

SERVEUR	=	serveur
CLIENT	=	client

all:		$(SERVEUR)r $(CLIENT)r

$(SERVEUR)r:
		$(MAKE) -C ./srv
		cp ./srv/$(SERVEUR) .

$(CLIENT)r:
		$(MAKE) -C ./clt
		cp ./clt/$(CLIENT) .

fclean:
		$(MAKE) fclean -C ./clt
		$(MAKE) fclean -C ./srv
		rm -f $(SERVEUR) $(CLIENT)
clean:
		$(MAKE) clean -C ./clt
		$(MAKE) clean -C ./srv

re:		fclean all

.PHONY:		all clean fclean re dolib norme
