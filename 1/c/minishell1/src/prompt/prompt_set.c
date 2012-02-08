/*
** prompt_set.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 12:57:24 2010 geoffrey hervet
** Last update Fri Dec 31 10:57:26 2010 geoffrey hervet
*/

#include		<sys/types.h>
#include		<unistd.h>

#include		"my_sh.h"
#include		"env/get_env.h"
#include		"env/set_env.h"
#include		"prompt/prompt_set.h"
#include		"cmd/get_cmd.h"

void			prompt_set(t_base *base)
{
  t_env			*prompt;

  prompt = get_env(base->env, "PROMPT");
  if (!prompt)
    {
      prompt = set_env("PROMPT", DEF_PROMPT, FREE_NOTH);
      base->env = set_env(NULL, NULL, FREE_NOTH);
    }
  get_cmd(base, prompt);
}
