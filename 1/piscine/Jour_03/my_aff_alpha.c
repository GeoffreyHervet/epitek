/*
** my_aff_alpha.c for my_aff_alpha in /home/hervet_g//afs/rendu/piscine/Jour_03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct  6 11:45:45 2010 geoffrey hervet
** Last update Wed Oct  6 17:34:36 2010 geoffrey hervet
*/

int		my_aff_alpha()
{
  static int    start = 97;
  static int    end = 122;
  int           ascii;

  ascii = start;
  end   = end + 1;
  while (end - ascii)
    {
      my_putchar (ascii);
      ascii = ascii + 1;
    }
  return (0);
}
