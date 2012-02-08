/*
** colle2-5.c for  in /home/ouelja_y//afs/rendu/piscine/colles/Semaine_02
** 
** Made by yacine ouelja
** Login   <ouelja_y@epitech.net>
** 
** Started on  Sat Oct 16 14:33:15 2010 yacine ouelja
** Last update Sat Oct 16 18:03:02 2010 geoffrey hervet
*/

int	my_power(int nb, int power)
{
  int	res;

  res = 1;
  while (power > 0)
    {
      res = res * nb;
      power = power - 1;
    }
  return (res);
}

void	aller(char *str, int esp_max, int u)
{
  int	esp_tot;
  int	esp_av;
  int	count;

  count = 0;
  while (count < esp_max)
    {
      esp_av = 0;
      esp_tot = 0;
      while (esp_av < count)
	{
	  my_putchar(' ');
	  esp_av = esp_av + 1;
	  esp_tot = esp_tot + 1;
	}
      my_putchar('*');
      while ((esp_tot + 1) < esp_max)
	{
	  my_putchar(' ');
	  esp_tot = esp_tot + 1;
	}
      count = count + 1;
      my_putstr2(str);
      usleep(u);
    }
}

void	retour(char *str, int esp_max, int u)
{
  int	esp_av;
  int	esp_tot;
  int	count;

  esp_tot = esp_max;
  while (esp_tot > 0)
    {
      count = 0;
      esp_av = 0;
      while (esp_av < esp_tot)
	{
	  my_putchar(' ');
	  esp_av = esp_av + 1;
	  count = count + 1;
	}
      my_putchar('*');
      while ((count + 1) < esp_max)
	{
	  my_putchar(' ');
	  count = count + 1;
	}
      esp_tot = esp_tot - 1;
      my_putstr(str);
      my_putstr(" \r");
      usleep(u);
    }
}
      
void	colle2_5(char *str, int esp_max, int u)
{
  int	count;

  count = 0;
  esp_max = esp_max - my_strlen(str);
  while (count < esp_max)
    {
      aller(str, count + 1, u);
      my_putchar('\r');
      retour(str, count, u);
      count = count + 1;
    }
  while (1)
    {
      aller(str, count, u);
      my_putchar('\r');
      retour(str, count, u);
    }
}

int	main(int argc, char **argv)
{
  if (argc < 3 || (my_getnbr(argv[2]) <= my_strlen(argv[1])))
    {
	  my_putstr("Call error, please type : \n");
	  my_putstr(argv[0]);
	  my_putstr(" string wall_size \nwith wall_size > string length + 1\n");
	  return (0);
    }
  if (argc == 3)
    colle2_5(argv[1] , my_getnbr(argv[2]), 50000);
  else
    colle2_5(argv[1] , my_getnbr(argv[2]), my_getnbr(argv[3]));
  return (0);
}
