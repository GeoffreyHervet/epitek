/*
** serv.h for inc in /home/hervet_g/work/unix/minitalk/serveur/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  ven. mars 11 17:40:55 2011 geoffrey hervet
** Last update ven. mars 11 17:40:55 2011 geoffrey hervet
*/

#ifndef __SERV_H__
# define __SERV_H__

typedef struct
{
  int		receive;
  int		dec;
  int		client;
  int		have_quit;
}		t_infos;

#endif /* !__SERV_H__ */
