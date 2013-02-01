/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#ifndef MOVE_H_
# define MOVE_H_

# include		"lemipc.h"

# define TAB_SIZE	(sizeof(tab) / sizeof(*tab))

int			move(t_process_infos *);

typedef int (*tmp)(t_process_infos *);

#endif /* MOVE_H_ */
