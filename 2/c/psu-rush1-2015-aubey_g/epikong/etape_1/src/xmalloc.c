/*
** main.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:16 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:16 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *xmalloc(int s)
{
  void *ptr;

  ptr = malloc(s);
  if (ptr == NULL)
  {
    perror("malloc");
    exit(1);
  }
  return (ptr);
}

