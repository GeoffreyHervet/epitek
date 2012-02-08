/*
** my_swap.c for my in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 22:05:22 2010 geoffrey hervet
** Last update Fri Dec 10 17:54:05 2010 geoffrey hervet
*/

#include	"libmy.h"

void		my_swap(void *left, void *right)
{
  void		*pivot;

  pivot = left;
  left = right;
  right = pivot;
}
