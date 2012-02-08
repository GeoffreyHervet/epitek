/*
** my_prinf.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Nov 17 02:08:26 2010 geoffrey hervet
** Last update Sun Nov 21 02:14:23 2010 geoffrey hervet
*/

#include	<stdarg.h>
#include	<unistd.h>
#include	<stdlib.h>

#include	"libmy_printf.h"
#include	"my.h"

t_funct		funct_prt[] =
  {
    {'b', my_printf_putbin},
    {'c', my_printf_put_char},
    {'d', my_printf_putnbr},
    {'i', my_printf_putnbr},
    {'o', my_printf_putoct},
    {'p', my_printf_putptr},
    {'s', my_printf_putstr},
    {'S', my_printf_putstra},
    {'u', my_printf_putuns},
    {'x', my_printf_puthexl},
    {'X', my_printf_puthexu},
    {'+', my_printf_putplus},
    { 0 , NULL}
  };

static void	my_printf_exec_flag(t_params *params)
{
  int		idx;

  idx = 0;
  while (funct_prt[idx].flag)
    {
      if (funct_prt[idx].flag == params->str[params->idx_str + 1])
	{
	  params->idx_str++;
	  funct_prt[idx].function(params);
	  return ;
	}
      ++idx;
    }

  if (adv_flag_process(params))
    return ;

  my_printf_putchar(PRTF_FLAG);
  my_printf_putchar(params->str[params->idx_str + 1]);
  params->char_printed += 2;
  params->idx_str++;
}

static void	my_printf_do(t_params *params)
{
  while (params->str[params->idx_str])
    {
      if (params->str[params->idx_str] == PRTF_FLAG)
	{
	  if (!params->str[params->idx_str + 1] ||
	      params->str[params->idx_str] == params->str[params->idx_str + 1])
	    {
	      my_printf_putchar(params->str[params->idx_str++]);
	      params->char_printed++;
	    }
	  else
	    my_printf_exec_flag(params);
	}
      else
	{
	  my_printf_putchar(params->str[params->idx_str]);
	  params->char_printed++;
	}
      params->idx_str++;
    }
}

static t_params	*init_params(char *str)
 {
  t_params	*params;

  params = malloc(sizeof(*params));
  if (params == NULL)
    return (NULL);

  params->adv_flag = " #.+-0123456789l";
  params->str = str;

  params->char_printed = 0;
  params->idx_str = 0;

  return (params);
}

int		my_printf(char *str, ...)
{
  t_params	*params;

  if (!str)
    return (0);
  if (str == NULL || !str[0])
    return (0);

  if ((params = init_params(str)) == NULL)
    return (-1);
  va_start(params->args, str);
  my_printf_do(params);
  va_end(params->args);

  return (params->char_printed);
}
