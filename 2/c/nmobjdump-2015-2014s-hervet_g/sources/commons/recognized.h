/*
** main.c for  in /home/hervet_g/mynm
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Mar  4 15:51:46 2012 geoffrey hervet
** Last update Sun Mar  4 15:51:48 2012 geoffrey hervet
*/

#ifndef RECOGNIZED_H_
# define RECOGNIZED_H_

typedef enum
{
  UNKNOWN,
  EXECUTABLE,
  RELOCATABLE,
  ARCHIVE,
  SHARED_LIB
} file_type;

file_type	recognized(const char const *file);

#endif /* !RECOGNIZED_H_ */
