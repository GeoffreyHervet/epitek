/*
** menu.h for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 03:59:42 2012 geoffroy aubey
** Last update Sun Mar  4 03:59:42 2012 geoffroy aubey
*/

#ifndef _MENU_H_
# define _MENU_H_

typedef struct s_menu
{
  char	*file_names[5];
  int	cur_selection;
  int	hit;
} t_menu;

int	menu_init(t_menu *menu);
int	draw_menu(t_game *game);
t_menu *create_menu();
int	menu_update(t_menu *menu, t_event *e, int delta);
int	menu_load_map(t_game *g, t_menu *m, char *file_name);

#endif /* !_MENU_H_ */
