/*
** my_aff_revalpha.c for my_aff_revalpha in /home/hervet_g//afs/rendu/piscine/Jour_03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct  6 11:53:01 2010 geoffrey hervet
** Last update Wed Oct  6 17:37:28 2010 geoffrey hervet
*/

int		my_aff_revalpha()
{
  static int    start = 122;
  static int    end = 97;
  int           ascii;

  ascii = start;
  end   = end - 1;
  while (end - ascii)
    {
      my_putchar (ascii);
      ascii = ascii - 1;
    }
  return (0);

}
