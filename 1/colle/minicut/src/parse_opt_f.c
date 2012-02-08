/*
** parse_opt_f.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 19:33:23 2011 geoffrey hervet
** Last update Tue May 17 21:31:21 2011 tracy nelcha
*/

#include	<stdlib.h>

#include	"types.h"

#include	"my_putstr.h"
#include	"my_strlen.h"
#include	"my_strdec.h"
#include	"parse_opt_f.h"
#include	"print_error.h"

static int	insert_item(t_opt_f **begin, int nb1, int nb2)
{
  t_opt_f	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (print_error("Error : malloc can't perform...\n", 0));
  tmp->next = *begin;
  *begin = tmp;
  tmp->delim[0] = (nb1 < nb2) ? nb1 : nb2;
  tmp->delim[1] = (nb1 < nb2) ? nb2 : nb1;
  return (1);
}

static int	getnbr(const char *str, const int max)
{
  int		ret;
  int		idx;

  ret = 0;
  idx = 0;
  while (idx < max)
  {
    ret = (ret * 10) + (str[idx++] - '0');
    if (ret < 0)
      return (-1);
  }
  return (ret);
}

static int	insert_number(char *str, t_opt_f **begin)
{
  int		idx;
  int		nb[2];

  idx = 0;
  while (IS_DIGIT(str[idx]))
    idx++;
  if ((nb[0] = getnbr(str, idx)) == -1)
    return (-1);
  my_strdec(str, idx + 1);
  if (*str == ',' || !*str)
  {
    return (insert_item(begin, nb[0], nb[0]));
  }
  idx = 0;
  while (IS_DIGIT(str[idx]))
    idx++;
  if (str[idx] == '-')
    return (print_error("in option -c : bad formatage ...\n", 0));
  if ((nb[1] = getnbr(str, idx)) == -1)
    return (-1);
  my_strdec(str, idx + 1);
  return (insert_item(begin, nb[0], nb[1]));
}

t_opt_f	  	*parse_opt_f(char *str)
{
  t_opt_f	*begin;
  int		idx;

  begin = NULL;
  idx = 0;
  while (str[idx])
  {
    if (!IS_DIGIT(str[idx]) && str[idx] != ',' && str[idx] != '-')
    {
      my_putstr("In option -c, an error occured : " WRONG_FORMAT "\n", 2);
      return (NULL);
    }
    idx++;
  }
  while (*str && (idx = insert_number(str, &begin)) == 1);
  if (idx == -1)
    my_putstr("In option -c, an error occured : interger overflow\n", 2);
  return (begin);
}
