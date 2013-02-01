/*
** main.c for  in /home/hervet_g/mynm
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Mar  4 15:51:46 2012 geoffrey hervet
** Last update Sun Mar  4 15:51:48 2012 geoffrey hervet
*/

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

#include "print.h"
#include "recognized.h"
#include "get_file_name.h"

static void	do_work(void *file, int fd, char *filename, char **av)
{
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  char		*strtab;

  if (UNKNOWN != recognized(file))
  {
    elf = (Elf64_Ehdr *)file;
    shdr =  (Elf64_Shdr *)(((char *)(file) + elf->e_shoff));
    strtab = (((char*)(file)) + shdr[elf->e_shstrndx].sh_offset);
    fd = 0;
    print_1stline(elf, filename);
    while (++fd < elf->e_shnum)
      print_section(&shdr[fd],
          shdr[fd].sh_addr,
          &strtab[shdr[fd].sh_name],
          file + shdr[fd].sh_offset);
  }
  else
    fprintf(stderr, "%s: %s File format not recognized\n", av[0], filename);
}

int		main (int ac, char **av)
{
  void		*file;
  int		fd;
  char		*filename;

  while (NULL != (filename = get_file_name(ac, av)))
  {
    if (-1 == (fd = open(filename, O_RDONLY)))
      fprintf(stderr, "%s: '%s': No such file\n", filename, filename);
    else
    {
      file = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
      close(fd);
      if (file == MAP_FAILED)
        fprintf(stderr, "%s: '%s': Can't mmap the file\n", filename, filename);
      else
        do_work(file, fd, filename, av);
    }
  }
  return (0);
}

/*
 * .dynstr .rela.dyn .repla.plt
 */
