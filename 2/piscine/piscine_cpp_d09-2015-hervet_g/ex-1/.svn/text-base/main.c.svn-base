/*
** main.c for ex-1 in /home/hervet_g/piscine/ok/ex-1
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 12 10:32:09 2012 geoffrey hervet
** Last update Thu Jan 12 10:32:09 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	"Exo-1.h"

int main()
{
  t_koala* _LKoala = NewKoala("Legend", 1);
  t_koala* _NLKoala = NewKoala("NotLegend", 0);

  t_cthulhu* _cthulhu = NewCthulhu();

  printf("----Start----\n");

  PrintPower(_cthulhu);
  PrintPower(&_LKoala->m_parent);
  PrintPower(&_NLKoala->m_parent);

  Attack(_cthulhu);
  Attack(&_LKoala->m_parent);
  Attack(&_NLKoala->m_parent);

  Eat(_NLKoala);

  Attack(_cthulhu);
  Sleeping(_cthulhu);
  PrintPower(_cthulhu);

  Attack(&_NLKoala->m_parent);

  return (0);
}
