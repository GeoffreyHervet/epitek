/*
** launcher.h for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec 27 14:00:59 2010 geoffrey hervet
** Last update Sun Jan  2 13:59:24 2011 geoffrey hervet
*/

#ifndef		__LAUNCHER_H__
#  define	__LAUNCHER_H__

int		launcher(t_base *base);

#  define	CMD	base->cmd_splited->data
#  define	ERR	my_putstr(CMD, 2);

#endif		/* !__LAUNCHER_H__ */
