/*
** ptr_func.c for ex03 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 11:27:52 2012 geoffrey hervet
** Last update Thu Jan 05 11:27:52 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>

#include	"func_ptr.h"


void	print_normal(char *str)
{
  if (str != NULL)
    printf("%s\n", str);
}

void	print_reverse(char *str)
{
  int	idx = 0;

  if (str != NULL)
  {
    idx = strlen(str);
    while (idx >= 0)
      putchar(str[idx--]);
    putchar('\n');
  }
}

void	print_upper(char *str)
{
  while (*str)
    printf("%c", ((*str >= 'a' && *str <= 'z') ? *str++ - 'a' + 'A' : *str++));
  printf("\n");
}

void	print_42(char *str)
{
  (void)str;
  printf("42\n");
}

void	do_action(t_action action, char *str)
{
  static t_ptr func[] =
  {
    print_normal,
    print_reverse,
    print_upper,
    print_42
  };

  func[action](str);
}
