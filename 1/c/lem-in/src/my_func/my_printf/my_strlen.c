/*
** my_strlen.c for my_strlen in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 11:51:00 2010 tom-brent yau
** Last update Sun Nov 21 17:45:31 2010 tom-brent yau
*/

int	my_strlen(char *str)
{
  int	pos;

  pos = 0;
  if (str)
    while (str[pos])
      pos++;
  return (pos);
}
