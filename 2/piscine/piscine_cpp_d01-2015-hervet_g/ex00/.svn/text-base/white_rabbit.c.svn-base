/*
** white_rabbit.c for d01 in /home/hervet_g/piscine/d01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Jan 04 10:46:36 2012 geoffrey hervet
** Last update Wed Jan 04 10:46:36 2012 geoffrey hervet
*/

#include <stdlib.h>
#include <stdio.h>

int		follow_the_white_rabbit(void)
{
  int		de;
  int		sum = 0;

  do
  {
    if (sum > 397)
      break;
    de = random() % 37 + 1;
    sum += de;

    if (de == 37)
      break;

    if (de == 10 || de == 15 || de == 23)
      printf("devant\n");
    else if ((de >= 4 && de <= 6) || (de >= 17 && de <= 21) || de == 28)
      printf("gauche\n");
    else if (de == 26 || !(de % 8))
      printf("derriere\n");
    else if (de == 13 || (de >= 34 && de <= 36))
      printf("droite\n");
  } while (de != 1 && de != 37);
  printf("LAPIN !!!\n");
  return sum;
}
