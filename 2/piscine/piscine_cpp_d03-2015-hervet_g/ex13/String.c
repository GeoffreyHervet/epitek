/*
** String.c for piscine_cpp_d03-2015-hervet_g in /home/hervet_g/piscine/piscine_cpp_d03-2015-hervet_g
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 07 02:03:05 2012 geoffrey hervet
** Last update Sat Jan 07 02:03:05 2012 geoffrey hervet
*/

#include	<stdlib.h>
#include	<string.h>

#include	"String.h"

static void		assign_s(String *this, String const *str);
static void		assign_c(String *this, char const *s);
static void		append_s(String *this, String const *str);
static void		append_c(String *this, char const *s);
static char		at(String *this, size_t pos);
static void		clear(String *this);
static int		size(String *this);
static int		compare_s(String *this, String *str);
static int		compare_c(String *this, char const *str);
static size_t		copy(String *this, char *s, size_t n, size_t pos);
static char const *	c_str(String *this);
static int		empty(String *this);
static int		find_s(String *this, const String *str, size_t pos);
static int		find_c(String *this, const char *str, size_t pos);
static void		insert_c(String *this, size_t pos, char const *str);
static void		insert_s(String *this, size_t pos, String const *str);
static int		to_int(String *this);
static char **		split_c(String *this, char separator);
String *		split_s(String *this, char separator);
static void		aff(String *this);
static void		join_c(String *this, char delim, char const **tab);
static void		join_s(String *this, char delim, String *tab);
static String *		substr(String *this, int offset, int length);


void		StringInit(String *this, char const *s)
{
  this->assign_c	= assign_c;
  this->assign_s	= assign_s;
  this->append_s	= append_s;
  this->append_c	= append_c;
  this->at		= at;
  this->clear		= clear;
  this->size		= size;
  this->compare_s	= compare_s;
  this->compare_c	= compare_c;
  this->copy		= copy;
  this->c_str		= c_str;
  this->empty		= empty;
  this->find_c		= find_c;
  this->find_s		= find_s;
  this->insert_s	= insert_s;
  this->insert_c	= insert_c;
  this->to_int		= to_int;
  this->split_s		= split_s;
  this->split_c		= split_c;
  this->aff		= aff;
  this->join_c		= join_c;
  this->join_s		= join_s;
  this->substr		= substr;
  this->str		= strdup(s);
}

void		StringDestroy(String *this)
{
  free(this->str);
  this->str = NULL;
}

static void	assign_s(String *this, String const *str)
{
  this->str = strdup(str->str);
}

static void	assign_c(String *this, char const *s)
{
  this->str = strdup(s);
}

static void	append_s(String *this, String const *str)
{
  if (NULL != (this->str = realloc(this->str, sizeof(*(this->str)) * (strlen(str->str) + strlen(this->str) + 1))))
      this->str = strcat(this->str, str->str);
}

static void	append_c(String *this, char const *s)
{
  if (NULL != (this->str = realloc(this->str, sizeof(*(this->str)) * (strlen(s) + strlen(this->str) + 1))))
      this->str = strcat(this->str, s);
}

static char	at(String *this, size_t pos)
{
  if (this->str == NULL || pos >= strlen(this->str))
    return -1;
  return this->str[pos];
}

static void	clear(String *this)
{
  if (this->str != NULL)
    bzero(this->str, strlen(this->str));
}

static int	size(String *this)
{
  if (this->str == NULL)
    return -1;
  return strlen(this->str);
}

static int	compare_s(String *this, String *str)
{
  return strcmp(this->str, str->str);
}

static int	compare_c(String *this, char const *str)
{
  return strcmp(this->str, str);
}

static size_t	copy(String *this, char *s, size_t n, size_t pos)
{
  size_t	idx = 0;

  if (this->str == NULL || s == NULL || pos >= strlen(this->str))
    return 0;
  while (this->str[idx + pos] && n-- > 0)
  {
    s[idx] = this->str[idx + pos];
    idx++;
  }
  s[idx] = 0;
  return idx;
}

static char const *c_str(String *this)
{
  return this->str;
}

static int	empty(String *this)
{
  if (this->str == NULL || !strlen(this->str))
    return 1;
  return -1;
}

