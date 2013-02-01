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
#include <stdlib.h>
#include <string.h>

#include "flags.h"

unsigned int		get_flags(Elf64_Ehdr const * const elf)
{
  unsigned int		flags;
  Elf64_Shdr		*shdr;
  size_t		idx;

  flags = BFD_NO_FLAGS;
  shdr = (Elf64_Shdr *)(((char *)(elf) + elf->e_shoff));
  idx = elf->e_shnum;
  if (elf->e_type == ET_EXEC)
    flags |= EXEC_P;
  if (elf->e_type == ET_DYN)
    flags |= DYNAMIC;
  if (elf->e_phnum > 1)
    flags |= D_PAGED;
  while (idx-- > 0)
  {
    if (elf->e_type == ET_REL && shdr[idx].sh_type == SHT_RELA &&
        !(flags & EXEC_P))
      flags |= HAS_RELOC;
    if (shdr[idx].sh_type == SHT_SYMTAB)
      flags |= HAS_SYMS;
  }
  return (flags);
}

/*
** if (shdr[idx].sh_type == SHT_PROGBITS && !strcmp(".debug", &(((char*)(elf))
** + shdr[elf->e_shstrndx].sh_offset)[shdr[idx].sh_name]))
** flags |= HAS_DEBUG;
*/
