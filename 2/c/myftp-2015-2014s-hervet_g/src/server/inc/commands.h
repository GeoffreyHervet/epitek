/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#ifndef COMMANDS_H_
# define COMMANDS_H_

# include "client.h"

# define CMD_FUNC_PROTO(n, c, cm) int cmd_##n(t_client *c, char *cm)

# include	"cmd_cd.h"
# include	"cmd_ls.h"
# include	"cmd_get.h"
# include	"cmd_put.h"
# include	"cmd_pwd.h"
# include	"cmd_quit.h"

#endif /* COMMANDS_H_ */
