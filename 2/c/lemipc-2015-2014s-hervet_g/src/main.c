/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/
/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
 */
#include		<time.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		<sys/types.h>
#include		<unistd.h>

#include		"lemipc.h"
#include		"game/run.h"
#include		"game/init.h"
#include		"game/exit.h"

static unsigned char	get_team_id(int ac, const char **av)
{
  int			idx;

  idx = 0;
  while (++idx < ac)
  {
    if (!strcmp(av[idx], "-t") && (idx + 1) < ac)
      return ((char)(atoi(av[idx + 1]) % 255));
  }
  return (1 + rand() % DEFAULT_TEAM_NB);
}

int			main(int ac, const char **av)
{
  t_process_infos	infos;

  srand(time(NULL) * getpid());
  infos.team_id = get_team_id(ac, av);
  if (EXIT_FAILURE == game_init(&infos))
    return (EXIT_FAILURE);
  printf("New player in team %d\n", infos.team_id);
  infos.shared->trick_id++;
  game_run(&infos);
  game_exit(&infos);
  printf("Player in team %d leaves\n", infos.team_id);
  return (EXIT_SUCCESS);
}
