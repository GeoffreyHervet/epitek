/*
** show_prompt.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Apr 14 22:49:10 2011 tom-brent yau
** Last update Sun May 22 21:48:45 2011 tom-brent yau
*/

#include	<fcntl.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<signal.h>

#include	"sh.h"

#include	"termcp.h"
#include	"creat_lexer.h"
#include	"exec_tree.h"
#include	"free_lex.h"
#include	"gnl.h"
#include	"parser.h"
#include	"history.h"
#include	"utils.h"
#include	"read_file.h"
#include	"my_handler.h"
#include	"xsignal.h"

static int	read_cmd(char *cmd, t_termcp *t, t_inf *infos)
{
  int		ret;

  t->idx = 0;
  t->size = 0;
  t->hist = NULL;
  memset(t->tmp_buff, 0, SIZE + 1);
  memset(cmd, 0, SIZE + 1);
  print("$> ");
  if (t->term != NULL)
    {
      raw_mode();
      ret = read_keys(t, cmd, infos);
      classic_mode();
      print("\n");
    }
  else
    {
      if ((ret = read(0, cmd, SIZE)) <= 0)
	return (0);
      cmd[ret - 1] = 0;
    }
  epur_str(cmd, " \t", "|<>;&");
  if (ret && update_history(cmd, &(infos->history)) == FALSE)
    return (0);
  return (ret);
}

static void	execution(t_inf *infos, char *cmd)
{
  t_lex		*list;
  t_tree	*root;

  root = NULL;
  list = creat_lexer(cmd, infos);
  root = parser(list);
  free_lex(list);
  if (root != NULL)
    {
      exec_tree(root, infos);
      free_tree(root);
    }
}

static void	load_conf(t_inf *infos)
{
  int		fd;
  char		*cmd;

  if ((fd = open(CFG_FILE, O_RDONLY)) > 0)
  {
    while ((cmd = gnl(fd)) != NULL)
    {
      epur_str(cmd, " \t", "|<>;&");
      execution(infos, cmd);
      free(cmd);
    }
    if (close(fd))
      fprintf(stderr, "Error : can't perform close()\n");
  }
}

void		show_prompt(t_inf *infos, t_termcp *t)
{
  char		cmd[SIZE + 1];
  int		(*func)(char *, t_termcp *, t_inf *);

  t->cmd = cmd;
  func = (t->term != NULL) ? read_cmd : read_file;
  if (func == read_cmd)
    xsignal(SIGQUIT, &my_handler);
  load_conf(infos);
  while (infos->if_exit == 0 && func(cmd, t, infos))
    execution(infos, cmd);
  if (func == read_cmd)
    print("exit\n");
}
