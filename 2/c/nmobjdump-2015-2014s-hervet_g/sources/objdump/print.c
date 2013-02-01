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
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"
#include "flags.h"

static t_flags		display_flags[] = {
  {HAS_RELOC, "HAS_RELOC"},
  {EXEC_P, "EXEC_P"},
  {HAS_LINENO, "HAS_LINENO"},
  {HAS_DEBUG, "HAS_DEBUG"},
  {HAS_SYMS, "HAS_SYMS"},
  {HAS_LOCALS, "HAS_LOCALS"},
  {DYNAMIC, "DYNAMIC"},
  {WP_TEXT, "WP_TEXT"},
  {D_PAGED, "D_PAGED"},
  {0, ""}
};

static void		print_content(const size_t idx,
					const void *data,
                                        const Elf64_Shdr *shdr,
                                        const char type)
{
  int		i;
  unsigned char	c;

  i = 0;
  while (i < 16)
  {
    if (!type && i && !(i % 4))
      printf(" ");
    if ((i + idx) < shdr->sh_size)
    {
      c = (unsigned char)(((char*)data)[idx + i]);
      if (0 == type)
        printf("%02x", c);
      else
        printf("%c", isprint(c) ? c : '.');
    }
    else
      printf( type ? " " : "  ");
    ++i;
  }
  if (type)
    printf("\n");
}

static unsigned int	size_t_hexa_len(unsigned int nbr)
{
  char          buffer[BUFFER_LEN + 1];
  size_t	len;

  snprintf(buffer, BUFFER_LEN, "%x", nbr);
  len = strlen(buffer);
  return (len < 4 ? 4 : len);
}

void		print_section(const Elf64_Shdr *shdr,
				const unsigned int virtual_addr,
                                const char *name,
                                const void *data)
{
  size_t	idx;

  if (!(!shdr->sh_size ||
      shdr->sh_type == SHT_NOBITS ||
      (shdr->sh_type == SHT_STRTAB && !(shdr->sh_flags & SHF_ALLOC)) ||
      (!(shdr->sh_flags & SHF_ALLOC) &&
       (shdr->sh_type == SHT_RELA || shdr->sh_type == SHT_REL)) ||
      shdr->sh_type == SHT_SYMTAB))
  {
    idx = 0;
    printf("Contents of section %s:\n", name);

    while (idx < shdr->sh_size)
    {
      printf(" %0*x ", size_t_hexa_len(shdr->sh_size),
         (unsigned int)(virtual_addr + idx));
      print_content(idx, data, shdr, 0);
      printf("  ");
      print_content(idx, data, shdr, 1);
      idx += 16;
    }
    fflush(stdout);
  }
}

static void	print_flags(unsigned int f)
{
  char		*comma;
  size_t	idx;

  comma = "";
  idx = 0;
  while (display_flags[idx].val != 0)
  {
    if (f & display_flags[idx].val)
    {
      printf("%s%s", comma, display_flags[idx].str);
      comma = ", ";
    }
    ++idx;
  }
  printf("\n");
}

void		print_1stline(Elf64_Ehdr const * const elf,
				const char * const name)
{
  unsigned int	flags;
  char		*comma;

  comma = "";
  flags = get_flags(elf);
  printf("\n%s:     file format elf64-x86-64\n", name);
  printf("architecture: i386:x86-64, flags 0x%08x:\n", flags);
  print_flags(flags);
  printf("start address 0x%016lx\n\n", (unsigned long)(elf->e_entry));
}
