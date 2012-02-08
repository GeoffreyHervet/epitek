/*
** my_aff_chiffre.c for my_aff_chiffre in /home/hervet_g//afs/rendu/piscine/Jour_03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct  6 13:16:22 2010 geoffrey hervet
** Last update Wed Oct  6 17:37:45 2010 geoffrey hervet
*/

int		my_aff_chiffre()
{
  static int    start = 48;
  static int    end = 57;
  int           now;

  now           = start;
  end           = end + 1;
  while (end - now)
    {
      my_putchar (now);
      now = now + 1;
    }
  return (0);
}
