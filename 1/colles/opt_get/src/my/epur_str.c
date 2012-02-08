/*
** epur.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 20:04:13 2011 tracy nelcha
** Last update Mon May  9 20:26:08 2011 tracy nelcha
*/

#include	"my_strlen.c"
#include	"xfunc.h"
#include	"epur_str.h"

char		*epur_str(char *str)
{
  int		i;
  int		j;
  char		*string;

  i = 0;
  j = 0;
  string = malloc(sizeof(string) * my_strlen(str));
  while (str[i])
  {
    while (str[i] && IS_SEP(str[i]))
      i++;
    while (str[i] && !IS_SEP(str[i]))
      string[j++] = str[i++];
    if (str[i])
      string[j++] = ' ';
  }
  if (IS_SEP(str[j - 1]))
    string[j - 1] = 0;
  return (string);
}
