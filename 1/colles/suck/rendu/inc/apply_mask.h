/*
** apply_mask.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun May 08 14:20:12 2011 geoffrey hervet
** Last update Sun May  8 16:36:34 2011 vincent caggiari
*/

#ifndef __APPLY_MASK_H__
# define __APPLY_MASK_H__

unsigned char		apply_mask_row(unsigned short grid[9][9],
				       const unsigned char y,
				       const unsigned char x,
				       const unsigned short mask);

unsigned char		apply_mask_col(unsigned short grid[9][9],
				       const unsigned char y,
				       const unsigned char x,
				       const unsigned short mask);

#endif /* !__APPLY_MASK_H__ */
