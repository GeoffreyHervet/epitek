/*
** calloc.c for src in /home/hervet_g/malloc/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Feb 01 12:13:03 2012 geoffrey hervet
** Last update Wed Feb 01 12:13:03 2012 geoffrey hervet
*/

#include	"malloc.h"
#include	"calloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  return malloc(nmemb * size);
}
