/*
** aff_pic.c for src in /home/hervet_g/work/unix/minitalk/serveur/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  ven. mars 11 18:08:46 2011 geoffrey hervet
** Last update ven. mars 11 18:08:46 2011 geoffrey hervet
*/

#include	<unistd.h>

#include	"serv.h"

#include	"aff_pid.h"

#define		my_putstr(x, y) (write(y, x, my_strlen(x)))

extern t_infos	*infos;

inline static int	my_putchar(char c, int fd)
{
  return (write(fd, &c, 1));
}

inline static int	my_strlen(const char *str)
{
  return ((*str) ? (1 + my_strlen(str + 1)) : 0);
}

static void		my_putnbr(const int nbr)
{
  if (nbr > 9)
    my_putnbr(nbr / 10);
  my_putchar('0' + nbr % 10, 1);
}

void			aff_pid()
{
  my_putstr("Mon pid est : ", 1);
  my_putnbr(getpid());
}
