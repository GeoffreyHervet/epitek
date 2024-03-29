/*
** add.c for  in /u/all/hervet_g/public/Pi/function_pi
**
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
**
** Started on  Wed Apr 27 19:23:02 2011 tracy nelcha
** Last update Wed Apr 27 22:41:07 2011 tracy nelcha
*/

#include	<unistd.h>
#include	<string.h>
#include	"my_putstr.h"
#include	"my_strlen.h"
#include	"xmalloc.h"

int	get_comma_pos(const char *str)
{
  int	ret;

  ret = 0;
  while (*str)
  {
    if (*str == '.' || *str == ',')
      return (ret);
    str++;
    ret++;
  }
  return (0);
}
/*
  void		add(char *str1, char *str2)
  {
    t_infos	inf1;
    t_infos	inf2;
    int		idx;
    char		*ret;

    inf1.idx = my_strlen(str1);
    inf2.idx = my_strlen(str2);
    inf1.comma = get_comma_pos(str1);
    inf2.comma = get_comma_pos(str2);
    idx = (inf1.idx > inf2.idx) ? inf1.idx : inf2.idx;
    ret = xmalloc(sizeof(ret) * (idx + 2));
    ret[idx - 1] = 0;
    while (idx > 0)
    {
      if (idx <= inf1.idx)
        ret[idx] += str1[inf1.idx--] - '0';
      if (idx <= inf2.idx)
        ret[idx] += str2[inf2.idx--] - '0';
      if (ret[idx] >= '9')
      {
        ret[idx] = '0' + (ret[idx] - '0') % 10;
        ret[idx--] = '1';
      }
      if (idx && ((idx == inf1.comma) || (idx == inf2.comma)))
      {
        ret[idx--] = ',';
        if (idx == inf1.comma)
          inf1.idx--;
        if (idx == inf2.comma)
          inf2.idx--;
      }
      idx--;
    }
    write(1, "resultat :", my_strlen("resultat :"));
    my_putstr(ret);
  }
*/

