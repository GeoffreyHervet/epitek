/*
** my_put_var.c for marvin in /home/hervet_g//work/rush/marvin
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Nov 27 10:15:46 2010 geoffrey hervet
** Last update Sat Nov 27 15:47:19 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"marvin.h"
#include	"my_put_var.h"
#include	"write_type.h"

static void	check_write(int val)
{
  if (val == -1)
    {
      if (write(1, "[ERROR] - Can't write in output standard\n", 42) == -1)
	exit (0);
      exit (0);
    }
}

int	my_put_var(t_marvin *marvin, t_variable*variable)
{
  check_write(write (1, "Declaration d'une variable nomee ", 33));
  check_write(write(1, &(marvin->str[variable->start_name]),
		    (variable->end_name - variable->start_name)));
  check_write(write(1, " et de type ", 12));
  check_write(write_type(1, &(marvin->str[variable->start_type]),
		    (variable->end_type - variable->start_type)));
  return (0);
}
