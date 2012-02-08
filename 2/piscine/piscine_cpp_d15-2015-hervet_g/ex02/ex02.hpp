/*
** ex02.h for ex02 in /home/hervet_g/piscine/piscine_cpp_d15-2015-hervet_g/ex02
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Wed Jan 18 11:04:12 2012 geoffrey hervet
** Last update Wed Jan 18 11:04:12 2012 geoffrey hervet
*/

#ifndef   __EX02_H__
# define  __EX02_H__

# include	<iostream>

template <typename T>
T		&min(const T &a, const T &b)
{
  std::cout << "template min" << std::endl;
  if (b < a)
    return b;
  return a;
}

int		min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (b < a)
    return b;
  return a;
}

template <typename T>
T		templateMin(const T* tab, size_t size)
{
  T		minVal = tab[--size];

  while (size--)
    minVal = min(tab[size], minVal);
  return minVal;
}

int		nonTemplateMin(const int * tab, size_t size)
{
  int		minVal = tab[--size];

  while (size--)
    minVal = min(tab[size], minVal);
  return minVal;
}

#endif     /* !__EX02_H__ */
