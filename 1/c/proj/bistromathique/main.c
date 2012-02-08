/*
** main.c for bistro in /home/hervet_g//work/projets/c/bistro
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct 29 16:23:59 2010 geoffrey hervet
** Last update Sat Oct 30 16:40:29 2010 geoffrey hervet
*/

#include	"bistromathique.h"
#include	<stdlib.h>
#include	<unistd.h>

static void	check_base(char *base);
static void	check_ops(char *ops);
static char	*get_expr(unsigned size);

int		main(int ac, char **av)
{
  char		*expr;
  unsigned int	size;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len\n");
      exit(1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  expr = get_expr(size = atoi(av[3]));
  my_putstr(eval_expr(av[1], av[2], expr, size));
}

static void	check_base(char *b)
{
 if (my_strlen(b) < 2)
    {
      my_putstr("Bad base\n");
      exit(1);
    }
 return ;
}

static char	*get_expr(unsigned int size)
{
  char	*expr;
  
  if (size <= 0)
    {
      my_putstr("Bad expr len\n");
      exit(1);
    }
  if ((expr = malloc(size + 1)) == 0)
    {
      my_putstr("could not alloc\n");
      exit(1);
    }
  if ((unsigned int) read(0, expr, size) != size)
    {
      my_putstr("could not read\n");
      exit(1);
    }
  expr[size] = 0;
  return (expr);
}

static void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      my_putstr("Bad ops\n");
      exit(1);
    }
}
