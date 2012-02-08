/*
** putcap.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/rendu/c/alum1/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Feb 11 18:50:51 2011 geoffrey hervet
** Last update Fri Feb 11 18:50:51 2011 geoffrey hervet
*/

#include	<unistd.h>

#include	<putcap.h>

int		putcap(int c)
{
  return (write(1, &c, 1));
}
