/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#ifndef GET_TEAM_H_
# define GET_TEAM_H_

# include		"lemipc.h"

unsigned char		get_team_left(t_process_infos *inf);
unsigned char		get_team_right(t_process_infos *inf);
unsigned char		get_team_bottom(t_process_infos *inf);
unsigned char		get_team_top(t_process_infos *inf);

#endif /* GET_TEAM_H_ */
