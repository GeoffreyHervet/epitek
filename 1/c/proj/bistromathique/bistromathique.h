/*
** bistromathique.h for bistro in /home/hervet_g//work/projets/c/bistro
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Oct 26 08:47:41 2010 geoffrey hervet
** Last update Wed Nov  3 15:14:16 2010 geoffrey hervet
*/

#ifndef		__BISTROMATHIQUE_H__
#  define	__BISTROMATHIQUE_H__

#  define	OP_OPEN_PARENT_IDX	(0)
#  define	OP_CLOSE_PARENT_IDX	(1)
#  define	OP_PLUS_IDX		(2)
#  define	OP_SUB_IDX		(3)
#  define	OP_NEG_IDX		(3)
#  define	OP_MULT_IDX		(4)
#  define	OP_DIV_IDX		(5)
#  define	OP_MOD_IDX		(6)

#  ifndef	TRUE
#    define	TRUE			(1)
#  endif	/* TRUE */

#  ifndef	FALSE
#    define	FALSE			(0)
#  endif	/* FALSE */

#  define	SYNTAXE_ERROR_MSG	"Syntax error"
#  define	MALLOC_ERROR_MSG	"Malloc error"

#define		GET_MAX(x, y)	(((x) > (y)) ? (x) : (y))


typedef	struct		s_btree
{
  struct s_btree	*left;
  struct s_btree	*right;
  char			*data;
}			t_btree;

typedef	struct		s_expr
{
  t_btree		*btree;
  char			*expr;
  char			*base;
  char			*ops;
  unsigned int		size_expr;
  unsigned int		size_base;
}			t_expr;

/*
** ****************************************************************************
** *			        ./parsing/				      *
** ****************************************************************************
*/
char *eval_expr(char *base, char *ops, char *expr, unsigned int size);
t_expr	*create_expr_s(char *base, char *ops, char *expr, unsigned int size);
int		get_operator_priority(char c, t_expr *s);
int		get_highest_priority(t_expr *s, int start, int end);
int		is_only_digits(t_expr *s, int start, int end);
int		count_operators(t_expr *s, int start, int end);
int		is_operator(t_expr *s, int pos);

/*
** ****************************************************************************
** *				     ./					      *
** ****************************************************************************
*/
int		my_strlen(char *str);
int		my_putchar(char c);
int		my_putstr(char *s);
char		*str_cpy_delimit(char *str, int start, int end);
int		char_in_str(char c, char *str);
int		str_only_digits(char *str, int start, int end, char *base);


/*
** ****************************************************************************
** *			      ./btree/					      *
** ****************************************************************************
*/
int		grow_btree(t_expr *s);
int		btree_repartition(t_expr *s, int pos, int tmp, t_btree *parent);
int		btree_add_node(t_btree *parent, int position, char *data);

#endif		/* __BISTROMATHIQUE_H__ */
