/*
** flags.h for  in /home/hervet_g/mynm
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Mar  4 15:54:31 2012 geoffrey hervet
** Last update Sun Mar  4 15:54:33 2012 geoffrey hervet
*/

#ifndef FLAGS_H_
# define FLAGS_H_

# include <elf.h>

# define BFD_NO_FLAGS    0x00
/* 
** BFD contains relocation entries.
*/
# define HAS_RELOC       0x01

/*
** BFD is directly executable.
*/
# define EXEC_P          0x02

/*
** BFD has line number information (basically used for F_LNNO in a COFF header).
*/
# define HAS_LINENO      0x04

/*
** BFD has debugging information.
*/
# define HAS_DEBUG       0x08

/*
** BFD has symbols.
*/
# define HAS_SYMS        0x10

/*
** BFD has local symbols (basically used for F_LSYMS in a COFF header).
*/
# define HAS_LOCALS      0x20

/*
** BFD is a dynamic object.
*/
# define DYNAMIC         0x40

/*
** Text section is write protected (if D_PAGED is not set, this is like an
** a.out NMAGIC file) (the linker sets this by default, but clears it for
** -r or -N).
*/
# define WP_TEXT         0x80

/*
** BFD is dynamically paged (this is like an a.out ZMAGIC file) (the
** linker sets this by default, but clears it for -r or -n or -N).
*/
# define D_PAGED         0x100

unsigned int		get_flags(Elf64_Ehdr const * const elf);

typedef struct
{
  unsigned int		val;
  const char		*str;
}			t_flags;

#endif /* FLAGS_H_ */
