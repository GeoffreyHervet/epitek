/*
** add.h for  in /u/all/hervet_g/public/Pi/Include
**
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
**
** Started on  Wed Apr 27 22:04:35 2011 tracy nelcha
** Last update Wed Apr 27 22:30:52 2011 tracy nelcha
*/

#ifndef		__MAIN_H__
# define	__MAIN_H__

/*
** DEFINE COLOR
*/

# define        B       "\033[34m"
# define        G       "\033[32m"
# define        R       "\033[31m"
# define        W       "\033[00m"

/*
** DEFINE
*/

# define	OK	0
# define	NOT_OK	1
# define	A(x)	((char)(x) >= '0' && (char)(x) <= '9')
# define	F(x)	((char)(x) == 'a' || (char)(x) == 'd' || (char)(x) == 's')

/*
** PROTOTYPE
*/

int     main(int ac, char **av);

#endif		/*__MAIN_H__*/
