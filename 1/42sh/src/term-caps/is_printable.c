/*
** is_printable.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 20 11:09:16 2011 tom-brent yau
** Last update Fri May 20 11:09:30 2011 tom-brent yau
*/

int	is_printable(char *buffer)
{
  while (*buffer)
    {
      if (*buffer < ' ' || *buffer == 127)
	return (0);
      ++buffer;
    }
  return (1);
}
