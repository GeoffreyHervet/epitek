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

# define DEBUG 0
# define SHIFT(X, S, O) ((X)[!!ELF64_ST_BIND((S)->st_info) && O])

char		print(Elf64_Shdr *tab,
			Elf64_Shdr *shdr,
			void *addr,
			char *st,
			int k,
			char *filename);

#endif /* !PRINT_H_ */
