/*
** errors.h for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 09:57:29 2010 geoffrey hervet
** Last update Wed Dec 22 15:07:21 2010 geoffrey hervet
*/

#ifndef		__ERRORS_H__
#  define	__ERRORS_H__

void		critical_error(int func_ret,
			       int check_val_ret,
			       int have_quit,
			       char *msg);

/*
** Errors loaction :
** file env/set_env : set_env() has been not initialized [...]
** file builtins/exec_builtins : Builtins not found ...
*/

#endif		/* !__ERRORS_H__ */
