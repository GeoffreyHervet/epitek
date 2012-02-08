/*
** read_file.c for src in /home/hervet_g/work/42sh/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 18 17:06:03 2011 geoffrey hervet
** Last update Wed May 18 17:06:03 2011 geoffrey hervet
*/

#include	<unistd.h>
#include	<string.h>

#include	"sh.h"
#include	"termcp.h"

#include	"utils.h"
#include	"read_file.h"

static void	dec_str(char str[SIZE], int dec)
{
  int		idx;

  idx = 0;
  while (str[dec + idx])
  {
    str[idx] = str[idx + dec];
    idx++;
  }
  str[idx] = 0;
}

static int	fill_cmd(char *cmd, char buf[SIZE], int *bpos)
{
  cmd = strncpy(cmd, buf, *bpos);
  dec_str(buf, *bpos + 1);
  *bpos = 0;
  return (1);
}

int		read_file(char *cmd, t_termcp *t, t_inf *infos)
{
  static int	bpos = -1;
  static char	buf[SIZE];

  memset(cmd, 0, SIZE + 1);
  (void)t;
  (void)infos;
  if (bpos == -1)
  {
    if (isatty(0))
      print("$> ");
    if ((bpos = read(0, buf, SIZE - 1)) <= 0)
      return (0);
    buf[bpos] = 0;
    epur_str(buf, " \t", "|<>;&");
    bpos = 0;
  }
  while (buf[bpos])
  {
    if (buf[bpos] == '\n')
      return (fill_cmd(cmd, buf, &bpos));
    bpos++;
  }
  bpos = -1;
  cmd = strcpy(cmd, buf);
  return (1);
}
