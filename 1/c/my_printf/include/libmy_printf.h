/*
** libmy_prinf.h for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 42 13:37:42 2042 geoffrey hervet
** Last update Sun Nov 21 02:15:29 2010 geoffrey hervet
*/

#ifndef		__LIBMY_PRINTF__
#  define	__LIBMY_PRINTF__

#  ifndef	NULL
#    define	NULL	((void *)(0))
#  endif	/* !NULL */

#  ifndef	PRTF_FLAG
#    define	PRTF_FLAG	'%'
# endif		/* !PRTF_FLAG */

#  ifndef	PRTF_LESS
#    define	PRTF_LESS	'-'
# endif		/* !PRTF_LESS */

#  ifndef	ABS
#    define	ABS(x)	(((x) < 0) ? (-(x)) : (x))
#  endif	/* !ABS */

typedef struct	s_params
{
  char		*str;
  char		*adv_flag;
  int		char_printed;
  int		idx_str;
  va_list	args;
}		t_params;

typedef struct	s_funct
{
  char		flag;
  int		(*function)(t_params *);
}		t_funct;

int	my_printf(char *str, ...);
int	adv_flag_process(t_params *params);

/*
** ********************************
** * STRING OR POINTERS FUNCTIONS *
** ********************************
*/

int	my_printf_putstr(t_params *params);
int	my_printf_putstra(t_params *params);
int	my_printf_putptr(t_params *params);

/*
** ****************************
** *     NUMBER FUNCTIONS     *
** ****************************
*/

int	my_printf_putnbr(t_params *params);
int	my_printf_putuns(t_params *params);
int	my_printf_putoct(t_params *params);
int	my_printf_puthexl(t_params *params);
int	my_printf_puthexu(t_params *params);
int	my_printf_putbin(t_params *params);

/*
** ****************************
** *     OTHERS FUNCTIONS     *
** ****************************
*/

void	my_printf_putchar(char c);
int	my_printf_put_char(t_params *params);
int	my_printf_putplus(t_params *params);

#endif		/* !__LIBMY_PRINTF__ */
