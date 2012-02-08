/*
** my_putstr.c for my_putstr in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 11:49:52 2010 tom-brent yau
** Last update Fri Mar 25 02:04:04 2011 tom-brent yau
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"my_printf.h"

void	my_putstr_p(char *str, t_option *option)
{
  int	pos;

  pos = 0;
  while (str[pos])
    my_putchar_p(str[pos++], option);
}
