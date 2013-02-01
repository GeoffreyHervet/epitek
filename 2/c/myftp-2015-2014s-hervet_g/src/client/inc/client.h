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

typedef struct
{
   char		*ip;
   int		port;
   int		fd;
}		t_client;

#if 0
  dprintf(fd, "Hello\n");
  k[read(fd, k, 199)] = 0;
  printf("Readed: [%s]\n", k);
  close(fd);
  return (EXIT_SUCCESS);
#endif

#endif /* CLIENT_H_ */
