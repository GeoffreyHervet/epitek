/*
** pi.c for function_pi in /afs/epitech.net/users/epitech_2015/hervet_g/public/Pi/function_pi
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Apr 27 21:11:08 2011 geoffrey hervet
** Last update Wed Apr 27 21:11:08 2011 geoffrey hervet
*/

#include	<stdlib.h>

typedef struct
{
  int		comma_pos;
  int		len;
  int		idx;
  int		nb_after_comma;
  int		nb_before_comma;
}		t_infos;

int		get_comma_pos(const char *str)
{
  int		ret;

  ret = 0;
  while (*str)
  {
    if (*str == ',' || *str == '.')
      return (ret);
    ret++;
    str++;
  }
  return (0);
}

int	  	my_strlen(const char *str)
{
  return (*str ? 1 + my_strlen(str + 1) : 0);
}

void		my_memset(char *str, char value, int len)
{
  while (len > 0)
  {
    *str = value;
    str++;
    len--;
  }
}

void		init_infos(t_infos *inf, const char *str)
{
  inf->len = my_strlen(str);
  inf->comma_pos = get_comma_pos(str);
  inf->idx = inf->len - 1;
  inf->nb_after_comma = (inf->comma_pos) ? inf->len - inf->comma_pos - 1 : 0;
  inf->nb_before_comma = inf->len - !!(inf->comma_pos);
}

void		add(char *s1, char *s2)
{
  t_infos	inf1;
  t_infos	inf2;
  int		idx;
  char		*ret;

  init_infos(&inf1, s1);
  init_infos(&inf2, s2);
  idx = inf1.idx > inf2.idx ? inf1.idx : inf2.idx;
  if (idx < inf2.nb_before_comma + inf2.nb_after_comma)
    idx = inf2.nb_before_comma + inf2.nb_after_comma;
  ret = malloc(sizeof(*ret) * (idx + 1));
  ret[idx] = 0;
  my_memset(ret, '0', idx);
  while (idx > 0)
  {
    idx--;
  }
}
