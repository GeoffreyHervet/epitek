/*
** my_strcmp.c for  in /u/all/hervet_g/public/opt_get/src/my
**
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
**
** Started on  Mon May  9 20:11:53 2011 tracy nelcha
** Last update Mon May  9 20:27:21 2011 tracy nelcha
*/

int		my_strcmp(const char *str, const char *str2)
{
  while ((*str) || (*str2))
  {
    if (*str != *str2)
      return ((*str) > (*str2)) ? 1 : -1;
    str++;
    str2++;
  }
  return (0);
}
