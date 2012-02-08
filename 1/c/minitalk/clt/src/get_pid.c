/*
** get_pid.c for src in /home/hervet_g/work/unix/minitalk/client/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Mar 12 13:25:32 2011 geoffrey hervet
** Last update Sat Mar 12 13:25:32 2011 geoffrey hervet
*/

#include	"client.h"

#include	"get_pid.h"

extern t_infos	*infos;

int		get_pid(char *str)
{
  if (!*str)
    return (0);
  if (*str < '0' || *str > '9')
    return (-1);
  if (infos->pid > (infos->pid * 10 + *str - '0'))
    return (-1);
  infos->pid = infos->pid * 10 + *str - '0';
  return (get_pid(str + 1));
}
