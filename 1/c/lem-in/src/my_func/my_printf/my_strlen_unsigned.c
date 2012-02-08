/*
** my_strlen_unsigned.c for my_strlen_unsigned in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 17:26:25 2010 tom-brent yau
** Last update Mon Nov 15 17:27:38 2010 tom-brent yau
*/

unsigned int	my_strlen_unsigned(char *str)
{
  unsigned int	pos;

  pos = 0;
  while (str[pos])
    pos++;
  return (pos);
}
