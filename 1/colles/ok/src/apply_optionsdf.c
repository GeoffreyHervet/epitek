/*
** apply_optionsdf.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 22:35:55 2011 geoffrey hervet
** Last update Tue May 17 22:35:55 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"apply_optionsdf.h"
#include	"option_f.h"
#include	"my_strlen.h"

static int	count_word(char *str, char del)
{
  int		ret;
  int		idx;

  ret = 1;
  idx = 0;
  while (str[idx])
  {
    if (str[idx++] == del)
      ret++;
  }
  return (0);
}

static void	fill_wtab(char **ptr, int deb, int end, char *str)
{
  int		idx;

  idx = 0;
  if ((*ptr = malloc(sizeof(**ptr) * (end - deb + 1))) == NULL)
    return ;
  while (deb < end)
    (*ptr)[idx++] = str[deb++];
  (*ptr)[idx] = 0;
    
}

static char	**wtab(char *str, char del)
{
  int		nb_word;
  char		**ret;
  int		word;
  int		idx;
  int		idx2;
  
  nb_word = count_word(str, del);
  if ((ret = malloc(sizeof(*ret) * (nb_word + 1))) == NULL)
    return (NULL);
  word = 0;
  idx = 0; 
  idx2 = 0; 
  while (str[idx])
  {
    if (str[idx] == del)
    {
      fill_wtab(&(ret[word++]), idx2, idx, str);
      idx2 = idx + 1;
    }
    idx++;
  }
  ret[word] = NULL;
  return (ret);
}

int	  	apply_optionsdf(t_infos *inf, char *tmp, char d)
{
  char	  	**tab;
  t_opt_f	*optf;

  if ((tab = wtab(tmp, d)) == NULL)
    return (1);
  optf = inf->opt_f;
  return (0);
}
