/*
** exec_command.c for  in /home/rufin_q/projet/42sh/42sh/src/exec
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sat Apr 16 14:56:56 2011 quentin rufin
** Last update Sat May 14 17:56:40 2011 tom-brent yau
*/

#include	<signal.h>
#include	<stdio.h>
#include	"show_message.h"

static const t_sig_rec	sig_rec[28] = {
  {SIGHUP, "Hangup"},
  {SIGQUIT, "Quit"},
  {SIGILL, "Illegal instruction"},
  {SIGTRAP, "Trace/BPT trap"},
  {SIGABRT, "Abort"},
  {SIGIOT, "Abort"},
  {SIGBUS, "Bus error"},
  {SIGFPE, "Floating exception"},
  {SIGKILL, "Killed"},
  {SIGUSR1, "User signal 1"},
  {SIGSEGV, "Segmentation fault"},
  {SIGUSR2, "User signal 2"},
  {SIGPIPE, "Broken pipe"},
  {SIGALRM, "Alarm clock"},
  {SIGTERM, "Terminated"},
  {SIGSTKFLT, "Stack limit exceeded"},
  /* {SIGCHLD, ""}, */
  /* {SIGCONT, ""}, */
  {SIGSTOP, "Suspended (signal)"},
  {SIGTSTP, "Suspended"},
  {SIGTTIN, "Suspended (tty input)"},
  {SIGTTOU, "Suspended (tty output)"},
  /* {SIGURG, ""}, */
  {SIGXCPU, "Cputime limit exceeded"},
  {SIGXFSZ, "Filesize limit exceeded"},
  {SIGVTALRM, "Virtual time alarm"},
  {SIGPROF, "Profiling time alarm"},
  /* {SIGWINCH, ""}, */
  {SIGIO, "Pollable event occured"},
  {SIGPOLL, "Pollable event occured"},
  {SIGPWR, "Power failure"},
  {SIGSYS, "Bad system call"}
};

void	show_message(int sig)
{
  int	pos;

  pos = 0;
  while (pos < 28 && sig_rec[pos].signum != sig)
    pos++;
  if (pos < 28)
    fprintf(stderr, "%s\n", sig_rec[pos].msg);
}
