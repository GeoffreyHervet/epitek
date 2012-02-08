/*
** my_sh.h for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 09:50:55 2010 geoffrey hervet
** Last update Wed Jan  5 15:31:59 2011 geoffrey hervet
*/

#ifndef		__MY_SH_H__
#  define	__MY_SH_H__

#  ifndef	__pid_t_defined
#    error	<sys/types.h> is not inclued
#  endif	/* !__pid_t_defined */

void	get_sig(int sig);

/*
** **************************************************************************
** *			Definition of the specials macros		    *
** **************************************************************************
*/

#  define	FREE_NOTH	0
#  define	FREE_NAME	1
#  define	FREE_VAL	2
#  define	FREE_BOTH	3

/*
** **************************************************************************
** *			Definition of the defaults settings		    *
** **************************************************************************
*/

#  define	DEF_PROMPT	"$>"
#  define	DEF_PATH	"/usr/local/bin:/bin:/usr/bin"

/*
** **************************************************************************
** *			Definition of the errors messages		    *
** **************************************************************************
*/

#  define	ERR_MALLOC	"Memory allocation failed\n"
#  define	ERR_CHDIR	"Directory can't be opened\n"
#  define	ERR_SPLIT	"\
Error occured : the command can't be splited ....\n"
#  define	ERR_DEFAULT	"\
A critical error has occurred ... The program just die before your eyes\n"
#  define	ERR_NEEDPWD	"$PWD in not present in environement...\n"
#  define	ERR_NEEDHOME	"$HOME in not present in environement...\n"

#  define	ERR_EXEC	": Permission denied...\n"
#  define	ERR_PATH	"Error path format ...\n"
#  define	ERR_CMDNOTFND	": Command not found \n"
#  define	ERR_FORK	"Oups ! Fork has failed ...\n"
#  define	ERR_EXECVE	"\
The program can't be executed ... (execve error ...)\n"
#  define	ERR_NB_ARG	": Too few arguments.\n"

/*
** **************************************************************************
** *			Definition of the structures			    *
** **************************************************************************
*/

/*
** t_env.have_free : FREE_NOTH => Do not free val AND name
**		     FREE_NAME => free name
**		     FREE_VAL  => free val
**		     FREE_BOTH => free name AND val
*/

typedef struct		s_env
{
  int			have_free;
  char			*name;
  char			*val;
  struct s_env		*next;
}			t_env;

typedef struct		s_cmd_split
{
  char			*data;
  struct s_cmd_split	*next;
}			t_cmd_split;

typedef struct		s_base
{
  char			*cmd;
  t_cmd_split		*cmd_splited;
  t_env			*env;
  pid_t			child;
}			t_base;

#endif		/* !__MY_SH_H__ */
