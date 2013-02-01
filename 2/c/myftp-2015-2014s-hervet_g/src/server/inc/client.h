/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include		<netinet/in.h>

# include		"server.h"

# define		BUFF_LEN	(2048)

typedef struct
{
  struct sockaddr_in	sin;
  t_server		*srv;
  unsigned int		sin_size;
  int			fd;
  unsigned char		quit;
  char			*wd;
}			t_client;

void			client_exec(t_client);

#endif /* CLIENT_H_ */
