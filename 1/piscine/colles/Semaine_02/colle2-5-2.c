/*
** colle2-5-2.c for  in /home/ouelja_y//afs/rendu/piscine/colles/Semaine_02
** 
** Made by yacine ouelja
** Login   <ouelja_y@epitech.net>
** 
** Started on  Sat Oct 16 14:32:00 2010 yacine ouelja
** Last update Sun Oct 17 09:41:31 2010 geoffrey hervet
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int		c;

  c = 0;
  while (str[c] != 0)
    c = c + 1;
  return (c);
}

void	my_putstr2(char *str)
{
  int	c;

  c = 0;
  while (str[c] != 0)
    {
      my_putchar(str[c]);
      c = c + 1;
    }
  my_putchar('\r');
}

void	my_putstr(char *str)
{
  int	c;

  c = 0;
  while (str[c] != 0)
    {
      my_putchar(str[c]);
      c = c + 1;
    }
}

int	my_getnbr(char *str)
{
  int	largeur_int;
  int	largeur_str;
  int	result;
  int	signe;

  largeur_int = my_strlen(str);
  largeur_str = 0;
  result = 0;
  signe = 1;
  if (str[0] == '-')
    return (0);
  while (largeur_int)
    {
      largeur_int = largeur_int - 1;
      result = result + ((str[largeur_str] - '0') * my_power(10, largeur_int));
      largeur_str = largeur_str + 1;
    }
  return (result * signe);
}

