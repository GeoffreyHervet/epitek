/*
** philosophe.h for  in /home/hervet_g/philosophe
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Mar 17 16:42:41 2012 geoffrey hervet
** Last update Sat Mar 17 16:42:42 2012 geoffrey hervet
*/

#ifndef PHILOSOPHE_H_
# define PHILOSOPHE_H_

typedef enum
{
  CHOPSTICK_IS_UNUSED = 0,
  CHOPSTICK_IS_USED = 1
}			t_chopstick;

/* relative to seconds, for example : set it to 60 will multiply the program
 * execution time by 60 */
# define COEFF			(1)

# define EAT_TIME		(1 * COEFF)
# define THINK_TIME		(1 * COEFF)
# define SLEEP_TIME		(2 * COEFF)

# define PHILOSOPHES_NBR	(7)

int	philosophe(void);

#endif /* !PHILOSOPHE_H_ */
