/*
** pars_keys.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Mon May  2 17:39:43 2011 silvain tuilliere
** Last update Sun May 22 21:53:43 2011 silvain tuilliere
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtgetstr.h"

const t_ctrl	ctrl[8] = {
  {CTRL_T, &gere_ctrl_t},
  {CTRL_L, &gere_ctrl_l},
  {CTRL_E, &move_cursor_end},
  {CTRL_A, &move_cursor_home},
  {CTRL_K, &gere_ctrl_k},
  {CTRL_W, &gere_ctrl_w},
  {CTRL_U, &gere_ctrl_u},
  {CTRL_Y, &gere_ctrl_y}
};

static void	init_tab(t_tab tab_[7])
{
  tab_[0].keys = xtgetstr("kl");
  tab_[1].keys = xtgetstr("kr");
  tab_[2].keys = xtgetstr("kD");
  tab_[3].keys = xtgetstr("kh");
  tab_[4].keys = xtgetstr("@7");
  tab_[5].keys = xtgetstr("ku");
  tab_[6].keys = xtgetstr("kd");
  tab_[0].ptr = &move_cursor_left;
  tab_[1].ptr = &move_cursor_right;
  tab_[2].ptr = &del_key;
  tab_[3].ptr = &move_cursor_home;
  tab_[4].ptr = &move_cursor_end;
  tab_[5].ptr = &up_history;
  tab_[6].ptr = &down_history;
}

int     pars_keys(t_termcp *termcp, char *result, char *buffer, t_inf *infos)
{
  int	count;
  t_tab	tab_[7];

  count = 0;
  if (*buffer >= 32 && *buffer != 127)
    return (1);
  init_tab(tab_);
  while (count < 8 && ctrl[count].key != buffer[0])
    count++;
  if (count < 8)
    {
      ctrl[count].ptr(infos, termcp, result);
      return (0);
    }
  count = 0;
  while (count < 7 && (tab_[count].keys[0] != buffer[0] ||
		       tab_[count].keys[2] != buffer[2]))
    ++count;
  if (count < 7)
    tab_[count].ptr(infos, termcp, result);
  else if (*buffer == 127)
    back_key(infos, termcp, result);
  else if (*buffer == '\t')
    tab_key(infos, termcp, result);
  return (0);
}
