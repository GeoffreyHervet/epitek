/*
** write_type.h for marvin in /home/hervet_g//work/rush/marvin
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Nov 27 11:17:52 2010 geoffrey hervet
** Last update Sat Nov 27 21:40:49 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"lib.h"
#include	"marvin.h"
#include	"write_type.h"

static t_translate	trans[] = 
  {
    {"bool",		8,	"booleen"},
    {"char",		8,	"caractere"},
    {"const",		4,	"contstant"},
    {"double",		8,	"double"},
    {"enum",		6,	"enumere"},
    {"float",		8,	"flottan"},
    {"int",		8,	"entier"},
    {"long",		8,	"long"},
    {"private",		2,	"prive"},
    {"protected",	7,	"protege"},
    {"public",		2,	"public"},
    {"register",	2,	"registre"},
    {"short",		4,	"court"},
    {"signed",		9,	"signe"},
    {"static",		4,	"statique"},
    {"struct",		4,	"structure"},
    {"unsigned",	9,	"non signe"},
    {"*",		10,	"pointeur sur"},
    {"void*",		1,	"pointeur generique"},
    {NULL,		0,	NULL}
  };

static void		set_trans(t_lang *tmp, char *str, int word_p, int word_end)
{
  int			trans_pos;
  int			in_c_pos;

  trans_pos = -1;
  in_c_pos = 0;
  while (trans[++trans_pos].in_c)
    {
      while (trans[trans_pos].in_c[in_c_pos] == str[word_p + in_c_pos])
	++in_c_pos;
      if (!trans[trans_pos].in_c[in_c_pos] && (word_p + --in_c_pos) == word_end)
	{
	  tmp->trans = trans[trans_pos].in_fr;
	  tmp->priority = trans[trans_pos].priority;
	  return ;
	}
      else
	in_c_pos = 0;
    }
  tmp->trans = my_cpystr_xtoy(str, word_p, word_end);
  tmp->priority = 8;
}

static t_lang		*grow_list(t_lang *begin, char *str, int word_p, int word_end)
{
  t_lang		*tmp;

  if ((tmp = malloc(sizeof(*begin))) == NULL)
    return (NULL);
  tmp->next = begin;
  set_trans(tmp, str, word_p, word_end);
  return (tmp);
}

static void		display(const int fd, t_lang *begin)
{
  int			max_prio;
  int			have_set_prio;
  t_lang		*tmp;

  max_prio = 0;
  have_set_prio = 0;
  tmp = begin;
  while (tmp)
    {
      if (tmp == NULL)
	{
	  have_set_prio = !have_set_prio;
	  max_prio = (have_set_prio) ? max_prio : 0;;
	  tmp = begin;
	}
      if (!have_set_prio)
	max_prio = MAX(tmp->priority, max_prio);
      else if (max_prio == tmp->priority)
	{
	  my_putstr(tmp->trans);
	  if (begin == tmp)
	    begin = begin->next;
	}
      tmp = tmp->next;
    }
}

int			write_type(const int fd, char *str, int len)
{
  int		idx;
  int		word_p;
  t_lang	*begin;
  t_lang	*last;

  idx = -1;
  word_p = 0;
  if ((begin = malloc(sizeof(*begin))) == NULL)
    return (-1);
  begin->next = NULL;
  while ((word_p + ++idx) < len)
    {
      if (idx && IS_SEPA(str[idx]))
	{
	  if((last = grow_list(begin, str, word_p, idx)) == NULL)
	    return (-1);
	}
      else if (IS_SEPA(str[idx]))
	{
	  --idx;
	  ++word_p;
	}
    }
  display(fd, begin);
  return (0);
}
