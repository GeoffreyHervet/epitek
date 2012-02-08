/*
** Exo-1.c for ex-1 in /home/hervet_g/piscine/ok/ex-1
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 12 09:46:23 2012 geoffrey hervet
** Last update Thu Jan 12 09:46:23 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"Exo-1.h"

void	PrintPower(struct s_cthulu *);
void	Attack(struct s_cthulu *);
void	Sleeping(struct s_cthulu *);
void	CthulhuInitializer(struct s_cthulu *);

void	Eat(struct s_koala *);
void	KoalaInitializer(t_koala *, char *, char);

t_cthulhu	*NewCthulhu(void)
{
  t_cthulhu	*p;
  char		str [] = "Cthulhu";

  printf("----\n");
  if (NULL == (p = malloc(sizeof(*p))))
    return NULL;
  p->m_name = strdup(str);
  CthulhuInitializer(p);
  return p;
}

#define LUI(x) ((long unsigned int)(x))

 t_koala *get_struct_ptr(t_cthulhu *m_parent)
{
  return (t_koala*)(
      LUI(m_parent)
      - LUI(&((t_koala *)(NULL))->m_parent));
}

 void	PrintPower(struct s_cthulu * this)
{
  printf("Power => %d\n", this->m_power);
}

void		CthulhuInitializer(struct s_cthulu *p)
{
  printf("Building Cthulhu\n");
  p->PrintPower = PrintPower;
  p->Attack = Attack;
  p->Sleeping = Sleeping;
  p->m_power = 42;
}

 void	Attack(struct s_cthulu * this)
{
  if (this->m_power >= 42)
  {
    this->m_power -= 42;
    printf("%s attacks and destroys the city\n", this->m_name);
  }
  else
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

 void	Sleeping(struct s_cthulu * this)
{
  this->m_power += 42000;
  printf("%s sleeps\n", this->m_name);
}

t_koala		*NewKoala(char *name, char _isALegend)
{
  t_koala	*p;

  printf("----\n");
  if (NULL == (p = malloc(sizeof(*p))))
    return NULL;
  KoalaInitializer(p, name, _isALegend);
  printf("Building %s\n", p->m_parent.m_name);
  return p;
}

void		Eat(struct s_koala *this)
{
  this->m_parent.m_power += 42;
  printf("%s eats\n", this->m_parent.m_name);
}

void	KoalaInitializer(t_koala *this, char *_name, char _isALegend)
{
  this->m_isALegend = _isALegend;
  this->m_parent.m_name = strdup(_name);
  this->Eat = Eat;
  CthulhuInitializer(&(this->m_parent));
  if (!_isALegend)
    this->m_parent.m_power = 0;
}
