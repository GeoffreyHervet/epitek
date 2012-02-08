/*
** xsignal.h for  in /home/yau_t//local/Projets/semestre_2/42sh/includes
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Apr 14 23:00:53 2011 tom-brent yau
** Last update Thu Apr 14 23:04:45 2011 tom-brent yau
*/

#ifndef		__XSIGNAL_H__
# define	__XSIGNAL_H__

typedef void (*sighandler_t)(int);

void	xsignal(int signum, sighandler_t handler);

#endif
