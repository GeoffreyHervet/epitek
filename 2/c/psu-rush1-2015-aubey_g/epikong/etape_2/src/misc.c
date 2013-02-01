/*
** misc.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 01:07:32 2012 geoffroy aubey
** Last update Sun Mar  4 01:07:32 2012 geoffroy aubey
*/

#include <stdio.h>
#include "epikong.h"

int	load_error(char *str)
{
  perror(str);
  return (-1);
}
