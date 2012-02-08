/*
** sh.h for  in /home/rufin_q//projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Mon Apr  4 11:49:06 2011 quentin rufin
** Last update Sat May 21 17:54:35 2011 quentin rufin
*/

#ifndef		SH_H
# define	SH_H

# define	SIZE	(4096)

#ifndef		TRUE
# define	TRUE	EXIT_SUCCESS
#endif

#ifndef		FALSE
# define	FALSE	EXIT_FAILURE
#endif

# define	MAX_SIZE	16384

# define	CFG_FILE	".42rc"

# define	ENV_PATH	"/bin:/usr/bin"

enum
  {
    WORD = 1,
    CMD,
    CMD_ARG,
    OPE_DOUBLE_RIGHT,
    OPE_RED_RIGHT,
    OPE_DOUBLE_LEFT,
    OPE_RED_LEFT,
    OPE_PIPE,
    OPE_AND,
    OPE_OR,
    AGR_FD,
    BACKGROUND,
    PTH_BEG,
    PTH_END,
    BACK_QUOTE,
    EXCL_MARK,
    SEMICOLON
  };

typedef struct	s_info
{
  char		*str;
  int		type;
}		t_info;

typedef struct	s_lex
{
  t_info	info;
  struct s_lex	*next;
  struct s_lex	*prev;
}		t_lex;

typedef struct	s_tree
{
  t_info	info;
  int		bg;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

typedef struct	s_env
{
  char		*var;
  struct s_env	*next;
}		t_env;

typedef struct	s_aliases
{
  char		*name;
  char		*value;
  struct s_aliases *next;
  unsigned int	selected:1;
}		t_aliases;

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

typedef struct	s_buff
{
  char	*buff;
  struct s_buff	*next;
}		t_buff;

typedef struct          s_history
{
  char                  *cmd;
  int                   id;
  int			hours;
  int			min;
  struct s_history      *next;
  struct s_history      *previous;
}                       t_history;

typedef struct		s_list_correc
{
  char			*name;
  struct s_list_correc	*next;
}			t_list_correc;

typedef struct
{
  t_aliases	*aliases;
  t_history 	*history;
  t_env		**env;
  t_list_correc	*list_correc;
  char		if_exit;
  int		ret;
}		t_inf;

#endif /* !SH_H */
