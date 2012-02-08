/*
** my_strcmp.c for my_strcmp.c in /home/hervet_g//work/piscine/Jour_06
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Oct 11 15:11:54 2010 geoffrey hervet
** Last update Tue Oct 12 22:39:29 2010 geoffrey hervet
*/

int     my_strcmp(char *s1, char *s2)
{
  while (*(s1))
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
