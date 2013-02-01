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
#include <sys/stat.h>
#include <sys/mman.h>

#include "print.h"
#include "get_file_name.h"
#include "recognized.h"

static char	*strerror[] = {
  "Format class not supported\n",
  "%s: %s: no symbols\n",
  "%s: %s: File format not recognized\n"
};

static int	is_symtab(Elf64_Shdr *section_header)
{
  return (section_header->sh_type == SHT_SYMTAB);
}

static char	*get_strtab(Elf64_Shdr *shdr, uint16_t idx, void *addr)
{
  while (idx--)
    if (shdr[idx].sh_type == SHT_STRTAB)
      return (addr + shdr[idx].sh_offset);
  return (NULL);
}

static int	do_work(void *file, char *filename, int ac)
{
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  char		*strtab;
  char		have_sym;
  int		idx;

  if (UNKNOWN == recognized(file))
    return (-2);
  elf = (Elf64_Ehdr *) file;
  if (elf->e_type != ELFCLASS64)
    return (0);
  shdr = (Elf64_Shdr *) (file + elf->e_shoff);
  strtab = get_strtab(shdr, elf->e_shnum, file);
  idx = 0;
  have_sym = 0;
  while (++idx < elf->e_shnum)
    if (is_symtab(&shdr[idx]))
      have_sym += print(shdr, &shdr[idx], file, strtab, ac > 2, filename);
  if (0 == have_sym)
    return (-1);
  return (1);
}

int		main(int ac, char **av)
{
  void		*file;
  int		fd;
  char		*filename;

  while (NULL != (filename = get_file_name(ac, av)))
  {
    if (-1 == (fd = open(filename, O_RDONLY)))
      fprintf(stderr, "%s: '%s': No such file\n", av[0], filename);
    else
    {
      file = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0);
      close(fd);
      if (file == MAP_FAILED)
        fprintf(stderr,
		"%s: Warning: '%s' is not an ordinary file\n", av[0], filename);
      else if (1 != (fd = do_work(file, filename, ac)))
        fprintf(stderr, strerror[-fd], av[0], filename);
    }
  }
  return (0);
}
