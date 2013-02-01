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
#include <string.h>

#include "recognized.h"

/*
** renvoie le type du fichier si il est gere
**
** if (((Elf64_Ehdr *)(file))->e_type == ET_NONE) 
** printf("ET_MODE\n");
** if (((Elf64_Ehdr *)(file))->e_type == ET_CORE)
** printf("ET_CORE\n");
*/

file_type	recognized(const char const *file)
{
  if (strncmp(&file[1], "ELF", 3))
    return (UNKNOWN);
  if (((Elf64_Ehdr *)(file))->e_type == ET_NONE)
    return (UNKNOWN);
  if (((Elf64_Ehdr *)(file))->e_type == ET_EXEC)
    return (EXECUTABLE);
  if (((Elf64_Ehdr *)(file))->e_type == ET_REL)
    return (RELOCATABLE);
  if (((Elf64_Ehdr *)(file))->e_type == ET_DYN)
    return (SHARED_LIB);
  return (UNKNOWN);
}

