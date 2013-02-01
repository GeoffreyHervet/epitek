/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#ifndef SERVER_H_
# define SERVER_H_

typedef struct
{
  int			port;
  int			socket;
  size_t		cwd_len;
  char			*cwd;
}			t_server;

#endif /* SERVER_H_ */
