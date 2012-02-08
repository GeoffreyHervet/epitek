/*
** calc_min_of_three_values.c for  in /home/rufin_q//projet/42sh/distance_de_levenshtein
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sun Apr 24 16:22:33 2011 quentin rufin
** Last update Sun Apr 24 16:22:58 2011 quentin rufin
*/

int	calc_min_of_three_values(int first, int second, int third)
{
  int		tmp;

  tmp = first;
  if (tmp > second)
    tmp = second;
  if (tmp > third)
    tmp = third;
  return (tmp);
}
