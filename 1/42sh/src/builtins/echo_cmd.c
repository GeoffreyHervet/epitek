/*
** echo_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/builtins
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Apr 17 19:14:40 2011 tom-brent yau
** Last update Mon May  9 12:37:48 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"sh.h"
#include	"utils.h"
#include	"echo_cmd.h"
#include	"echo_numbers.h"

static const t_sp_ch corresp[] =
  {
    {'\\', '\\'},
    {'a', '\a'},
    {'b', '\b'},
    {'c', '\0'},
    {'e', ' '},
    {'f', '\f'},
    {'n', '\n'},
    {'r', '\r'},
    {'t', '\t'},
    {'v', '\v'},
    {0,      0}
  };

static int	get_option_of_antislash(char *str,
					int *count,
                                        int *count2,
                                        int enable)
{
  int		idx;

  idx = 0;
  while (corresp[idx].letter && enable)
  {
    if (str[*count2 + 1] == corresp[idx].letter)
    {
      str[*count] = corresp[idx].corr;
      *count2 += 2;
      return (0);
    }
    idx++;
  }
  if ((str[*count2 + 1] == 'x' || str[*count2 + 1] == '0') && enable)
    return (number_str(str, count, count2));
  str[*count] = str[*count2 + 1];
  *count2 += 2;
  return (0);
}

static void	modify_special_string(char *str, int enable)
{
  int		count;
  int		count2;

  count = 0;
  count2 = 0;
  while (str[count2] != 0)
  {
    if (str[count2] == '\\')
      get_option_of_antislash(str, &count, &count2, enable);
    else
    {
      str[count] = str[count2];
      count2++;
    }
    count++;
  }
  str[count] = 0;
}

static t_tree	*get_option_and_string_node(t_tree *cmd, int *option)
{
  int		tmp;
  int		idx;

  while (cmd != NULL)
  {
    if (cmd->info.str[0] != '-')
      return (cmd);
    idx = 1;
    tmp = *option;
    while (cmd->info.str[idx])
    {
      if (cmd->info.str[idx] == 'n')
        tmp |= OPTION_N;
      else if (cmd->info.str[idx] == 'e')
        tmp |= OPTION_E;
      else if (cmd->info.str[idx] == 'E')
        tmp |= OPTION_MAJ_E;
      else
        return (cmd);
      idx++;
    }
    *option = tmp;
    cmd = cmd->right;
  }
  return (cmd);
}

int		echo_cmd(t_tree *cmd, __attribute__((unused)) t_env **env)
{
  int		option;

  option = 0;
  cmd = get_option_and_string_node(cmd, &option);
  if (option & OPTION_MAJ_E)
    option &= ~OPTION_E;
  while (cmd)
    {
      modify_special_string(cmd->info.str, option & OPTION_E);
      printf("%s", cmd->info.str);
      if (cmd->right)
	printf(" ");
      cmd = cmd->right;
    }
  if ((option & OPTION_N) != OPTION_N)
    printf("\n");
  else
    fflush(stdout);
  return (TRUE);
}
