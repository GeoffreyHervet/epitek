/*
** dist_levenshtein.h for  in /home/rufin_q//projet/42sh/distance_de_levenshtein
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sat Apr 23 21:15:39 2011 quentin rufin
** Last update Wed Jun  8 16:04:04 2011 quentin rufin
*/

#ifndef		DIST_LENSHTEIN_H_
# define	DIST_LENSHTEIN_H_

# define	SIZE_MAX_WORD	256

typedef struct	s_two_str_info
{
  char		*str1;
  char		*str2;
  int		size1;
  int		size2;
}		t_two_str_info;

int	xcalc_dist_levenshtein(char *s1, char *s2);
int	calc_dist_levenshtein(char *s1, char *s2);
int	calc_min_of_three_values(int, int, int);

#endif	/* !DIST_LENSHTEIN_H_ */
