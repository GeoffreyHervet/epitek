/*
** check_function.c for  in /home/rufin_q//projet/42sh/42sh/src
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Tue Apr  5 21:28:21 2011 quentin rufin
** Last update Wed May 11 15:32:12 2011 tom-brent yau
*/

#include	"check_function.h"

int		check_number(char c)
{
  return (c >= '0' && c <= '9');
}

int		check_word(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	   c == '-' || c == '_' || check_number(c) || c == '.' ||
	   c == '/' || c == '\\' || c == '~' || c == '*' || c == '\\');
}

int		check_all_ope(char c)
{
  return (c == '&' || c == '|' || c == '!' || c == '>' || c == '<');
}
