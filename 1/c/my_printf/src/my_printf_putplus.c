/*
** my_printf_putplus.c for my_printf in /home/hervet_g//work/projets/c/printf/sources
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Nov 21 02:16:05 2010 geoffrey hervet
** Last update Sun Nov 21 02:24:29 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdarg.h>

#include	"libmy_printf.h"

int	my_printf_putplus(t_params *params)
{
  write(1, "%+", 2);
  va_arg(params->args, int);
  params->char_printed += 2;
  return (1);
}
