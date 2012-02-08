/* 
** tp.c for unix in /home/hervet_g/unix
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Feb 07 12:12:56 2012 geoffrey hervet
** Last update Tue Feb 07 12:12:56 2012 geoffrey hervet
*/

#define _XOPEN_SOURCE
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



#if 0

int main()
{
  struct termios	t;
  char			buf[100];

  tcgetattr(0, &t);
  t.c_lflag &= ~ECHO;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &t);
  buf[read(0, buf, 99)] = 0;
  printf("%s", buf);
  return 0;
}

#endif

int	open_matster_tty()
{
  return open("/dev/ptmx", O_RDWR | O_NOCTTY);
}



int main()
{
  int		fd_master;

  fd_master = open_matster_tty();
  printf("fd_master = %i\n", fd_master);

  return 0;
}
