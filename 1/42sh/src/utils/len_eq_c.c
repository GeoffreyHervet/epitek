/*
** len_eq_c.c for len_eq_c in /home/yau_t//local/Projets/semestre_2/minishell2/main
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Feb 14 15:07:30 2011 tom-brent yau
** Last update Wed Feb 23 20:45:58 2011 quentin rufin
*/

int	len_eq_c(char *str, char *c)
{
  int	pos;
  int	pos2;
  int	ct;

  pos = 0;
  ct = 0;
  while (str[pos] && ct == 0)
    {
      pos2 = 0;
      while (c[pos2] && str[pos] != c[pos2])
	pos2++;
      if (c[pos2])
	pos++;
      else
	ct = 1;
    }
  return (pos);
}
