/*
** my_printf.h for my_printf in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Nov 13 18:49:22 2010 tom-brent yau
** Last update Fri Mar 25 02:03:33 2011 tom-brent yau
*/

#ifndef		__MY_PRINTF_H__
# define	__MY_PRINTF_H__

typedef struct	s_option
{
  va_list	arg;
  int		pos;
  int		zero_pad;
  int		minus;
  int		space;
  int		plus;
  int		hash;
  int		field_width;
  int		precision;
  int		if_flag;
  int		if_precision;
  int		if_field_width;
  int		char_printed;
}		t_option;

typedef struct	s_flags
{
  char		flag;
  void		(*p)(t_option *);
}		t_flags;

typedef struct	s_type
{
  char		type;
  t_option	(*f)(t_option);
}		t_type;

int		my_printf(char *str, ...);
t_option	type_s(t_option option);
t_option	type_d(t_option option);
void		my_putchar_p(char c, t_option *option);
void		my_put_nbr_p(t_option *option, int nb);
void		my_putstr_p(char *str, t_option *option);
int		my_strlen(char *str);
t_option	type_c(t_option option);
void		my_putnbr_base(t_option *option, unsigned int nb, char *base);
t_option	type_o(t_option option);
t_option	type_p(t_option option);
t_option	type_x_down(t_option option);
t_option	type_x_up(t_option option);
unsigned int	my_strlen_unsigned(char *str);
t_option	type_u(t_option option);
t_option	type_b(t_option option);
t_option	type_s_up(t_option option);
int		call_func(char *str, t_option *option);
int		my_getnbr(char *str);
int		get_flags(char *str, t_option *option);
void		get_len(char *str, t_option *option);
int		nb_len(int nb);
void		disp_space_int(t_option *option, int nb);
void		disp_zero_int(t_option *option, int len, int nb);
void		disp_space_unsigned(t_option *option, unsigned int nb, int base);
void		disp_zero_unsigned(t_option *option, int len, unsigned int nb,
				   int base);
void		hash_option(t_option *option);
void		zero_pad_op(t_option *option);
void		minus_option(t_option *option);
void		plus_option(t_option *option);
void		space_option(t_option *option);
void		disp_space_string(t_option *option, int s_len);
int		nb_len_unsigned(unsigned int nb, int base);
int		if_param(char *str, t_option option);
extern		t_type	type[12];
extern		t_flags	flags[6];

#endif
