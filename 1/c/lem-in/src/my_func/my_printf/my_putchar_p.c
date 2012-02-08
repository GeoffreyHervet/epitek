/*
** my_putchar.c for my_putchar in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Nov 14 12:53:23 2010 tom-brent yau
** Last update Fri Mar 25 02:05:10 2011 tom-brent yau
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"my_printf.h"

void	my_putchar_p(char c, t_option *option)
{
  write(1, &c, 1);
  option->char_printed++;
}
