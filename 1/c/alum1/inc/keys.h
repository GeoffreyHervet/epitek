/*
** keys.h for alum1 in /u/all/hervet_g/rendu/c/alum1
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 21:40:09 2011 geoffrey hervet
** Last update Fri Feb 11 21:52:27 2011 geoffrey hervet
*/

#ifndef	__KEYS_H__
# define __KEYS_H__

int	_key_down(t_game *game);
int	_key_up(t_game *game);
int	_key_right(t_game *game);
int	_key_left(t_game *game);
int	_key_select(t_game *game);
int	_key_valid(t_game *game);

# define		DEC_LEFT (NB_FLOORS - 1 - game->c_row)
# define		COL_DEC (game->c_col - DEC_LEFT)
# define		CUR_FLO (game->floors[game->c_row])
# define		COL	(game->c_col)
# define		ROW	(game->c_row)

#endif
