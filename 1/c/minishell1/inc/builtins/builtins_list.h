/*
** builtins_list.h for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec 20 16:40:39 2010 geoffrey hervet
** Last update Wed Jan  5 15:15:00 2011 geoffrey hervet
*/

#ifndef			__BUILTINS_LIST_H__
#  define		__BUILTINS_LIST_H__

#  ifndef		NULL
#    error		NULL is not defined
#  endif

typedef struct		s_builtins
{
  char			*name;
  int			(*func)(t_base *);
}			t_builtins;

static t_builtins	builtins_all[] =
  {
    {"cd", cd},
    {"env", _env},
    {"unsetenv", _unsetenv},
    {"setenv", _setenv},
    {NULL, NULL}
  };

#endif			/* !__BUILTINS_LIST_H__ */
