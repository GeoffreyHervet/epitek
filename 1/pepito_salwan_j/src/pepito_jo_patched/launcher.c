/*
 * Pierre Wacrenier wrote this.
 * If you enjoy it, you can^Wmust buy me a beer.
 *
 * Launcher that deactivates Linux's Address Space Layout Randomization (ASLR)
 * to allow easy stack smashing.
 * To see how it works, read the usage.
 *
 * More informations about Linux's ASLR:
 * - http://pax.grsecurity.net/docs/aslr.txt
 * - http://www.phrack.org/issues.html?issue=59&id=9#article
 */
 
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/personality.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void		usage(const char *progname)
{
  fprintf(stderr, "usage: %s path [arg ...]\n", progname);
}
 
int		main(int ac, char **av)
{
  int		persona;
  pid_t		pid;
  int		status;

  if (ac > 1)
    {
      if ((pid = fork()) < 0)
	return (EXIT_FAILURE);
      if (pid == 0)
	{
	  persona = personality(0);
	  personality(persona | ADDR_NO_RANDOMIZE);
	  execve(av[1], av + 1, environ);
	}
      else
	{
	  wait(&status);
	  printf("launcher return status: %d\n", status);
	  return (EXIT_SUCCESS);
	}
    }
  else
    usage(av[0]);
  return (EXIT_FAILURE);
}

/*
** (|€~
*/
