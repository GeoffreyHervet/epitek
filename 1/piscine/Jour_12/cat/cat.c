/*
** cat.c for cat in /home/hervet_g//work/piscine/Jour_12/cat
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Oct 21 14:56:22 2010 geoffrey hervet
** Last update Thu Oct 21 20:32:56 2010 geoffrey hervet
*/

#include	"fonctions.h"
#include	"cat.h"
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<errno.h>



void	buffer_errors(int err, int *buf, char *file)
{
  *buf = 0;
  if (err == EACCES)
    my_put_err(file, EACCES_MSG);
  if (err == EISDIR)
    my_put_err(file, EISDIR_MSG);
  my_put_err(file, UNK_ERR_MSG);
}

void	my_put_err(char *file, char *msg)
{
  my_putstr("EXE_NAME: ");
  my_putstr(file);
  my_putstr(msg);
}

int	cat(int ac, char **av)
{
  char	buffer[BUFFER_MAX_SIZE];
  int	size_buf;
  int	fd;
  int	i;

  i = 0;
  while (++i < ac)
    {
      size_buf = -1;
      fd = open(av[i], O_RDONLY);
      if (fd == -1)
	my_put_err(av[i], OPEN_ERR_MSG);
      else
	{
	  while (size_buf)
	    {
	      size_buf = read(fd, buffer, BUFFER_MAX_SIZE - 1);
	      if (size_buf < 0)
		buffer_errors(errno, &size_buf, av[i]);
	      else
		write(1, buffer, size_buf);
	    }
	  close(fd);
	}
    }
  return (0);
}
