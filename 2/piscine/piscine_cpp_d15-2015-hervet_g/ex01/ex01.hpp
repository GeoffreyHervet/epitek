/*
** ex01.h for ex01 in /home/hervet_g/piscine/piscine_cpp_d15-2015-hervet_g/ex01
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Wed Jan 18 10:15:00 2012 geoffrey hervet
** Last update Wed Jan 18 10:15:00 2012 geoffrey hervet
*/

#ifndef   __EX01_H__
# define  __EX01_H__

#include	<cstring>

template<typename T>
int		compare(T const &a, T const &b)
{
  if (a == b)
    return 0;
  if (a < b)
    return -1;
  return 1;
}


template<>
int		compare<const char *>(const char * const &a,  const char * const &b)
{
  int		ret = strcmp(a, b);

  if (ret < 0)
    ret = -1;
  else if (ret > 0)
    ret = 1;
  return ret;
}

#endif     /* !__EX01_H__ */
