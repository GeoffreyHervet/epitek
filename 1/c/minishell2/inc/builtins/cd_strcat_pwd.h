/*
** cd_strcat_pwd.h for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Dec 23 10:59:53 2010 geoffrey hervet
** Last update Sun Jan  2 14:01:12 2011 geoffrey hervet
*/

#ifndef		__CD_STRCAT_PWD_H__
#  define	__CD_STRCAT_PWD_H__

char		*tilde_gestion(const char *home,
			       const char *str);

char		*strcat_pwd(const char *pwd,
			    const char *str);
int		xchdir(const char *path);

#endif		/* !__CD_STRCAT_PWD_H__ */
