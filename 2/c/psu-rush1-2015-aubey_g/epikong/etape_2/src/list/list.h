/*
** list.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:18 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:18 2012 geoffroy aubey
*/

#ifndef LIST_H_
# define LIST_H_

/*
** Types
*/

typedef enum e_bool
{
    FALSE,
    TRUE
}            t_bool;

typedef struct  s_node
{
    void	    *value;
    struct s_node   *next;
}               t_node;

typedef t_node   *t_list;

# define END (void *)0
# define NEXT(x) ((x) = (x)->next)

/*
** Functions
*/

/* Informations */

unsigned int    list_get_size(t_list list);
t_bool          list_is_empty(t_list list);

typedef void    (*t_displayer)(void *value);
void            list_dump(t_list list, t_displayer displayer);

/* Modification */

t_bool  list_push_front(t_list *front_ptr, void *elem);
t_bool  list_push_back(t_list *front_ptr, void *elem);
t_bool  list_push_position(t_list *front_ptr, void *elem,
                           unsigned int position);

t_bool  list_del_front(t_list *front_ptr);
t_bool  list_del_back(t_list *front_ptr);
t_bool  list_del_position(t_list *front_ptr, unsigned int position);
t_bool  list_del_value(t_list *front_ptr, void *value);

void    list_clear(t_list *front_ptr);

/* Value Access */

void	 *list_get_front(t_list list);
void	 *list_get_back(t_list list);
void	 *list_get_position(t_list list, unsigned int position);

/* Node Access */

typedef int (*t_comparator)(void *first, void *second);
t_node  *list_get_first_value(t_list list, void *value, t_comparator comp);

#endif /* !LIST_H_ */