static int	find_s(String *this, const String *str, size_t pos)
{
  if (str == NULL)
    return -1;
  return this->find_c(this, str->str, pos);
}

static int	find_c(String *this, const char *str, size_t pos)
{
  char		*tmp;

  if (pos >= strlen(this->str) || str == NULL)
    return -1;
  if (NULL != (tmp = strstr(this->str + pos, str)))
    return ((unsigned long int)tmp) - ((unsigned long int) (this->str + pos));
  return -1;
}

static void	insert_c(String *this, size_t pos, char const *str)
{
  char		*c  = NULL;
  int		idx = -1;

  if (this->str == NULL || str == NULL)
    return this->assign_c(this, str);
  if (NULL != (c = malloc(sizeof(*c) * (strlen(str) + strlen(this->str) + 1))))
  {
    while (this->str[++idx] && pos--)
      c[idx] = this->str[idx];
    pos = 0;
    while (*str)
      c[idx + pos] = *str++;
    while (this->str[idx])
    {
      c[idx + pos] = this->str[idx];
      idx++;
    }
    c[idx + pos] = 0;
    this->str = c;
  }
}

static void	insert_s(String *this, size_t pos, String const *str)
{
  this->insert_c(this, pos, str->str);
}

static int	to_int(String *this)
{
  if (this->str == NULL)
    return 0;
  return atoi(this->str);
}

static char **		split_c(String *this, char separator)
{
  char			**ret = NULL;
  int			size = 2;
  int			idx = 0;
  int			prev = 0;
  char			*str = NULL;

  if (NULL == (str = strdup(this->str)))
    return NULL;
  while (str[idx])
  {
    if (str[idx] == separator)
    {
      if (prev == idx)
      {
        prev++;idx++;continue;
      }
      if (NULL == (ret = realloc(ret, sizeof(*ret) * (size + 1))))
        return NULL;
      str[idx] = 0;
      ret[size++ - 2] = strdup(str + prev);
      prev = idx + 1;
    }
    idx++;
  }
  ret[size - 2] = NULL;
  if (idx > prev)
    ret[size - 2] = strdup(this->str + prev);
  ret[size - 1] = NULL;
  free(str);
  return ret;
}

String *		split_s(String *this, char separator)
{
  char			**tab;
  int			idx = 0;
  String		*ret;

  if (NULL == (tab = this->split_c(this, separator)))
    return NULL;
  for (idx = 0; tab[idx] != NULL; idx++);
  if (NULL == (ret = malloc(sizeof(*ret) * (++idx))))
    return NULL;
  for (idx = 0; tab[idx] != NULL; idx++)
    StringInit(&(ret[idx]), tab[idx]);
  StringInit(&(ret[idx]), "");
  return ret;
}

static void		aff(String *this)
{
  printf("%s", this->str);
  fflush(stdout);
}

static void		join_c(String *this, char delim, char const **tab)
{
  int			idx = 0;
  char			*str;
  int			total_size = 0;

  while (tab[idx] != NULL)
    total_size += strlen(tab[idx++]) + 1;
  if (NULL != (str = malloc(sizeof(*str) * total_size)))
  {
    total_size = 0;
    while (*tab != NULL)
    {
      idx = 0;
      while ((*tab)[idx])
        str[total_size++] = (*tab)[idx++];
      str[total_size++] = delim;
      tab++;
    }
    str[total_size - 1] = 0;
    this->str = str;
  }
}

static void		join_s(String *this, char delim, String *tab)
{
  int			idx = 0;
  char			*str;
  int			total_size = 0;

  while (strlen(tab[idx].str))
    total_size += strlen(tab[idx++].str) + 1;
  if (NULL != (str = malloc(sizeof(*str) * total_size)))
  {
    total_size = 0;
    while (strlen(tab[idx].str))
    {
      idx = 0;
      while ((*tab).str[idx])
        str[total_size++] = (*tab).str[idx++];
      tab++;
      str[total_size++] = strlen(tab[idx].str) ? delim : 0;
    }
    this->str = str;
  }
}

static String *		substr(String *this, int offset, int length)
{
  (void)this;
  offset += length;
  return NULL;
}
