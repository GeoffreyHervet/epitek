/*
** lib.h for my in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 22:05:22 2010 geoffrey hervet
** Last update Tue Nov 23 16:51:31 2010 geoffrey hervet
*/

#ifndef		__LIB_H__
#  define	__LIB_H__

#  ifndef	ABS
#    define	ABS(x)		(((x) < 0) ? - (x) : (x))
#  endif	/* !ABS */

int	my_strlen(char *s);
int	my_get_nbr(char *nb);

void	my_putchar(char c);
void	my_putstr(char *s);
void	my_putnbr_espace(int nb);

#endif		/* !__LIB_H__ */
