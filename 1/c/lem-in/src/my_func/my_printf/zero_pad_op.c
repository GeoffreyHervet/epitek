/*
** zero_pad_op.c for zero_pad_op in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Nov 19 13:06:06 2010 tom-brent yau
** Last update Sat Nov 20 17:31:24 2010 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	zero_pad_op(t_option *option)
{
  option->zero_pad = 1;
}
