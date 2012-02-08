/*
** cat.h for cat_defines in /home/hervet_g//work/piscine/Jour_12/cat
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Oct 21 18:25:33 2010 geoffrey hervet
** Last update Thu Oct 21 20:37:11 2010 geoffrey hervet
*/

#ifndef	__CAT_H__
#define	__CAT_H__

#define	BUFFER_MAX_SIZE	30720
#define	EXE_NAME	cat
#define	OPEN_ERR_MSG	": No such file or directory\n"
#define	EACCES_MSG	": Permission denied\n"
#define	EISDIR_MSG	": Is a directory\n"
#define	UNK_ERR_MSG	": Unknow error\n"


void	buffer_errors(int err, int *buf, char *file);
void	my_put_err(char *file, char *msg);
int	cat(int ac, char **av);

#endif
