/*
** my_aff_comb.c for my_aff_comb in /home/hervet_g//afs/rendu/piscine/Jour_03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct  6 17:49:05 2010 geoffrey hervet
** Last update Thu Oct  7 20:47:49 2010 geoffrey hervet
*/

int	aff_number(int units, int tens, int hundreds)
{
  if (units != tens && units != hundreds && tens != hundreds
      && units > tens && units > hundreds && tens > hundreds)
    {
      my_putchar(48 + hundreds);
      my_putchar(48 + tens);
      my_putchar(48 + units);
      if (hundreds == 7 && tens == 8 && units == 9)
        {
          return (0);
        }
      my_putchar(',');
      my_putchar(' ');
    }
  return (0);
}

int	my_aff_comb()
{
  int   units;
  int   tens;
  int   hundreds;

  units = 0;
  tens = 0;
  hundreds = 0;
  while (hundreds < 10)
    {
      while (tens < 10)
        {
          while (units < 10)
            {
              aff_number(units, tens, hundreds);
              units = units + 1;
            }
          units = 0;
          tens = tens + 1;
        }
      units = 0;
      tens = 0;
      hundreds = hundreds + 1;
    }
  return (0);
}
