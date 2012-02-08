/*
** builtins_all.h for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec 20 15:40:18 2010 geoffrey hervet
** Last update Wed Jan  5 15:15:14 2011 geoffrey hervet
*/

#ifndef			__BUILTINS_ALL_H__
#  define		__BUILTINS_ALL_H__

int			cd(t_base *base);
int			_env(t_base *base);
int			_unsetenv(t_base *base);
int			_setenv(t_base *base);

#endif			/* !__BUILTINS_ALL_H__ */
