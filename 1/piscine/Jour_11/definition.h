/*
** definition.h for definitions.h in /home/hervet_g//work/piscine/Jour_11
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 20 13:49:28 2010 geoffrey hervet
** Last update Wed Oct 20 23:24:48 2010 geoffrey hervet
*/

#ifndef		__DEFINITION_H__
#define		__DEFINITION_H__
#define		MALLOC_ERROR_CRITICAL	"Insufficient RAM memory to run the program correctly."

#include	<stdlib.h>

t_list		*my_params_in_list(int ac, char **av);
void		show_t_list(t_list *ptr);
int		my_list_size(t_list *begin);

#endif
