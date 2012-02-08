/*
** add.h for  in /u/all/hervet_g/public/Pi/Include
**
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
**
** Started on  Wed Apr 27 22:04:35 2011 tracy nelcha
** Last update Wed Apr 27 22:08:48 2011 tracy nelcha
*/

#ifndef		__ADD_H__
# define	__ADD_H__

/*
** DEFINE COLOR
*/

# define        B       "\033[34m"
# define        G       "\033[32m"
# define        R       "\033[31m"
# define        W       "\033[00m"

/*
** STRUCTURE
*/

typedef struct
{
  int           comma;
  int           idx;
}               t_infos;

/*
** PROTOTYPE
*/

void		add(char *str1, char *str2);

#endif		/*__ADD_H__*/
