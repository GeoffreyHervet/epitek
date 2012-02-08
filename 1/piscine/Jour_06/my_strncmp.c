/*
** my_strncmp.c for my_strncmp in /home/hervet_g//afs/rendu/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Oct 12 22:04:55 2010 geoffrey hervet
** Last update Tue Oct 12 22:05:45 2010 geoffrey hervet
*/

int     my_strncmp(char *s1, char *s2, int n);
{
  while (*(s1) && n--)
    {
      if (*(s1) < *(s2))
	return (-1);
      if (*(s1) > *(s2))
        return (1);
      *(s1++);
      *(s2++);
    }
  return (0);
}
