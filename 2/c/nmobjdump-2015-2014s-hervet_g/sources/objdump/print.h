/*
** main.c for  in /home/hervet_g/mynm
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Mar  4 15:51:46 2012 geoffrey hervet
** Last update Sun Mar  4 15:51:48 2012 geoffrey hervet
*/

#ifndef PRINT_H_
# define PRINT_H_

# include <elf.h>

# include "recognized.h"
# define BUFFER_LEN 	(32)

void		print_section(const Elf64_Shdr *shdr,
				const unsigned int virtual_addr,
                                const char *name,
                                const void *data);

void		print_1stline(Elf64_Ehdr const * const elf,
				const char * const name);

#endif /* PRINT_H_ */
