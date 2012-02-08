/*
** get_map.c for sudoki-bi in /u/all/hervet_g/public/suck/rendu/src
** 
** Made by vincent caggiari
** Login   <caggia_v@epitech.net>
** 
** Started on  Fri May  6 23:21:55 2011 vincent caggiari
** Last update Sun May  8 22:42:55 2011 vincent caggiari
*/

#include			<unistd.h>
#include			<string.h>

#include			"update_digit.h"

inline static unsigned char			clear_char(char c)
{
  if (c < 10 && c > 0)
    return (1);
  return (0);
}

unsigned char			get_map(unsigned short grid[9][9])
{
  unsigned char			buf[231 + 1];
  char				*buffer;
  register unsigned char	count;
  register unsigned char	pos;

  if (read(0, buf, 231) < 231)
    return (0);
  buffer =(char *)&buf[21];
  count = 0;
  while (count < 9)
    {
      pos = 1;
      while (pos < 10)
	{
	  if (buffer[pos * 2] != ' ' && clear_char(buffer[pos * 2] - '0'))
	    update_digit(grid, count, pos - 1, buffer[pos * 2] - '0');
	  pos++;
	}
      buffer += 21;
      count++;
    }
  return (1);
}
