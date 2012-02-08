/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Mon Jan 01 00:00:00 2011 geoffrey hervet
*/

#ifndef __LITTLEHAND_H_
# define __LITTLEHAND_H_

#include	"Cagette.h"
#include	"Coconut.h"

class		LittleHand
{
  public:
    static void	sortCagette(Cagette &,Cagette &,Cagette &,Cagette &);
    static Cagette * const * organizeCoconut(Coconut const * const * coconuts_paquet);
};

#endif /* !__LITTLEHAND_H_ */
