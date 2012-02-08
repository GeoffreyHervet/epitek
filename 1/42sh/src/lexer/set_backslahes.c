/*
** set_backslahes.c for lexer in /home/hervet_g/work/42sh/src/lexer
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 18:15:16 2011 geoffrey hervet
** Last update Tue May 17 18:15:16 2011 geoffrey hervet
*/

static void	update_str(char *str,
			   int idx)
{
  while (str[idx])
  {
    str[idx] = str[idx + 1];
    idx++;
  }
  str[idx + 1] = 0;
}

void		set_backslashes(char *str,
					int idx)
{
  update_str(str, idx);
}

