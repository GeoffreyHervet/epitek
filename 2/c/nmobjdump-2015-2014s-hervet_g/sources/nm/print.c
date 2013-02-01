/*
** main.c for  in /home/hervet_g/mynm
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Mar  4 15:51:46 2012 geoffrey hervet
** Last update Sun Mar  4 15:51:48 2012 geoffrey hervet
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "print.h"

static int		cmpstringp(const void *p1, const void *p2)
{
  return (strcmp(* (char * const *) p1 + 19, * (char * const *) p2 + 19));
}

static char		get_sym_char(Elf64_Shdr *tab,
					Elf64_Sym *s)
{
  if (s->st_shndx == SHN_ABS)
    return (SHIFT("aA", s, 1));
  if (s->st_shndx == SHN_COMMON)
    return ('C');
  if (ELF64_ST_BIND(s->st_info) == STB_WEAK &&
      (!s->st_value || ELF64_ST_TYPE(s->st_info) ==  STT_FUNC))
    return (SHIFT("wW", s, s->st_value));
  if (ELF64_ST_BIND(s->st_info) == STB_WEAK)
    return (SHIFT("vV", s, s->st_value));
  if (tab[s->st_shndx].sh_type == SHT_NOBITS)
    return (SHIFT("bB", s, 1));
  if (s->st_shndx == SHN_UNDEF)
    return (SHIFT("uU", s, 1));
  if ((ELF64_ST_TYPE(s->st_info) == STT_OBJECT || ELF64_ST_TYPE(s->st_info) 
        == STT_NOTYPE) && tab[s->st_shndx].sh_type == SHT_PROGBITS &&
      ~tab[s->st_shndx].sh_flags & (SHF_WRITE))
    return (SHIFT("rR", s, 1));
  if (ELF64_ST_TYPE(s->st_info) == STT_FUNC)
    return (SHIFT("tT", s, 1));
  if ((ELF64_ST_TYPE(s->st_info) == STT_OBJECT &&
      ((tab[s->st_shndx].sh_flags & (SHF_WRITE | SHF_ALLOC) ||
       tab[s->st_shndx].sh_flags & SHF_TLS))) ||
      (tab[s->st_shndx].sh_type == SHT_PROGBITS))
    return (SHIFT("dD", s, 1));
  return ('?');
}

static char		display_addr(const char c)
{
  const char		*flags = "tTdDAarRbBWvV";

  while (*flags)
  {
    if (*flags == c)
      return (1);
    flags++;
  }
  return (0);
}

static char		display(char **disp,
				int size,
				char *s,
				int k)
{
  int			idx;

  idx = 0;
  if (!size)
    return (0);
  qsort(disp, size, sizeof(disp[1]), cmpstringp);
  if (k)
    printf("\n%s:\n", s);
  while (idx < size)
    printf("%s\n", disp[idx++]);
  return (1);
}

char			print(Elf64_Shdr *tab,
				Elf64_Shdr *shdr,
				void *addr,
				char *st,
				int k,
				char *s)
{
  Elf64_Sym	*sy;
  char 		**disp;
  size_t	idx;
  size_t	pos;
  char		c;

  idx = 0;
  pos = 0;
  if (!shdr->sh_entsize || NULL == (disp = malloc(sizeof(char *) *
          shdr->sh_size / shdr->sh_entsize)))
    return 0;
  while (idx < shdr->sh_size)
  {
    sy = (Elf64_Sym *)(addr + shdr->sh_offset + idx);
    if (sy->st_name && sy->st_info != STT_FILE)
    {
      if (display_addr(c = get_sym_char(tab, sy)))
        asprintf(&disp[pos++],
            "%016x %c %s", (unsigned int)sy->st_value, c, &st[sy->st_name]);
      else
        asprintf(&disp[pos++], "%16s %c %s", " ", c, &st[sy->st_name]);
    }
    idx += shdr->sh_entsize;
  }
  return (display(disp, pos, s, k));
}
